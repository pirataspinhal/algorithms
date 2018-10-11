public class PostfixCalculator implements IPostfixCalculator{
	Stack stack = new Stack();
	
	// Displays the operands currently on the stack. You may use the same
    // formatting as used in IStack.
    public String toString(){
    	return stack.toString();								// Returns the stack as a string
    }

    // Resolve a single operator.  You must support the operators
    // '+', '-', '*', and '/'. You only need to consider division where
    // the quotient is a whole number.
    // Throw an InvalidArgumentException if an invalid operator is provided.
    // The return value should give the remaining operands on the stack after
    // the operator is applied.
    
    public String inputOperator(char operator){
    	String str = "+-*/";									// Our string of operators we are using
    	int answer = 0;											// Defaults our answer to 0
		int num1 = (int) stack.pop();							// Pops the first item
		int num2 = (int) stack.pop();							// Pops our second item
		
		if(str.indexOf(operator) == -1){						// If the given character is not an operator
			throw new IllegalArgumentException();					// Throw IllegalArgumentException
		}
		else if( operator == '*'){								// If we are multiplying
			answer = num1 * num2;									// Multiply the 2 numbers
		}
		else if( operator == '/'){								// If we are dividing
			answer = num2 / num1;									// Divide the 2 numbers
		}
		else if(operator == '+'){								// If we are adding
			answer = num1 + num2;									// Add the 2 numbers
		}
		else if( operator == '-'){								// If we are subtracting
			answer = num2 - num1;									// Subtract the 2 numbers
		}
		
    	stack.push(answer);										// Push the remaining value on the stack
    	return stack.toString();								// Return the string version of the stack.
    	}

    // Enter a single numerical operand onto the stack.
    // The return value should give the remaining operands on the stack after
    // the operand is added.
    public String inputOperand(int operand){
    	stack.push(operand);									// Pushes operand onto stack
    	return stack.toString();								// Returns string of the stack
    }

    // Enter a single token into the calculator representing either a single
    // number or an operator.  Valid examples are '27', '-2', or '/'.
    // Throw an InvalidArgumentException if the token is not an operator or an
    // operand.
    // The return value should give the remaining operands on the stack after
    // the token is applied.
    // Hint: use inputOperator() or inputOperand() to perform the computation.
    public String inputToken(String token){
    	String sign_str = "+-*/";
    	String str = null;
    	
    	if(sign_str.indexOf(token) >= 0){							// If the token is an operator
    		char sign = token.charAt(0);								// Converts to char
    		str = inputOperator(sign);									// Performs operation by calling
    	}
    	else{
    		try{													// Tries parsing token to integer
    			int num = Integer.parseInt(token);					// Sets string value 
    			str = inputOperand(num);
    		}
    		catch(NumberFormatException ex){						// If the token isn't an integer, throw
    			throw new IllegalArgumentException();				// IllegalArgumentException
    		}
    	}
    	return str;													// Returns remaining stack
    }
    // Break the equation into tokens and determine the result of the equation.
    // You may assume that all tokens are separated by whitespace.
    // Throw an InvalidArgumentException if the equation contains invalid
    // tokens.
    // The return value should give the result of the equation.
    // Hint: Use input token to perform the computation.
    public String inputEquation(String equation){
		String str = "";											// Creates our empty string 
		int i =0;													// Index equals 0
		while(i<(equation.length())){								// For all characters in the string
			while(equation.charAt(i) != ' '){							// While the current character is not a space,
				str= str + equation.charAt(i);								// Add to our empty string
				if(i+1<equation.length()){									// Ensures we are in the bounds
					i=i+1;														// Increase our index
				}
				else{														// Else, exits
					break;
				}
			}
			i=i+1;														// Increases index count
    		inputToken(str);											// Pass the string as an unknown token
    		str = "";													// Resets the string.
    	}
		return stack.toString();									// Returns the stack as a string
    }

    // Returns the stack used to track the operands.
    public IStack getInternalStack(){								
    	return stack;												// Returns underlying stack structure
    }
}