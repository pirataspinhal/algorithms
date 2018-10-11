
public interface IInfixCalculator{

    ////////////////////////////////////////////////////////////////////////////
    // Public interface

    // Process a single operator.  You must support the operators
    // '+', '-', '*', '/', '(' and ')'.
    // Throw an InvalidArgumentException if an invalid opeator is provided or
    // if a closed parenthesis is provided without an opening paranthesis.
    void inputOperator(char operator);

    // Process a single numerical operand.
    void inputOperand(int operand);

    // Closes the conversion, resolving any left over operators.
    // This leaves the operator stack empty and the queue with a
    // complete postfix equasion.
    void endEquation();

    // Enter a single token into the calculator representing either a single
    // number or opeartor.  Valid examples are '27', '-2', ')', or '/'.
    // Throw an InvalidArgumentException if the token is not valid, or if a
    // closed parenthesis is provided without an opening paranthesis.
    // The return value should give the remaining operands on the stack after
    // the token is applied.
    // Hint: use inputOperator() or inputOperand() to perform the computation.
    void inputToken(String token);

    // Convert an equation in infix notation into postfix notation.  Break the
    // equation into tokens and then use inputToken() to process each token.
    // Throw an InvalidArgumentException if the equation contains invalid
    // tokens or if parethesis are not balanced.
    // The return value should give the result of the equation.
    // Hint: Use inputToken() and endEquation() to perform the conversion.
    String convertEquation(String equation);

    // Find the solution to an infix equation.
    // Throw an InvalidArgumentException if the equation contains invalid
    // tokens or if parethesis are not balanced.
    // Break the equation into tokens
    // You may assume that all tokens are separated by whitespace.
    // Hint: Use convertEquation() to convert to postfix, and then an
    // IPostfixCalculator object to find the result.
    String InputEquation(String equation);

    ////////////////////////////////////////////////////////////////////////////
    // Private interface
    //
    // Normally, everything past this point would be private.  For the sake of
    // testing in CS249, however, all of these must be provided as public.

    // Returns the stack used to track the operators.
    IStack<Character> getInternalStack();

    // Returns the internal queue of postfix tokens.
    IQueue<String> getInternalPostfixQueue();

    // Returns the underlying postfix calculator used to find the answer after
    // conversion.
    IPostfixCalculator getInternalPostfixCalculator();

}
