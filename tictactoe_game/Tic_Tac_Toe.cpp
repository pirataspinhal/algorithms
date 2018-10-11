#include<iostream>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<unistd.h>

using namespace std;

void win(char p1[],char p2[],int,char a[3][3]);
void board(char a[3][3]);
void input(int &,char p1[30],char p2[30],char a[3][3]);
int check(char a[3][3]);

int main()
{
    int k,g=1,i,j,c;	
    char p1[30],p2[30],a[3][3];
    system("clear");  //Clears Output screen.
    cout<<"Please enter your Name : "<<"\nPlayer 1 (X) : ";
    cin.getline(p1,30);
    cout<<"Player 2 (O) : ";
    cin.getline(p2,30);
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
            a[i][j]=' ';
    }
    for(i=0;p1[i]!='\0';i++)
        p1[i]=toupper(p1[i]);
    for(i=0;p2[i]!='\0';i++)
        p2[i]=toupper(p2[i]);
    for(k=1;k<10;k++)
    {
        board(a); //Prints BOARD
        c=check(a); //after every input checks if anyone wins or not
        if(c==1||c==-1)
            break;
        input(g,p1,p2,a); //accepts VALID input
    }
    win(p1,p2,c,a);
    getchar();
    return 0;
}


void board(char a[3][3])
{
    system("clear");
    int i,j,b=1;
    cout<<"\n 		   1    2    3\n 		  -------------";
    cout<<"\n";
    for(i=0;i<3;i++)
    {
        cout<<"		  |   |   |   |\n		"<<b<<" | ";
        for(j=0;j<3;j++)
        {
            cout<<a[i][j];
            cout<<" | ";
        }
        cout<<"\n";
        cout<<"		  -------------\n";
        b++;
    }
}

int check(char a[3][3])
{ int i,j,x;
x=0;
for(i=0;i<3;i++)
{
    int f1=0,f2=0,f3=0,f4=0;
    for(j=0;j<3;j++)
    {
        if(a[i][j]=='X')
            f1++;
        else if(a[i][j]=='O')
            f1--;
        if(a[j][i]=='X')
            f2++;
        else if(a[j][i]=='O')
            f2--;
        if(a[j][j]=='X')
            f3++;
        else if(a[j][j]=='O')
            f3--;
        if(a[j][2-j]=='X')
            f4++;
        else if(a[j][2-j]=='O')
            f4--;
    }
    if(f1==3||f2==3||f3==3||f4==3)
    {
        x=1;
        break;
    }
    else if(f1==-3||f2==-3||f3==-3||f4==-3)
    {
        x=-1;
        break;
    }
    else
        x=0;
}
return x;
}

void input(int &g,char p1[],char p2[],char a[3][3])
{ 
    int i,j,t=0;
	if(g==1)
	puts(p1);
	else
	puts(p2);
	cout<<"Please enter the coordinates for your move. ";
	cin>>i>>j;
    while(t==0)
	{
        if( i>3 || j>3 || a[i-1][j-1]!=' ' )
        {
            cout<<"INVALID MOVE! Please enter a valid move. ";
            cin>>i>>j;
        }
	   else
	       t=1;
	}
    if(g==1)
    {
        a[i-1][j-1]='X';
        g=2;
    }
    else
    {
        a[i-1][j-1]='O';
        g=1;
    }
}

void win(char p1[],char p2[],int c,char a[3][3])
{
    int i,j,k,d,l1,l2,m=0,l;
    l1=strlen(p1);
    l2=strlen(p2);
    if(c==1||c==-1)
    {
        for(i=0;i<16;i++)
        {
            board(a);
            if(c==1&&m==1)
            {
                printf("\t\t%s WINS\n", p1);
                m=0;
            }
            else if(c==-1&&m==1)
            {
                printf("\t\t%s WINS\n", p2);
                m=0;
            }
            else
            m=1;
            usleep(250000); //Time Delay
        }
    }
    else
    cout<<"\t\tDRAW\n";
}
