/*
    MERGE SORT:-

    Time Complexity: Θ(nLogn)

    Auxiliary Space: O(n)

    Algorithmic Paradigm: Divide and Conquer
*/

function merge (left, right) {
    let result = [], l = 0, r = 0;
  
    while (l < left.length && r < right.length) {
        if (left[l] < right[r]) {
            result.push(left[l]);
            l++;
        } else {
            result.push(right[r]);
            r++;
        }
    }
    return result.concat(left.slice(l)).concat(right.slice(r));
}

function mergeSort (arr) {
    if (arr.length <= 1) {
        return arr;
    }
    const middle = Math.floor(arr.length / 2);
    const left = arr.slice(0, middle);
    const right = arr.slice(middle);

    return merge(
        mergeSort(left), mergeSort(right)
    );
}

console.log(mergeSort([4,5,6,1,2,3]));
