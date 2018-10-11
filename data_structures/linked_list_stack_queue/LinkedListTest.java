import org.junit.*;

// import java.util.NoSuchElementException;
//import java.util.Random;
import java.util.ArrayList;
import java.util.Arrays;

public class LinkedListTest {
    ILinkedList<String> target;
    ArrayList<String> original;
    ArrayList<String> control;

    @Before
    public void setUp()
    {
        target = new LinkedList<String>();
        control = new ArrayList<String>();
        original = new ArrayList<String>();
    }

    private void addMany()
    {
        control.addAll(Arrays.asList("First","Second","Third","Fourth","Fifth"));
        for(int i = 0; i < control.size(); i++)
        {
            target.add(control.get(i),i);
        }
        original = new ArrayList<String>(control);
    }

    private String remove(int index)
    {
        control.remove(index);
        return target.remove(index);
    }

    public static <T> boolean listsEqual(ILinkedList<T> ll, ArrayList<T> al)
    {
      if(ll.size() != al.size()) return false;
      for(int i = 0; i < ll.size(); i++)
      {
        if(ll.get(i) != al.get(i)) return false;
      }
      return true;
    }

    // Ensure we have no errors just building the list
    @Test
    public void canInstantiate() { /*testing setUp()*/ }

    @Test
    public void emptyListHasCorrectSize()
    {
        Assert.assertEquals(0, target.size());
    }

    @Test
    public void emptyListHasNoFirst()
    {
        Assert.assertEquals(null, target.getFirstNode());
    }

    @Test
    public void emptyListHasNoLast()
    {
        Assert.assertEquals(null, target.getLastNode());
    }

    @Test(expected=IndexOutOfBoundsException.class)
    public void getFromEmptyThrowsIndexOutOfBoundsException()
    {
        target.get(0);
    }

    @Test
    public void addFirstIncreasesSize()
    {
        target.add("First",0);
        Assert.assertEquals(1, target.size());
    }

    @Test
    public void addFirstCreatesFirstAndLastNode()
    {
        target.add("First",0);
        Assert.assertNotNull(target.getFirstNode());
        Assert.assertEquals(target.getFirstNode(), target.getLastNode());
    }

    @Test
    public void addFirstNodeHasElement()
    {
        String element = "First";
        target.add(element,0);
        Assert.assertEquals(element, target.getFirstNode().data());
    }

    @Test
    public void canAddMany()
    {
        addMany();
    }

    @Test
    public void addManyHasCorrectSize()
    {
        addMany();
        Assert.assertEquals(control.size(), target.size());
    }

    @Test
    public void addManyHasCorrectGet()
    {
        addMany();
        for(int i = 0; i < control.size(); i++)
        {
            Assert.assertEquals(control.get(i), target.get(i));
        }
    }

    @Test
    public void addManyNodesHaveNext()
    {
        addMany();
        Assert.assertNotNull(target.getFirstNode().next());
    }

    @Test
    public void addManyNodesHavePrevious()
    {
        addMany();
        Assert.assertNotNull(target.getLastNode().previous());
    }

    @Test
    public void addManyHasNodesForward()
    {
        addMany();
        ILinkedList.INode cursor = target.getFirstNode();
        for(int i = 0; i < control.size();i++)
        {
            Assert.assertEquals(control.get(i), cursor.data());
            cursor = cursor.next();
        }
        Assert.assertNull(cursor);
    }

    @Test
    public void addManyHasNodesBackward()
    {
        addMany();
        ILinkedList.INode cursor = target.getLastNode();
        for(int i = 0; i < control.size();i++)
        {
            Assert.assertEquals(control.get(control.size()-i-1), cursor.data());
            cursor = cursor.previous();
        }
        Assert.assertNull(cursor);
    }

    @Test
    public void canToString()
    {
       addMany();
       Assert.assertEquals(control.toString(), target.toString());
    }

    @Test
    public void canRemove()
    {
        addMany();
        remove(3);
        Assert.assertTrue("After removing the fourth element from "+original+" the result should be "+control+" but is "+target+" instead.", listsEqual(target,control));
    }

    @Test
    public void canRetrieveRemoved()
    {
        addMany();
        String expected = control.get(3);
        Assert.assertEquals(remove(3), expected);
    }

    @Test
    public void canRemoveStart()
    {
        addMany();
        remove(0);
        Assert.assertTrue("After removing the first element from "+original+" the result should be "+control+" but is "+target+" instead.", listsEqual(target,control));
    }

    @Test
    public void canRetrieveRemovedStart()
    {
        addMany();
        String expected = control.get(0);
        Assert.assertEquals(remove(0), expected);
    }

    @Test(expected=IndexOutOfBoundsException.class)
    public void removeUnderBounds()
    {
      addMany();
      target.remove(-1);
    }

    @Test(expected=IndexOutOfBoundsException.class)
    public void removeOverBounds()
    {
      addMany();
      target.remove(5);
    }

    @Test(expected=IndexOutOfBoundsException.class)
    public void removeFarOverBounds()
    {
      addMany();
      target.remove(10);
    }

    @Test
    public void canFindIndexOf()
    {
      addMany();
      Assert.assertEquals(2,target.indexOf(control.get(2)));
    }

    @Test
    public void cantFindIndexOf()
    {
      addMany();
      Assert.assertEquals(-1,target.indexOf("Other"));
    }

    @Test
    public void canSet()
    {
      addMany();
      String expected = "New";
      target.set(2, expected);
      Assert.assertEquals(expected, target.get(2));
    }

    @Test(expected=IndexOutOfBoundsException.class)
    public void setUnderBounds()
    {
      addMany();
      target.set(-1,"New");
    }

    @Test(expected=IndexOutOfBoundsException.class)
    public void setOverBounds()
    {
      addMany();
      target.set(5,"New");
    }

    @Test(expected=IndexOutOfBoundsException.class)
    public void setFarOverBounds()
    {
      addMany();
      target.set(10,"New");
    }
}
