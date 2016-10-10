# The Stable Marriage Problem

Numberphile has a great video explanation of the problem here:

[![Stable Marriage Problem - Numberphile](http://img.youtube.com/vi/Qcv1IqHWAzg/0.jpg)](https://www.youtube.com/watch?v=Qcv1IqHWAzg "Stable Marriage Problem - Numberphile")

The algorithm I studied during CS was the Gale-Shapley algorithm.
It has the following features:
* It guarantees that everyone will be married in stable conditions at the end
* It is optimal for the group that is proposing
* It is bad for the group that is receiving the proposals
* Even though that group can change pairs during the algorithm!
* It runs at O(n²) at the worst case scenario (all men proposes to all women)

Here's a very handy flowchart of how it works:

![GaleShapley flowchart](http://i.imgur.com/I6QIOh9.png)
