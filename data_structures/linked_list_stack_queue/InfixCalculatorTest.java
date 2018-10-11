import org.junit.*;

public class InfixCalculatorTest
{
  private IInfixCalculator calc;
  private IStack<Character> stack;

  @Before
   public void setUp() throws Exception {
      calc = new InfixCalculator();
      stack = calc.getInternalStack();
  }

  @Test
  public void testInternalPostfixQueue()
  {
    Assert.assertNotNull(calc.getInternalPostfixQueue());
    Assert.assertEquals("[]",calc.getInternalPostfixQueue().toString());
  }

  @Test
  public void testInternalStack()
  {
    Assert.assertNotNull(calc.getInternalStack());
    Assert.assertEquals("[]",calc.getInternalStack().toString());
  }

  @Test
  public void testInternalPostfixCalculator()
  {
    Assert.assertNotNull(calc.getInternalPostfixCalculator());
  }

  @Test
  public void testPushOperand()
  {
    calc.inputOperand(10);
    Assert.assertEquals("[10]",calc.getInternalPostfixQueue().toString());
  }

  @Test
  public void testPushOperator()
  {
    calc.inputOperand(10);
    calc.inputOperator('+');
    Assert.assertEquals("[10]",calc.getInternalPostfixQueue().toString());
    Assert.assertEquals("[+]",calc.getInternalStack().toString());
  }

  @Test
  public void testEndEquasion()
  {
    calc.inputOperand(10);
    calc.inputOperator('+');
    calc.inputOperand(6);
    calc.endEquation();
    Assert.assertEquals("[10, 6, +]",calc.getInternalPostfixQueue().toString());
    Assert.assertEquals("[]",calc.getInternalStack().toString());
  }

}
