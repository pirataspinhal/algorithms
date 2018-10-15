import java.util.NoSuchElementException;

public class Queue<E> implements IQueue<E>{
	LinkedList list = new LinkedList();							// Our underlying structure for our queue
	
	public Queue(){												// Instantiates our queue
		this.list = list;
	}
	
	// Adds the first element into the queue
	public void push(E e){										
		list.add(e, (list.size()));								// Adds the element at the end of the queue
	}
	
	
	// Removes and returns the oldest element in the queue.
	// NoSuchElementException is thrown if empty.
	public E pop(){
		if(list.size() == 0 || list.get(0) == null){			// If index is out of bounds.
			try{
				list.remove(0);									// Throws IndeOutOfBoundsException
			}
			catch (IndexOutOfBoundsException ex){				// Handle the exceptions
				throw new NoSuchElementException();
			}
		}
		return (E) list.remove(0);								// Returns removed head item
	}
	
	
	// Returns the oldest item in queue.
	// NoSuchElementException is thrown if empty.
	public E peek(){
		if((list.size()) == 0){									// If index is out of bounds
			try{
				list.get(0);;									// Throws IndeOutOfBoundsException
			}
			catch (IndexOutOfBoundsException ex){				// Handle the exceptions
				throw new NoSuchElementException();
			}
		}
		return (E) list.get(0);									// Returns the head of the list
	}
	
	
	// Returns the number of elements in the queue
	public int size(){
		return list.size();										
	}
	
	
	// Returns the queue in string form, surrounded by [] brackets and with
    // each items separated by a comma and space.  For example:
    // [First, Second, Third, Fourth]
    // where 'First' is the next item that would be returned by pop()
	public String toString(){
		return list.toString();									// Returns the queue as a string
	}
	
	
	public ILinkedList getInternalLinkedList(){					// Returns underlying LinkedList
		return list;
	}
}