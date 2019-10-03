// NodeJS input setup
const input = require('readline').createInterface({
      input: process.stdin,
      output: process.stdout
})

input.question("Enter a Space Separated list of numbers: ", (listString) => {
      list = listString.split(' ').map(element => parseFloat(element))

      input.question("Enter Search element: ", (searchElement) => {
            // Reads input and calls the main function
            var position = linearSearch(list, parseFloat(searchElement))

            if (position === -1) {
                  console.log(`Search Element ${searchElement} not found in the List`)
            } else {
                  console.log(`Search Element found!\nAt index: ${position} in the Array`)
            }

            input.close()
      })
})

// Main function
function linearSearch(list, searchElement) {
      /*
            Args:
            `list`: A list of numbers (floats)
            `searchElement`: The search element as a number (float)

            Returns:
            `position`: Index of the first element that is equal to `searchElement`
      */

      var found = false
      var position = -1
      list.forEach((element, i) => {
            if (element === searchElement && !found) {
                  // Element found! Return index of the element found.
                  position = i
                  found = true
            }
      })

      // if element is not found, `position` will still be -1, else we return the index of the element
      return position
}