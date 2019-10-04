function bubbleSort(items) {
    var length = items.length;
    for (var i = 0; i < length; i++) { //Number of passes
      for (var j = 0; j < (length - i - 1); j++) { //Notice that j < (length - i)
        //Compare the adjacent positions
        if (items[j] > items[j + 1]) {
          //Swap the numbers
          var tmp = items[j]; //Temporary variable to hold the current number
          items[j] = items[j + 1]; //Replace current number with adjacent number
          items[j + 1] = tmp; //Replace adjacent number with current number
        }
      }
    }
  }