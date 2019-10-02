print("--Binary Search--")

# Read input as a space separated list of numbers, elements can be of any data type
array = list(map(float, input("Enter a Sorted Space-Separated list of Numbers: ").split(', ')))

# Read the element to be searched
search_element = float(input("Enter the Search Element: "))


# Main function
def binary_search(array: list, search_element):
    # left and right are pointers to the left and right most indices that the element might be present within, since the array is sorted.
    left = 0
    right = len(array) - 1

    while left <= right:
        # mid is the pointer that points to the mid point between left and right
        mid = (left + right) // 2

        if array[mid] == search_element:
            print(f"Search Element found!\nAt index: {mid} in the Array")
            return
        else:
            if array[mid] < search_element:
                # search_element is present after mid
                left = mid + 1
            else:
                # search_element is present before mid
                right = mid - 1

    # if the function didn't exit at line #22 and the execution reaches line #30, search_element is not present in the array
    print(f"Search Element {search_element} not found in the List")


# call the function
binary_search(array, search_element)
