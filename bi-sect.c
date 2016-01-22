#include<stdio.h>
#include<conio.h>
#define deci 0.1
float c1,c2,c3,l,u,m;
float f(float);
void start();
void bisect(float,float);
void main()
{
	printf("enter value of co-efficient...");
	scanf("%f %f %f",&c1,&c2,&c3);
	start();
	bisect(l,u);
	printf("root=%.1f",m);
}
float f(float x)
{
	float y;
	y=x*x*x*c1+x*c2+c3;
	return y;
}
void start()
{
	int i;
	if(f(0)==0)
	{
		l=0;
		u=0;
		m=0;
		return;
	}
	if(f(0)>0)
	{
		if(f(1)>f(0))
		{
			for(i=-1;f(i+1)>0;i--)l=i;
		}
		else
		{
			for(i=1;f(i-1)>0;i++)l=i;
		}
		u=l+1;
		return;
	}
	if(f(0)<0)
	{
		//printf("check 4");
		if(f(1)<f(0))
		{
		//			printf("check 3");

			for(i=-1;f(i+1)<0;i--)u=i;
		}
		else
		{
		//	printf("check 6");
			for(i=1;f(i-1)<0;i++)u=i;
		}
		l=u-1;
		return;
	}
}
void bisect(float a,float b)
{
	if(a-b<deci&&a-b>-deci)
		return;
	m=(a+b)/2;
	if(f(m)>0)
		bisect(a,m);
	else	bisect(m,b);
}
