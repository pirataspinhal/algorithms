#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
int cost[10][10],i,j,k,n,qu[10],front,rare,v,visit[10],visited[10];
void main()
{ clrscr();
int m;
cout <<"Enter no of vertices";
cin >> n;
cout <<"Enter no of edges";
cin >> m;
cout <<"\nEDGES \n";
for(k=1;k<=m;k++)
{ cin >>i>>j;
cost[i][j]=1;
}
cout <<"Enter initial vertex";
cin >>v;
cout <<"Visitied vertices\n";
cout <<v<<" ";
visited[v]=1;
k=1;
while(k<n)
{
for(j=1;j<=n;j++)
if(cost[v][j]!=0 && visited[j]!=1 && visit[j]!=1)
{
visit[j]=1;
qu[rare++]=j;
}
v=qu[front++];
cout<<v<<" ";
k++;
visit[v]=0; visited[v]=1;
getch();
}}