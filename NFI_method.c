#include<conio.h>
#include<stdio.h>
#define size 5
float a[size],x0,x,h,p;
void table();
void p1();
float NFI(float);
void main()
{
	int i;
	printf("\nenter starting value & difference...");
	scanf("%f %f",&x0,&h);
	for(i=0;i<size;i++)
	{
		printf("\nenter value of f(%.1f)",x0+i*h);
		scanf("%f",&a[i]);
	}
	printf("\nenter value of x..");
	scanf("%f",&x);
	table();
	printf("\ntable of y..");
	for(i=0;i<size;i++)
	{
		printf("\n%f",a[i]);
	}
	p1();
	printf("\nf(%.2f) = %f",x,NFI(x));
}
void table()
{
	int i,j;
	for(i=0;i<size-1;i++)
	{
		for(j=size-1;j>i;j--)
		{
			a[j]=a[j]-a[j-1];
		}
	}
}
void p1()
{
	p=(x-x0)/h;
}
float NFI(float c)
{
	int i,j;
	float y=0,f,g;
	for(i=0;i<size;i++)
	{
		f=1;
		g=1;
		for(j=1;j<=i;j++)
		{
			g=g*(p-j+1);
			f=f*j;
		}
		y=y+(g*a[i]/f);
	}
	return y;
}
