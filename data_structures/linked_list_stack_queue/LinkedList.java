public class LinkedList<E> implements ILinkedList<E>{
	
	Node head;																// Creates our head, tail and count variables to be implemented
	Node tail;																// through all methods.
	int list_count;
	
	public LinkedList(){													// Instantiates our Linked List
		head = null;
		tail = null;
		list_count = 0;
	}
	
	// Adds the item at a given index.
	public void add(E e, int index){
		if(index < 0 || index > size()) {									// If index is out of bounds.
	        throw new IndexOutOfBoundsException();							// Throws IndexOutOfBoundsException
		}
		else{																// Otherwise;
			Node newnode = new Node();										// Creates our node
			Node current = head;											// Sets the current as the head
			newnode.data = e;												// Sets the given data to our new node
			if( head == null){												// If there are no nodes in the linked list.
				head = newnode;												// The new node is the head
				tail = newnode;												// The new node is the tail
				list_count++;												// Increase the linked list count
			}
			else{															// If there is at least 1 node
				for(int i = 0; i<=size(); i++){								// Starts looping through all item in the linked list
					if(index == 0){											// If the index is in the beginning.
						current.previous = newnode;							// Sets the old head's previous to the new node.
						newnode.next = current;								// Sets the new nodes next to the old node.
						head = newnode;										// Sets the head as the new node.
						list_count++;										// increases the list count.
						break;												// breaks from loop
					}
					else if(i == index){									// If the index is being inserted somewhere in the middle.
						newnode.next = current;								// sets the newnode's next.
						newnode.previous = current.previous;				// Sets the newnode's previous.
						current.previous = newnode;							// Sets the left node's next, to the new node.
						(newnode.previous).next = newnode;					// Sets the old node' previous to the new node.
						list_count++;										// Increases list count.
						break;												// breaks from loop
					}
					else if (index == size()){								// If the index is being inserted last.
						tail.next = newnode;								// The old tail's next is the new node.
						newnode.previous = tail;							// the new node's previous is the old tail.
						tail = newnode;										// The new node is the tail.
						list_count++;										// Increases list count.
						break;												// breaks from loop
					}
					else{													// Continues searching if not found.
						current = current.next;
					}
				}									
			}
		}
	}
	
	// Returns the item at the given index.
	public E get(int index){
		if(index < 0 || index >= size() || size() == 0){					//If the index out of bounds.
	        throw new IndexOutOfBoundsException();							// Throw exception.
		}
		E item = null;														// defaults our item variable we're getting to null
		int i = 0;															// our index variable
		Node current = head;												// Starting our loop at the head.
		if(index == 0){														// If we are looking for the head
			item = (E) head.data;											// item is the head's data
		}
		else if(index == (size()-1)){										// If we are looking for the tail
			item = (E) tail.data;											// item is the tails data
		}
		else{
			while(current != null){											// If its somewhere in between, loop through all
				if(i == index){												// If we found the index.
					item = (E) current.data;								// our item is the index's data
					break;													// break the loop.
				}
				else{														// Otherwise, continue searching.
					current = current.next;									// moves on to the next node
					i++;													// increase our current index count
				}
			}
		}
			return item;
	}

	
	// Returns the first occurrence of the given item.
	// Else returns -1 if not present.
	public int indexOf(E e){
		Node current = head;												// Starting at the head.
		int i = 0;
		while(current != null){												// While we are still in the Linked List
			if(current.data == e){											// If the current item is the index
				return i;													
			}
			i++;
			current = current.next;											// Otherwise, keep searching.
		}
		return -1;															// If its not present, returns -1
	}
	
	// Removes the item at the given index.
	public E remove(int index){
		Node current = head;												// Sets the current node being evaluated.
		E item = null;
		if(index < 0 || index >= size() || size() == 0){					// If the index is out of bounds.
	        throw new IndexOutOfBoundsException();
	        }
			
			else{
				if(size() == 1){											// If the size is 1
					item = (E) current.data;								// item is the current data
					head = null;											// head is now null
					tail = null;											// tail is now null
					list_count--;											// list count is reduced
				}
				else if(index == 0){										//If we are removing the first item.
					item = (E) current.data;								// Creates return item
					if(size()>=2){									
						head = current.next;								// Changes the new head.
						(current.next).previous = null;						// Sets the new head's previous as null.
					}
					current = null;											// Removes the current
					list_count--;											// Decreases list count
				}
				else if(index == (size()-1)){								// If we are removing the last item.
					item = (E) current.data;								// Creates return item
					tail = current.previous;								// Changes the new tail.
					(current.previous).next = null;							// Sets the new tail's previous as null.
					list_count--;											// Decreases list count
				}
				else{														// If the index is somewhere in between.
					int i = 0;												// Loop through.
					while(current != null){
						if(i == index){										// If we found the index in the middle.
							item = (E) current.data;						// Creates return item
							(current.previous).next = current.next;			// Sets the next to the new next
							(current.next).previous = current.previous;		// Seat the previous to the new previous
							list_count--;									// Decreases list count
							break;											// breaks from loop
							}
						current = current.next;								// Continues searching otherwise
						i++;												// increases index
					}
				}
		}
		return item;														// Returns the removed item
	}
	
	public void set(int index, E element){									// Replaces the item at the given index with the 
																			// new given element.
		if(index < 0 || index >= size() || size() == 0){					// If the index is out of bounds.
	        throw new IndexOutOfBoundsException();
		}
		Node current = head;												// Starting at the beginning.
		int i = 0;
		while(current != null){
			if(i == index){													// If we find the value;
				current.data = element;										// data is updated.
				break;
			}
			else{															// Otherwise, keep searching.
				current = current.next;
			}
			i++;
		}
	}
	
	public int size(){														// Returns the number of items in the list.
		return list_count;
	}
	
	//[word, apple]
	
	public String toString(){												// Returns the list in string form.
		String str;
		if(head == null){													// If the stack is empty
	        str = "[]";														// return empty brackets
		}
		else{																// If the stack has items in it.
			str = "[" + head.data;											// Starts the opening bracket and adds first item.
			Node current = head.next;										// Sets the next current to the next node.
			int i = 1;														// For index 1
			while(current != null){											// While there is a next node
				if(size() == 1){											// If there is only one item, break
					break;										
				}
				else if(current == tail){									// If we are at the end of the stack
					if(current.previous == head){							// If the size is 2.
						str = str + ", " + tail.data;						// Ensures we have the comma separating
					}
					else{
					str = str + tail.data;									// Adds the last item to the list		
					}
				}
				else{														// If we are somewhere in between the tail and head
					if(i == 1){
						str = str + ", ";
					}
					str = str + current.data + ", ";
				}
				current = current.next;										// Moves on to next node
				i++;														// Increments index
			}
			str= str+"]";													// Closes the string
		}
		return str;															// Returns the final string
	}
	
	public class Node<E> implements INode<E>{
		E data;																// Creates data variable of type E
		Node next;															// Creates the next node variable
		Node previous;														// Creates the previous node variable
		
		public Node(){														// Creates our node object
			next = null;													// Defaults all variables to null.
			previous = null;
			data = null;
		}
		
		public INode previous(){											// Returns the previous node or null 
			return previous;												// if there's only 1 node.
		}
		
		public INode next(){												// Returns the next node or, 
			return next;													// null if its the last node.
		}
		
		public E data(){													// Returns the element contained
			return data;													// in this node.
		}
	}
	
	
	public INode getFirstNode(){											// Returns the first node in the Linked List.
		return head;										
	}
	
	
	public INode getLastNode(){												// Returns the last node in the Linked list.
		return tail;
	}
}