#include <stdio.h>
#include <malloc.h>
#include <math.h>


#define MAX 10

int a[MAX], rear = 0;
void insert(int num);
void showElements();
void siftUp(int);
void isEmpty();
void getMax();
void getSize();
void siftDown(int);
void extractMax();
void removeItem(int);
void heapify();

int main()
{
    printf("\n:: Inserting Elements in array ::\n");
    insert(10);
    insert(12);
    insert(1);
    insert(9);
    insert(7);
    insert(6);
    insert(8);

//    insert(4);
//    insert(10);
//    insert(3);
//    insert(5);
//    insert(1);

    printf("\n:: Elements in array ::\n");
    showElements();

//    printf("\n:: Max Element in array ::\n");
//    getMax();
//
//    printf("\n:: Size of Heap ::\n");
//    getSize();
//
//    printf("\n:: Empty heap? ::\n");
//    isEmpty();

//    printf("\n:: Sifting Down an Element ::\n");
//    siftDown(1);
//    siftDown(3);

//    printf("\n:: Extracting Max ::\n");
//    extractMax();

//    printf("\n:: Removing item ::\n");
//    removeItem(2);

    printf("\n:: Heapify ::\n");
    heapify();

    printf("\n:: Heap Sort ::\n");
    heapSort();
}

void heapSort()
{
    int sorted[MAX], i;
    int rtemp = rear;
    //extract max
    while(rear >= 1)
    {
        sorted[rear] = a[1];
        a[1] = a[rear];
        rear = rear - 1;
        siftDown(1);
    }

    for(i=1;i<=rtemp;i++)
    {
        printf("%i - %d\n",i,sorted[i]);
    }

}

void heapify()
{
    int i,temp;

    //heapifying the items
    for(i=1;i<=7;i++)
    {
//        sifting down elements here for pvt array
//        while(i>1 && a[i/2] < a[i])
//        {
//            temp = a[i/2];
//            a[i/2] = a[i];
//            a[i] = temp;
//        }
        siftDown(i);
    }

    printf("\n:: Elements after heapify ::\n");
    showElements();
}

void removeItem(int index)
{
    int pinf=INFINITY; //using infinity from math.h lib
    a[index] = pinf; //infinity can be any big number than the list, so it can work like extract max
    siftUp(index);   // after sifting up
    extractMax();
}

void extractMax()
{
    int max = a[1];
    a[1] = a[rear];
    rear = rear - 1;
    siftDown(1);
}

void siftDown(int index)
{
    int index_temp = index;
    int temp;
    printf("rear - %d\n",rear);
    while(index < rear)
    {
        int l = 2*index;
        int r = (2*index)+1;
        printf("left-right : %d-%d\n",a[l],a[r]);
        if(a[l] > a[r] && a[l] > a[index])
        {
            temp = a[l];
            a[l] = a[index];
            a[index] = temp;
            index = l;
        }
        else if(a[r] > a[l] && a[r] > a[index])
        {
            temp = a[r];
            a[r] = a[index];
            a[index] = temp;
            index = r;
        }
        else
        {
            break;
        }
    }

    printf("\n:: Elements after sifting down index %d to %d ::\n",index_temp,index);
    showElements();
}

void siftUp(int index)
{
    int temp;
    while(index > 1 && a[index/2] < a[index])
    {
        temp = a[index/2];
        a[index/2] = a[index];
        a[index] = temp;
        index = index/2;
    }
}

void isEmpty()
{
    if(rear == 0)
        printf("Heap is empty\n");
    else
        printf("Heap is not empty.\n");
}

void getMax()
{
    printf("Max Element : %d\n",a[1]);
}

void getSize()
{
    printf("Size of Heap : %d\n",rear);
}

void insert(int num)
{
    if(rear == 0)
    {
        rear=1;
    }
    else
    {
        rear+=1;
    }
    a[rear] = num;

//    siftUp(rear);
}

void showElements()
{
    int i;
    for(i=1;i<=rear;i++)
    {
        printf("%d\n",a[i]);
    }
}
