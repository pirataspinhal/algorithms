// This represents a first in first out queue interface for CS249.
public interface IQueue<E> {

    ////////////////////////////////////////////////////////////////////////////
    // Public interface

    // Adds an element onto the queue.
    void push(E e);

    // Removes and returns the oldest element in the queue.
    // Throws a NoSuchElementException if the queue is empty.
    E pop();

    // Returns the oldest item in the queue without removing it.
    // Throws a NoSuchElementException if the queue is empty.
    E peek();

    // Returns the number of elements in this queue.
    int size();

    // Returns this queue in string form, surrounded by [] brackets and with
    // each items separated by a comma and space.  For example:
    // [First, Second, Third, Fourth]
    // where 'First' is the next item that would be returned by pop()
    String toString();

    ////////////////////////////////////////////////////////////////////////////
    // Private interface
    //
    // Normally, everything past this point would be private.  For the sake of
    // testing in CS249, however, all of these must be provided as public.

    // Returns the linked list which this queue is composed over.
    ILinkedList getInternalLinkedList();

}
