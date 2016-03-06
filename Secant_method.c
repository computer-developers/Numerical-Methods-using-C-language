#include<stdio.h>
#include<conio.h>
float l,u,m;
float f(float);
void secant(float,float);
void main()
{
	printf("enter limits...");
	scanf("%f %f",&l,&u);
	secant(l,u);
	printf("\nanswer=%f",m);
}
float f(float x)
{
	float y;
	y=x*x*x-x-11;
	return y;
}
void secant(float g,float h)
{
	if(f(m)==0||g-h<0.001&&h-g<0.001)
		return;
	m=g-f(g)*(g-h)/(f(g)-f(h));
	secant(m,g);
}
