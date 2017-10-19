function quickSort(origArray: any[]): any[] {
	if (origArray.length <= 1) {
		return origArray;
	} else {
		let left: any[] = [];
		let right: any[] = [];
		let newArray: any[] = [];
		let pivot: any = origArray.pop();
		for (let i: number = 0; i < origArray.length; i++) {
			if (origArray[i] <= pivot) {
				left.push(origArray[i]);
			} else {
				right.push(origArray[i]);
			}
		}
		return newArray.concat(quickSort(left), pivot, quickSort(right));
	}
}
