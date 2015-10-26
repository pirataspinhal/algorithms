# Queue

A queue is a data structure to store elements in a FIFO way (First In, First Out).
Items are always added at the end of the queue and removed at the beginning (front).

# Implementation

This implementation has a memory problem. We always reallocate more memory for new items,
when we could be using nodes and a circular list to simply free a node that is removed from the list.
But this implementation works, it only needs a few fine tunings. 

# Enjoy!