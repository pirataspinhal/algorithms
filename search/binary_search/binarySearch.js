// NodeJS input setup
const input = require('readline').createInterface({
      input: process.stdin,
      output: process.stdout
})

input.question("Enter a Sorted, Space Separated list of numbers: ", (listString) => {
      list = listString.split(' ').map(element => parseFloat(element))

      input.question("Enter Search element: ", (searchElement) => {
            // Reads input and calls the main function
            binarySearch(list, parseFloat(searchElement))

            input.close()
      })
})

// Main function
function binarySearch(list, searchElement) {
      /*
            Args:
            `list`: A sorted list of numbers (floats)
            `searchElement`: The search element as a number (float)
      */

      // left and right are pointers to the left and right most indices that the element might be present within, since the array is sorted.
      var left = 0
      var right = list.length - 1

      while (left <= right) {
            // mid is the pointer that points to the mid point between left and right
            var mid = parseInt((left + right) / 2)

            if (list[mid] == searchElement) {
                  console.log(`Search Element found!\nAt index: ${mid} in the Array`)
                  return
            }
            else {
                  if (list[mid] < searchElement) {
                        // searchElement is present after mid
                        left = mid + 1
                  } else {
                        // searchElement is present before mid
                        right = mid - 1
                  }
            }
      }

      // if the function didn't exit at line #22 and the execution reaches line #30, searchElement is not present in the array
      console.log(`Search Element ${searchElement} not found in the List`)
}