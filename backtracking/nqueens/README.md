# The N-Queens 女王 Problem

The n-queens puzzle is the problem of placing n chess queens on an ｎ ｘ ｎ chessboard so that no two queens threaten each other. 

Thus, a solution requires that no two queens share the same **row, column, or diagonal**.

Let's discuss a simple solution to the problem, without implementing any heuristics for optimization, only bruteforce 
backtracking.

## Recursion

Have we reached the end of the board (last line)?
* **YES**: Return *TRUE*
* **NO**: Continue

Iterate through the current row.

Place a queen at current position [row][i].

Is this queen possible? (See [**Validation**](https://github.com/felipecustodio/algorithms/new/master/backtracking/nqueens#validation))

  * **YES**: Calls recursion to next row.
  
  * **NO**: Remove queen and continue loop.
 
If the loop has ended and we couldn't place any queen, it means the previous queen is blocking us.

We backtrack to her and continue the process.
 
## Validation

If there's a queen in:
* Same row
* Same column
* Same diagonals

The function will return *FALSE*.

## Performance

The program asks for a maximum size of board. It'll try to solve every board with increasing size until n.

It doesn't have any restrictions, so it could take hours for a big test case. Use it carefully.


![Board size x Time to solve](http://i.imgur.com/1l8stbh.png)

## Memory

The program will allocate a structure named BOARD, that contains a double int pointer (matrix) and it's size.
After it attempts to solve the board, the heap memory allocated is destroyed.

Tested with Valgrind, no memory leaks.

## Flowchart

To better understand the algorithm, here's a handy flowchart of the N-Queens problem without using heuristics:


![n-queens problem without heuristics](https://s17.postimg.org/nm73d06pb/nqueens.png)
 
>*Keep in mind this is not following proper flowchart rules, it was drawn just for quick reference before an exam*
