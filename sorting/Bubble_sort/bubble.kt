fun bubbleSort(myList: MutableList<Int>) {
    for (pass in 0 until (myList.size - 1)) {
        for (currentPosition in 0 until (myList.size - pass - 1)) {
            if (myList[currentPosition] > myList[currentPosition + 1]) {
                swap(myList, currentPosition, currentPosition + 1)
            }
        }
    }
}

fun swap(myList: MutableList<Int>, indexA: Int, indexB: Int){
    val aux = myList[indexA]
    myList[indexA] = myList[indexB]
    myList[indexB] = aux
}

fun main() {
    val myList = mutableListOf(11, 2, 3, 44, 8, 3, 9)
    bubbleSort(myList)
    print(myList)
}