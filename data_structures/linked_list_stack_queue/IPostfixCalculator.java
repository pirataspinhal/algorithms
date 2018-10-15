public interface IPostfixCalculator{

    ////////////////////////////////////////////////////////////////////////////
    // Public interface

    // Displays the operands currently on the stack. You may use the same
    // formatting as used in IStack.
    String toString();

    // Resolve a single opeartor.  You must support the operators
    // '+', '-', '*', and '/'. You only need to consider division where
    // the quotient is a whole number.
    // Throw an InvalidArgumentException if an invalid operator is provided.
    // The return value should give the remaining operands on the stack after
    // the operator is applied.
    String inputOperator(char operator);

    // Enter a single numberical operand onto the stack.
    // The return value should give the remaining operands on the stack after
    // the operand is added.
    String inputOperand(int operand);

    // Enter a single token into the calculator representing either a single
    // number or an opeartor.  Valid examples are '27', '-2', or '/'.
    // Throw an InvalidArgumentException if the token is not an operator or an
    // operand.
    // The return value should give the remaining operands on the stack after
    // the token is applied.
    // Hint: use inputOperator() or inputOperand() to perform the computation.
    String inputToken(String token);

    // Break the equation into tokens and determine the result of the equation.
    // You may assume that all tokens are separated by whitespace.
    // Throw an InvalidArgumentException if the equation contains invalid
    // tokens.
    // The return value should give the result of the equation.
    // Hint: Use input token to perform the computation.
    String inputEquation(String equation);

    ////////////////////////////////////////////////////////////////////////////
    // Private interface
    //
    // Normally, everything past this point would be private.  For the sake of
    // testing in CS249, however, all of these must be provided as public.

    // Returns the stack used to track the operands.
    IStack getInternalStack();

}
