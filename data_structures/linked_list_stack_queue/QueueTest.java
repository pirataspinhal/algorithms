/**
 * Created by Jean-Paul on 7/7/2015.
 */

import org.junit.*;

import java.util.NoSuchElementException;
import java.util.Random;
import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;


public class QueueTest {
    private static List<String> control;

    private static IQueue<String> target;

    private static Random rng = new Random();

    @BeforeClass
    public static void init() throws Exception {

    }

    @Before
     public void setUp() throws Exception {
        control = new ArrayList<String>();
        target = new Queue<String>();
    }

    private void pushMany()
    {
      control = Arrays.asList("First","Second","Third","Fourth","Fifth");
      for(int i = 0; i < control.size(); i++)
      {
        target.push(control.get(i));
      }
    }

    @Test
    public void canInstantiate()
    { /* testing set up*/ }

    @Test
    public void testSizeWhenEmpty()
    {
       Assert.assertEquals(0,target.size());
    }

    @Test(expected=NoSuchElementException.class)
    public void testPeekWhenEmpty()
    {
      target.peek();
    }

    @Test
    public void testAddWhenEmpty()
    {
      target.push("First");
    }

    @Test
    public void testSizeAfterPush()
    {
      target.push("First");
      Assert.assertEquals(1,target.size());
    }

    @Test
    public void testPopAfterPush()
    {
      String expected = "First";
      target.push(expected);
      Assert.assertEquals(expected,target.pop());
    }

    @Test
    public void testPushMany()
    {
      pushMany();
    }

    @Test
    public void testSizeAfterPushMany()
    {
      pushMany();
      Assert.assertEquals(5, target.size());
    }

    @Test
    public void testPeekAfterPushMany()
    {
      pushMany();
      Assert.assertEquals(control.get(0), target.peek());
    }

    @Test
    public void testPopAfterPushMany()
    {
      pushMany();
      Assert.assertEquals(control.get(0), target.pop());
    }

    @Test
    public void testToStringAfterPushAndPop()
    {
      pushMany();
      target.pop();
      Assert.assertEquals("[Second, Third, Fourth, Fifth]", target.toString());
    }

    @Test
    public void testPopsAfterPushMany()
    {
      pushMany();
      target.pop();
      Assert.assertEquals(control.get(1), target.pop());
    }

    @Test
    public void testPopPopPushPopPopAfterPushMany()
    {
      pushMany();
      target.pop();
      target.pop();
      target.push("Alternative");
      target.pop();
      target.pop();
      Assert.assertEquals(control.get(4),target.peek());
    }

    @Test
    public void testPopPopPushPopPopStructureAfterPushMany()
    {
      pushMany();
      String alt = "Alternative";
      target.pop();
      target.pop();
      target.push(alt);
      target.pop();
      target.pop();
      ILinkedList list = target.getInternalLinkedList();
      Assert.assertNotNull(list);
      Assert.assertEquals(2,list.size());
      Assert.assertEquals(control.get(4),list.get(0));
      Assert.assertEquals(alt,list.get(1));

    }

}
