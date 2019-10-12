def cocktail_shaker_sort(alist):
    def swap(i, j):
        alist[i], alist[j] = alist[j], alist[i]
 
    upper = len(alist) - 1
    lower = 0
 
    no_swap = False
    while (not no_swap and upper - lower > 1):
        no_swap = True
        for j in range(lower, upper):
            if alist[j + 1] < alist[j]:
                swap(j + 1, j)
                no_swap = False
        upper = upper - 1
 
        for j in range(upper, lower, -1):
            if alist[j - 1] > alist[j]:
                swap(j - 1, j)
                no_swap = False
        lower = lower + 1
 
 
alist = input('Enter the list of numbers: ').split()
alist = [int(x) for x in alist]
cocktail_shaker_sort(alist)
print('Sorted list: ', end='')
print(alist)
