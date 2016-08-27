def insertionSort(list):
    
    for i in range(1, len(list)):
        key = list[i]
        j = i - 1
        while j > -1 and list[j] > key:
            list[j + 1] = list[j]
            j = j - 1
        list[j + 1] = key

list = [4, 3, 2, 1]
insertionSort(list)
print(list)
