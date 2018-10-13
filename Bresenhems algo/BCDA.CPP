#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
void octant()
{
   int midx,midy;
   midx =getmaxx()/2;
   midy =getmaxy()/2;
   int xmax=2*midx;
   int ymax=2*midy;
   line(midx,0,midx,ymax);
   line(0,midy,xmax,midy);
   line(0,0,xmax,ymax);
   line(xmax,0,0,ymax);
   outtextxy(midx,midy,"(0,0)");
   outtextxy(midx,ymax-10,"y'");
   outtextxy(xmax-10,midy,"x'");
   outtextxy(midx,0,"y");
   outtextxy(0,midy,"x");
}

int main(void)
{
   int gdriver = DETECT, gmode;
   int xmax, ymax,midx,midy,r,bx[20],by[20],d[20],x,y;
   initgraph(&gdriver, &gmode, "C://TURBOC3//BGI");

   setcolor(getmaxcolor());
   xmax = getmaxx();
   ymax = getmaxy();
   midx =getmaxx()/2;
   midy =getmaxy()/2;
   //circle
   printf("enter the value of radius of circle :");
   scanf("%d",&r);
   x=0;
   y=r;
   bx[0]=x;
   by[0]=y;
   d[0]=3-2*r;
   //printf("%d",d[0]);

   for(int k=0;k<=by[k];k++)
   {
	if(d[k]>0)
	{
	   d[k+1]=d[k]+4*(bx[k]-by[k])+10;
	   by[k+1]=by[k]-1;
	   putpixel(midx+(bx[k]+1),midy+(by[k]-1),RED);
	   putpixel(midx+(bx[k]+1),midy-(by[k]-1),RED);
	   putpixel(midx-(bx[k]+1),midy-(by[k]-1),RED);
	   putpixel(midx-(bx[k]+1),midy+(by[k]-1),RED);
	   putpixel(midx+(by[k]-1),midy+(bx[k]+1),RED);
	   putpixel(midx+(by[k]-1),midy-(bx[k]+1),RED);
	   putpixel(midx-(by[k]-1),midy-(bx[k]+1),RED);
	   putpixel(midx-(by[k]-1),midy+(bx[k]+1),RED);


	}
	else
	{
		d[k+1]=d[k]+4*bx[k]+6;
		by[k+1]=by[k];
		putpixel(midx+(bx[k]+1),midy+by[k],RED);
		putpixel(midx+(bx[k]+1),midy-by[k],RED);
		putpixel(midx-(bx[k]+1),midy-by[k],RED);
		putpixel(midx-(bx[k]+1),midy+by[k],RED);
		putpixel(midx+(by[k]),midy+(bx[k]+1),RED);
		putpixel(midx+(by[k]),midy-(bx[k]+1),RED);
		putpixel(midx-(by[k]),midy-(bx[k]+1),RED);
		putpixel(midx-(by[k]),midy+(bx[k]+1),RED);

	}
	bx[k+1]=x+1;
	x++;
//	printf("\n sum[%d]=%d \t\t\t (%d,%d)",k,d[k],bx[k],by[k]);
	}
//	octant();

   /* clean up */
   getch();
   closegraph();
   return 0;
}

