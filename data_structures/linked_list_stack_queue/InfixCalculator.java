public class InfixCalculator implements IInfixCalculator{
	Stack stack = new Stack();										// Creates our operator stack
	Queue queue = new Queue();										// Creates our equation queue
	int openparentheses = 0;										// Our open Parenthesis tracker
	int closeparentheses = 0;										// Our close Parenthesis tracker
	PostfixCalculator postfix = new PostfixCalculator();			// Creates our Postfix object
	String str = "";
	
	// Process a single operator.  You must support the operators
    // '+', '-', '*', '/', '(' and ')'.
    // Throw an InvalidArgumentException if an invalid opeator is provided or
    // if a closed parenthesis is provided without an opening paranthesis.
    public void inputOperator(char operator){
    	String sign_str = "+-*/()";									// Our string of operators we are using
    	if(sign_str.indexOf(operator) == -1 ){						// If the given character is not an operator
			throw new IllegalArgumentException();					// Throw IllegalArgumentException
		}
    	else if(operator == ')' && openparentheses%2 != 1){			// if there is not an open parentheses already
    		throw new IllegalArgumentException();					// Throws exception
    	}
    	else{														// Otherwise
    		if(operator == '('){									// If the operator is an open parentheses
    			openparentheses++;									// We increase the parentheses count
    		}
    	stack.push(operator);										// Push the remaining value on the stack

		}
	}

    // Process a single numerical operand.
    public void inputOperand(int operand){
    	queue.push(operand);										// Pushes the integer on the queue
    }

    // Closes the conversion, resolving any left over operators.
    // This leaves the operator stack empty and the queue with a
    // complete postfix equasion.
    public void endEquation(){
    	queue.push(stack.pop()+"");									// Adds the item to queue
	 
    }

    // Enter a single token into the calculator representing either a single
    // number or opeartor.  Valid examples are '27', '-2', ')', or '/'.
    // Throw an InvalidArgumentException if the token is not valid, or if a
    // closed parenthesis is provided without an opening paranthesis.
    // The return value should give the remaining operands on the stack after
    // the token is applied.
    // Hint: use inputOperator() or inputOperand() to perform the computation.
    public void inputToken(String token){
    	String sign_str = "+-*/()";
    	
    	if(sign_str.indexOf(token) >= 0){							// If the token is an OPERATOR
    		if(token == "("){										// If the operator is an open parentheses
    		}
    		else if(token == ")" && openparentheses%2 != 1){		// If there is not an open parentheses already
        		throw new IllegalArgumentException();				// Throws exception
    		}
    		inputOperator(token.charAt(0));							// Performs operation by calling inputOperator
    	}
    	
    	else{														// If the token is possibly an OPERAND
    		try{													// Tries parsing token to integer
    			int num = Integer.parseInt(token);					// Sets string value 
    			inputOperand(num);
    		}
    		catch(NumberFormatException ex){						// If the token isn't an integer or operator,
    			throw new IllegalArgumentException();				// Throws IllegalArgumentException
    		}
    	}
    }

    // Convert an equation in infix notation into postfix notation.  Break the
    // equation into tokens and then use inputToken() to process each token.
    // Throw an InvalidArgumentException if the equation contains invalid
    // tokens or if parethesis are not balanced.
    // The return value should give the result of the equation.
    // Hint: Use inputToken() and endEquation() to perform the conversion.
    public String convertEquation(String equation){
    	String str = "";											// Creates our empty string 
		int i =0;													// Index equals 0
		while(i<(equation.length())){								// For all characters in the string
			while(equation.charAt(i) != ' '){						// While the current character is not a space,
				if(equation.charAt(i) == '('){ 						// If the current character is a parenthesis
					openparentheses++;								//Increase the Parenthesis count
				}
				else if(equation.charAt(i) == ')'){
					closeparentheses++;
				}
				
				str= str + equation.charAt(i);						// Add to our empty string
				
				if(i+1<equation.length()){							// Ensures we are in the bounds for the next loop
					i=i+1;											// Increase our index
				}
				else{												// Else, exits
					break;
				}
			}
			i=i+1;													// Increases index count
    		inputToken(str);										// Pass the string as an unknown token
    		str = "";												// Resets the string.
    	}
		if(openparentheses != closeparentheses){					// If the parentheses are not balanced
			throw new IllegalArgumentException();					// Throw exception
		}
		return queue.toString();									// Returns the remaining result of the equation
    }

    // Find the solution to an infix equation.
    // Throw an InvalidArgumentException if the equation contains invalid
    // tokens or if parethesis are not balanced.
    // Break the equation into tokens
    // You may assume that all tokens are separated by whitespace.
    // Hint: Use convertEquation() to convert to postfix, and then an
    // IPostfixCalculator object to find the result.
    public String InputEquation(String equation){
    	String equ = convertEquation(equation);						// Converts equation into Postfix
    	String str = postfix.inputEquation(equ);					// Solves equation and returns in string form
    	return str;													// Returns solution
    }

    // Returns the stack used to track the operators.
    public IStack<Character> getInternalStack(){
    	return stack;												// Returns operator stack
    }

    // Returns the internal queue of postfix tokens.
    public IQueue<String> getInternalPostfixQueue(){
    	return queue;												// Returns queue
    }

    // Returns the underlying postfix calculator used to find the answer after
    // conversion.
    public IPostfixCalculator getInternalPostfixCalculator(){
    	return postfix;
    }
}