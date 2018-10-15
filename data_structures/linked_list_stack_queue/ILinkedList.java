// This represents a simplified list interface to be implemented as a doubly
// linked list for CS249.
public interface ILinkedList<E> {

    ////////////////////////////////////////////////////////////////////////////
    // Public interface

    // Appends the specified element at the given index.  The index of all
    // elements at index or later is increased.
    // Throws an IndexOutOfBoundsException when index is out of range.
    void add(E e, int index);

    // Returns the element at the specified position in this list.
    // Throws an IndexOutOfBoundsException when index is out of range.
    E get(int index);

    // Returns the index of the first occurrence of the specified element in
    // this list, or -1 if this list does not contain the element.
    int indexOf(E e);

    // Removes the element at the specified position in this list.
    // Throws an IndexOutOfBoundsException when index is out of range.
    E remove(int index);

    // Replaces the element at the specified position in this list with the
    // specified element.
    // Throws an IndexOutOfBoundsException when index is out of range.
    void set(int index, E element);

    // Returns the number of elements in this list.
    int size();

    // Returns this list in string form, surrounded by [] brackets and with each
    // items separated by a comma and space.  For example:
    // [First, Second, Third, Fourth]
    String toString();

    ////////////////////////////////////////////////////////////////////////////
    // Private interface
    //
    // Normally, everything past this point would be private.  For the sake of
    // testing in CS249, however, all of these must be provided as public.

    // You must use an inner class in your implementation to implement this
    // interface for the nodes.
    public interface INode<E> {

        ////////////////////////////////////////////////////////////////////////////
        // Public interface

        // Returns the previouos node, or null if this is the first node.
        INode previous();

        // Returns the next node, or null if this is the last node.
        INode next();

        // Returns the element contained in this node
        E data();

    }

    // Returns the first node object in the linked list, which should link to
    // all of the linked nodes through next links.
    INode getFirstNode();

    // Returns the last node object in the linked list, which should link to all
    // of the linked nodes through previous links.
    INode getLastNode();


}
