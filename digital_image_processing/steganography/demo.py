import numpy as np
import imageio
import seaborn as sns
from matplotlib import pyplot as plt
from matplotlib import animation
from subprocess import call


# load images
print("Loading images...")
original = np.asarray(imageio.imread("images/forest.png", as_gray=False, pilmode="RGB"))
secret = np.asarray(imageio.imread("images/doggo.png", as_gray=False, pilmode="RGB"))

# copy original image for merging
merged = np.copy(original)

# plotting parameters
dpi = 80.0
margin = 0.05
xpixels, ypixels = original.shape[0], original.shape[1]
figsize = (1 + margin) * ypixels / dpi, (1 + margin) * xpixels / dpi
fig = plt.figure(figsize=figsize, dpi=dpi)
ax = fig.add_axes([margin, margin, 1 - 2*margin, 1 - 2*margin])

# merge images
print("Merging images...")

for i in range(original.shape[0]):
    for j in range(original.shape[1]):
        # get binary representation of pixel (original)
        # we're only interested in RGB
        r, g, b = original[i][j]
        rgb1 = ('{0:08b}'.format(r), '{0:08b}'.format(g), '{0:08b}'.format(b))
        # get binary representation of pixel (secret)
        r, g, b = secret[i][j]
        rgb2 = ('{0:08b}'.format(r), '{0:08b}'.format(g), '{0:08b}'.format(b))
        # now, we merge them
        # rg1 and rgb2 are string tuples, let's break them
        r1, g1, b1 = rgb1
        r2, g2, b2 = rgb2
        # now we can add the most significant bits of each one
        rgb = (r1[:4] + r2[:4], g1[:4] + g2[:4], b1[:4] + b2[:4])
        # we now have the new pixel for the output image (binary)
        # let's convert it back to int tuple (R,G,B)
        r, g, b = rgb
        merged[i][j] = [int(r, 2), int(g, 2), int(b, 2)]

# save merged image
print("Plotting merged image...")
plt.axis('off')
ax.imshow(merged, interpolation='none')
plt.savefig("plots/merged.png", dpi=100)
plt.clf()

# extraction
rmse = []
compressed = []

# apply different levels of compression
print("Compressing merged image...")
compressed.append(np.copy(merged)) # original image
for i in range(10, 110, 10):
    # compress and store (i = % of quality for jpg compression)
    call("convert -resize 800x800 -quality "+str(i)+"% plots/merged.png plots/compressed_" + str(i) + ".jpg", shell=True)
    compressed.append(np.asarray(imageio.imread("plots/compressed_" + str(i) + ".jpg", as_gray=False, pilmode="RGB")))

# unmerge images
for i in range(0, 110, 10):
    print("Extracting image - Compression at {}%...".format(i))
    merged = np.copy(compressed[int((i/10))])
    unmerged = np.copy(compressed[int((i/10))])

    for x in range(merged.shape[0]):
        for y in range(merged.shape[1]):
            # get RGB
            r, g, b = merged[x][y]
            r, g, b = ('{0:08b}'.format(r), '{0:08b}'.format(g), '{0:08b}'.format(b))
            # extract last 4 bits (assuming we know it's 4 bits)
            # concatenate remaining bits as 0
            rgb = (r[4:] + "0000", g[4:] + "0000", b[4:] + "0000")
            # convert it back to int
            r, g, b = rgb
            unmerged[x][y] = [int(r, 2), int(g, 2), int(b, 2)]

    # save extracted image
    print("Plotting extracted image...")
    plt.axis('off')
    plt.imshow(unmerged, interpolation='none')
    plt.savefig("plots/extracted_" + str(int(i)) + ".png", dpi=100)
    plt.clf()

    # calculate RMSE (extracted vs original secret)
    print("Calculating RMSE...")
    error = ((unmerged - secret) ** 2)
    error = np.sum(error)
    error *= 1 / (merged.shape[0] * merged.shape[1])
    error = np.sqrt(error)
    rmse.append(error)


print("Plotting RMSE vs Compression")
sns.set()
plt.plot(range(0, 110, 10), rmse)
plt.xlabel('RMSE')
plt.ylabel('Quality of JPEG compression (%)')
plt.title('RMSE (extracted vs original secret) x JPEG compression quality')
plt.savefig("plots/rmse.png", dpi=100)
plt.clf()

print("Finished")
