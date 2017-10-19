let originalArray = [4, 5, 1, 8, 3, 49, 10, 23, 81, 23];

document.getElementById('original').appendChild(
    document.createTextNode(
        'Original array: ' + originalArray.toString())
);

document.getElementById('sorted').appendChild(
    document.createTextNode(
        'Sorted array: ' + quickSort(originalArray).toString())
);
