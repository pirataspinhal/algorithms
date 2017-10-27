/* Finds out the roots o a quadratic equation and their nature. */
#include<iostream>
#include<cmath>
using namespace std;
class quadratic
{
	float a,b,c;
	float r1,r2,d,x,y;
	public:
	void getdata();
	void nature();
};
void quadratic::getdata(void)
{
	cout<<"enter a,b,c"<<endl;
	cin>>a>>b>>c;
}
void quadratic::nature(void)
{
	d=b*b-4*a*c;
	cout<<"discriminant = "<<d<<endl;
	if(d>0)
	{
		cout<<"roots are real and distinct"<<endl;
		r1=(-b+sqrt(d))/(2*a);
		r2=(-b-sqrt(d))/(2*a);
		cout<<"r1="<<r1<<"	"<<"r2="<<r2<<endl;
	}
	else if(d==0)
	{
		cout<<"roots are real and equal"<<endl;
		r1=(-b)/(2*a);
		r2=(-b)/(2*a);
		cout<<"r1="<<r1<<"	"<<"r2="<<r2<<endl;
	}
	else if(d<0)
	{
		d=-d;
		x=-b/(2*a);
		y=sqrt(d)/(2*a);
		cout<<"roots are imaginary"<<endl;
		cout<<"r1="<<x<<"+i"<<y<<endl;
		cout<<"r2="<<x<<"-i"<<y<<endl;
	}
}
int main()
{
	quadratic call;
	call.getdata();
	call.nature();
	return 0;
}

/*samplle I/O
enter a,b,c
1 4 4
discriminant = 0
roots are real and equal
r1=-2   r2=-2

enter a,b,c
1 5 6
discriminant = 1
roots are real and distinct
r1=-2   r2=-3

enter a,b,c
1 1 4
discriminant = -15
roots are imaginary
r1=-0.5+i1.93649
r2=-0.5-i1.93649
*/
