#include<stdio.h>
#include<conio.h>
float l,u,m;
float f(float);
void bisect(float,float);
void main()
{
	printf("enter limits...");
	scanf("%f %f",&l,&u);
	bisect(l,u);
	printf("\nanswer=%f",m);
}
float f(float x)
{
	float y;
	y=x*x*x-x-11;
	return y;
}
void bisect(float a,float b)
{
	if(a-b<0.001&&b-a<0.001)
		return;
	m=(a+b)/2;
	if(f(m)>0)
		bisect(a,m);
	else if(f(m)<0)
		bisect(m,b);
	else
		return;
}
