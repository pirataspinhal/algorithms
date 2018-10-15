// This represents a first in last out stack interface for CS249.
public interface IStack<E> {

    ////////////////////////////////////////////////////////////////////////////
    // Public interface

    // Adds an element onto the stack.
    void push(E e);

    // Removes and returns the most recent element added to the stack.
    // Throws a NoSuchElementException if the stack is empty.
    E pop();

    // Returns the item on the top of the stack without removing it.
    // Throws a NoSuchElementException if the stack is empty.
    E peek();

    // Returns the number of elements in this stack.
    int size();

    // Returns this stack in string form, surrounded by [] brackets and with
    // each items separated by a comma and space.  For example:
    // [First, Second, Third, Fourth]
    // where 'First' is the next item that would be returned by pop()
    String toString();

    ////////////////////////////////////////////////////////////////////////////
    // Private interface
    //
    // Normally, everything past this point would be private.  For the sake of
    // testing in CS249, however, all of these must be provided as public.

    // Returns the linked list which this stack is composed over.
    ILinkedList getInternalLinkedList();

}
