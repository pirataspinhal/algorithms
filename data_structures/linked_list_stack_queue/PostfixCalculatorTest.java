import org.junit.*;

public class PostfixCalculatorTest
{
  private IPostfixCalculator calc;

  @Before
   public void setUp() throws Exception {
      calc = new PostfixCalculator();
  }

  @Test
  public void canInstantiate()
  { /* Testing setup */ }

  @Test
  public void testEmptyToString()
  {
    Assert.assertEquals("[]", calc.toString());
  }

  @Test
  public void testPushOperand()
  {
    calc.inputOperand(10);
    Assert.assertEquals("[10]", calc.toString());
  }

  @Test
  public void testPushOperandReturns()
  {
    Assert.assertEquals("[10]", calc.inputOperand(10));
  }

  @Test
  public void testPushTwoOperands()
  {
    calc.inputOperand(10);
    calc.inputOperand(6);
    Assert.assertEquals("[6, 10]", calc.toString());
  }

  @Test
  public void testAddOperator()
  {
    calc.inputOperand(10);
    calc.inputOperand(6);
    calc.inputOperator('+');
    Assert.assertEquals("[16]", calc.toString());
  }

  @Test
  public void testPushOperatorReturns()
  {
    calc.inputOperand(10);
    calc.inputOperand(6);
    Assert.assertEquals("[16]", calc.inputOperator('+'));
  }

  @Test
  public void testSubtractOperator()
  {
    calc.inputOperand(10);
    calc.inputOperand(6);
    calc.inputOperator('-');
    Assert.assertEquals("[4]", calc.toString());
  }

  @Test
  public void testDivideOperator()
  {
    calc.inputOperand(20);
    calc.inputOperand(4);
    calc.inputOperator('/');
    Assert.assertEquals("[5]", calc.toString());
  }

  @Test
  public void testMultiplyOperator()
  {
    calc.inputOperand(10);
    calc.inputOperand(6);
    calc.inputOperator('*');
    Assert.assertEquals("[60]", calc.toString());
  }

  @Test
  public void testAddTokens()
  {
    calc.inputToken("10");
    calc.inputToken("6");
    Assert.assertEquals("[16]", calc.inputToken("+"));
  }

  @Test
  public void testPushTokenReturns()
  {
    calc.inputToken("10");
    calc.inputToken("6");
    Assert.assertEquals("[16]", calc.inputToken("+"));
  }

  @Test
  public void testDivideTokens()
  {
    calc.inputToken("20");
    calc.inputToken("2");
    calc.inputToken("/");
    Assert.assertEquals("[10]", calc.toString());
  }

  @Test
  public void testEquasion()
  {
    calc.inputEquation("30 17 +");
    Assert.assertEquals("[47]", calc.toString());
  }

  @Test
  public void testEquasionReturns()
  {
    Assert.assertEquals("[47]", calc.inputEquation("30 17 +"));
  }

  @Test
  public void testExampleEquasion()
  {
    calc.inputEquation("3 4 5 * 10 / + 11 +");
    Assert.assertEquals("[16]", calc.toString());
  }

  @Test
  public void testEquasionStack()
  {
    calc.inputEquation("3 4 5 * 10 /");
    IStack<Integer> stack = calc.getInternalStack();
    Assert.assertNotNull(stack);
    ILinkedList<Integer> list = stack.getInternalLinkedList();
    Assert.assertNotNull(list);
    Assert.assertEquals(2, list.get(0).intValue());
    Assert.assertEquals(3, list.get(1).intValue());
  }

}
