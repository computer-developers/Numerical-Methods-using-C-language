#include<stdio.h>
#include<conio.h>
float x,m;
float f(float);
float f1(float);
void nr(float);
void main()
{
	printf("enter starting point...");
	scanf("%f",&x);
	nr(x);
	printf("\nanswer=%f",m);
}
float f(float x)
{
	float y;
	y=x*x*x-x-11;
	return y;
}
float f1(float x)
{
	float y;
	y=3*x*x-1;
	return y;
}
void nr(float g)
{
	m=g-f(g)/f1(g);
	if(g-m<0.001&&m-g<0.001)
		return;
	nr(m);
}
