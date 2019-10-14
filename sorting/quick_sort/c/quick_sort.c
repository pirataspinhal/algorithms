#include <stdio.h>
int a[10];

int partition(int low,int high)
{
  int pivot,pindex,t,i;
  pivot = a[low];
  pindex = high;
  i = high;

  for(i=high;i>low;i--)
  {
    if(a[i] >= pivot)
    {
       t = a[i];
       a[i] = a[pindex];
       a[pindex] = t;
       pindex--;
    }
  }
   t = a[low];
   a[low] = a[pindex];
   a[pindex] = t;
  return pindex;
}

void quick_sort(int low,int high)
{
  int pindex;
  if(low<high)
  {
    pindex = partition(low,high);
    quick_sort(low,pindex-1);
    quick_sort(pindex+1,high);
  }
  else
  return;
}

int main(void) 
{
  int i,j,n;
  printf("enter the number of elements");
  scanf("%d",&n);

  printf("enter the elements");   
  for(i = 0; i<n ; i++)
  {
   scanf("%d",&a[i]);
  }
   i=0;
   j=n-1;
  quick_sort(i,j);

  printf("SORTED ELEMENTS\n");
  for(i=0;i<n;i++)
  {
    printf("%d\t",a[i]);
  }
}
