#include<stdio.h>
#include<conio.h>
#define deci 0.01
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
	printf("root=%.2f",m);
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
		u=0;
		for(i=1;f(i)>0&&f(-i)>0;i++);
		if(f(i)<0)
			l=i;
		else
			l=-i;
		return;
	}
	if(f(0)<0)
	{
		l=0;
		for(i=1;f(i)<0&&f(-i)<0;i++);
		if(f(i)>0)
			u=i;
		else
			u=-i;
		return;
	}
}
void bisect(float a,float b)
{
	printf("\n l=%f u= %f m= %f f(m)=%f",l,u,m,f(m));
	if(a-b<deci&&a-b>-deci)
		return;
	m=(a+b)/2;
	if(f(m)>0)
		bisect(a,m);
	else	bisect(m,b);
}
