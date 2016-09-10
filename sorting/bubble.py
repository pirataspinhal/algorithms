def bubblesort(A):
    for i in range(0, len(A)):
        for j in range(0, len(A)):
            if A[j] > A[j+1]:
                temp = A[j]
                A[j] = A[j+1]
                A[j+1] = temp

A = [4, 3, 2, 1]
bubblesort(A)
print(A)
