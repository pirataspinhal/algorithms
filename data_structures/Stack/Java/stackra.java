/***
   Stack with resizing array
***/

public class StackRA<Item> {

   private Item[] a;
   private int N;

   // construtor
   public StackRA() {
      a = (Item[]) new Object[2];
      N = 0;
   }

   // a pilha mora em a[0..N-1]
   
   public boolean isEmpty() {
      return N == 0;
   }
   
   public void push(Item item) { 
      if (N == a.length)
         resize(2 * a.length);
      a[N++] = item;
   }

   public Item pop() {
      Item item = a[--N];
      if (N > 0 && N == a.length/4)
         resize(a.length/2);
      return item;
   }

   private void resize(int max) {
      Item[] temp;
      temp = (Item[]) new Object[max];
      for (int i = 0; i < N; i++)
         temp[i] = a[i];
      a = temp;
   }
}