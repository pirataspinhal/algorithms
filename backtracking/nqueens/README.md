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


![Board size x Time to solve](http://i.imgur.com/82BNHJ3.png)

![Board size x Time to solve](http://i.imgur.com/b8yzF41.png)


We can observe that the number of attributions and the time needed to solve a board increases a lot with board size.
After the last case test, my computer kept running the program for almost an hour, still not producing the output for the 33 x 33 board. 

*Benchmark Machine:* 

> OS: Antergos

> Kernel: x86_64 Linux 4.7.6-1-ARCH

> Shell: zsh 5.2

> CPU: Intel Core i5-6200U CPU @ 2.7GHz

> GPU: Mesa DRI Intel(R) HD Graphics 520 (Skylake GT2)

> RAM: 2096MiB / 7854MiB

### Run Results

| board size | calls       | time        |
|------------|-------------|-------------|
| 0          | 0           | 0.000001s   |
| 1          | 1           | 0.000000s   |
| 4          | 26          | 0.000005s   |
| 5          | 15          | 0.000004s   |
| 6          | 171         | 0.000026s   |
| 7          | 42          | 0.000009s   |
| 8          | 876         | 0.000101s   |
| 9          | 333         | 0.000046s   |
| 10         | 975         | 0.000117s   |
| 11         | 517         | 0.000064s   |
| 12         | 3066        | 0.000374s   |
| 13         | 1365        | 0.000181s   |
| 14         | 26495       | 0.002876s   |
| 15         | 20280       | 0.002252s   |
| 16         | 160712      | 0.017150s   |
| 17         | 91222       | 0.010383s   |
| 18         | 743229      | 0.084488s   |
| 19         | 48184       | 0.005725s   |
| 20         | 3992510     | 0.490726s   |
| 21         | 179592      | 0.023457s   |
| 22         | 38217905    | 5.092550s   |
| 23         | 584591      | 0.081210s   |
| 24         | 9878316     | 1.410959s   |
| 25         | 1216775     | 0.188140s   |
| 26         | 10339849    | 1.599553s   |
| 27         | 12263400    | 1.987257s   |
| 28         | 84175966    | 14.078644s  |
| 29         | 44434525    | 7.684626s   |
| 30         | 1692888135  | 298.843353s |
| 31         | 408773285   | 74.617912s  |
| 32         | -1495242192 | 526.441956s |
| 33         | 323601164   | 893.228821s |

Number of calls has exceed *long int* on board 32 x 32.

## Algorithm Complexity

Backtracking algorithms have a worst case complexity of O(d^n).
* d = domain (possible values for a variable)
* n = number of variables

For the n-queens problem, we have a domain of 2 (0 or 1) and n² variables.

Consider the 34 * 34 board.

![Board size x Time to solve](https://www5a.wolframalpha.com/Calculate/MSP/MSP3991f5h01dgcf77819100002275f3a04ecb8865?MSPStoreType=image/gif&s=37)

How about it? Without heuristics and a very good implementation, it's insane how much this problem grows.


## Memory

The program will allocate a structure named BOARD, that contains a double int pointer (matrix) and it's size.
After it attempts to solve the board, the heap memory allocated is destroyed.

Tested with **Valgrind**, no memory leaks.

## Flowchart

To better understand the algorithm, here's a handy flowchart of the N-Queens problem without using heuristics:


![n-queens problem without heuristics](https://s17.postimg.org/nm73d06pb/nqueens.png)
 

>*Keep in mind this is not following proper flowchart rules, it was drawn just for quick reference before an exam*
