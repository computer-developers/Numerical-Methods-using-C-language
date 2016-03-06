#include<stdio.h>
#include<conio.h>
float l,u,m,k;
float f(float);
void fp(float,float);
void main()
{
	printf("enter limits...");
	scanf("%f %f",&l,&u);
	k=u;
	fp(l,u);
	printf("\nanswer=%f",m);
}
float f(float x)
{
	float y;
	y=x*x*x-x-11;
	return y;
}
void fp(float g,float h)
{
	if(f(h)==f(g))
		return;
	m=(g*f(h)-h*f(g))/(f(h)-f(g));
	if(k-m<0.001&&m-k<0.001)
		return;
	k=m;
	if(f(m)>0)
		fp(g,m);
	else if(f(m)<0)
		fp(m,h);
	else
		return;
}
