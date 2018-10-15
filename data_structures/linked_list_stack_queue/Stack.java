import java.util.NoSuchElementException;

public class Stack<E> implements IStack<E>{
	LinkedList list = new LinkedList();
	
	
	public Stack(){										// Instantiates our stack
		this.list = list;									
		
	}
	
	
	 // Adds an element onto the stack.
	public void push(E e){
		list.add(e, 0);									// Adds the element to the top of the stack
	}
	
	
	// Removes and returns the most recent element added to the stack.
    // Throws a NoSuchElementException if the stack is empty.
	public E pop(){
		if(list.size() == 0) {							// If index is out of bounds.
			//try {
			//	list.remove(0);							// Throws an error
			//}
			//catch (IndexOutOfBoundsException ex){		// Catches the error
				throw new NoSuchElementException();		// Throws the NoSuchElementException
			//}
		}
		return (E) list.remove(0);						// Otherwise, returns the top removed item	
	}
	
	
	 // Returns the item on the top of the stack without removing it.
    // Throws a NoSuchElementException if the stack is empty.
	public E peek(){
		if((list.size()) == 0){							// If index is out of bounds
			try {
				list.get(0);							// Throws an error
			}
			catch (IndexOutOfBoundsException ex){		// Catches the error
				throw new NoSuchElementException();		// Throws the NoSuchElementException
			}
		}
		return (E) list.get(0);							// Otherwise, returns the top item	
	}
	
	
	// Returns the number of elements in this stack.
	public int size(){
		return list.size();								// Returns the stack size
	}
	
	
	public String toString(){
		return list.toString();							// Returns the string form of stack
	}
	
	
	public ILinkedList getInternalLinkedList(){
		return list;									// Returns the underlying linked list
	}
}