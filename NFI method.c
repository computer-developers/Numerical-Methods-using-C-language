#include<conio.h>
#include<stdio.h>
float a[5],x,p;
void table();
void p1();
float NFI(float);
void main()
{
	int i;
	for(i=0;i<5;i++)
	{
		printf("\nenter value of f(%d)",i*2);
		scanf("%f",&a[i]);
	}
	table();
	printf("\nenter value of x..");
	scanf("%f",&x);
	p1();
	printf("\nf(%.2f) = %f",x,NFI(x));
}
void table()
{
	int i,j;
	for(i=0;i<4;i++)
	{
		for(j=4;j>i;j--)
		{
			a[j]=a[j]-a[j-1];
		}
	}
}
void p1()
{
	p=(x-0)/2;
}
float NFI(float c)
{
	int i,j;
	float y=0,f,g;
	for(i=0;i<5;i++)
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
