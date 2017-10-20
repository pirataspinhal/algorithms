function quickSort(origArray) {
    if (origArray.length <= 1) {
        return origArray;
    }
    else {
        var left = [];
        var right = [];
        var newArray = [];
        var pivot = origArray.pop();
        for (var i = 0; i < origArray.length; i++) {
            if (origArray[i] <= pivot) {
                left.push(origArray[i]);
            }
            else {
                right.push(origArray[i]);
            }
        }
        return newArray.concat(quickSort(left), pivot, quickSort(right));
    }
}
//# sourceMappingURL=quickSort.js.map