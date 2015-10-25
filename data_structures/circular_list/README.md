# Linked Circular List

The linked circular list is made of nodes that contains two pointers:
    @ NODE *previous
    @ NODE *next

# How does it work?

By using a header, we can always know where the list 'ends' or 'starts' when
performing a search or sort. Circular lists are extremely easy to use, because
you don't have to handle a lot of exceptions that linear lists have, like inserting
a node at the beggining or at the end. In a circular list, all you do is change the previous
and next pointers of the nodes around a position. If a list is empty, it only has a header, which
both pointers are pointing to itself.

This is how the linked circular list in this program looks like:

<-> NODE_A <-> NODE_B <-> HEADER <-> NODE_A <-> NODE_B <->

Enjoy!