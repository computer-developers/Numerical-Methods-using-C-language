#include<stdio.h>
#include<conio.h>
float l,u,m;
float f(float);
void bisect(float,float);
int scan();
void main()
{
	printf("enter limits...");
	for(;!scan(););
	bisect(l,u);
	printf("\nanswer=%f",m);
}
float f(float x)
{
	float y;
	y=x*x*x-x-11;
	return y;
}
int scan()
{
	scanf("%f %f",&l,&u);
	if(f(u)<0)
	{
		if(f(l)<0)
			return 0;
		else
			{
				l=l+u;
				u=l-u;
				l=l-u;
				return 1;
			}
	}
	if(f(u)>0)
	{
		if(f(l)>0)
			return 0;
		else
			return 1;	
	}
	else
	{
		m=u;
		return 1;
	}
}
void bisect(float a,float b)
{
	int x;
	x=a*10-b*10;
	if(x==0)
		return;
	m=(a+b)/2;
	if(f(m)>0)
		bisect(a,m);
	else if(f(m)<0)
		bisect(m,b);
	else
		return;
}
