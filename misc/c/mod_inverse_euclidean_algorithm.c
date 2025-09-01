#include<stdio.h>
#include<conio.h>

void main()
{
 int n=0,b=0,x,r1,r2,t1,t2,q,r,t,d;
 clrscr();
 printf("Enter the number a : ");
 scanf("%d",&b);
 printf("Enter the number n : ");
 scanf("%d",&n);

 r1=n;
 r2=b;
 t1=0;
 t2=1;

 while(r2>0)
 {
	q=r1/r2;
	r=r1-q*r2;
	r1=r2;
	r2=r;
	t=t1-q*t2;
	t1=t2;
	t2=t;
 }

 if(r1==1)
 {
	if(t1>0)
	{
	  d=t1;
	}
	else
	{
	  d=t1+n;
	}

	printf("\n The inverse of %d mod %d is : %d ",b,n,d);
	getch();
 }
 else
 {
	printf("\n The inverse does not exist. ");
 }

}