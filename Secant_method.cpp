#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<math.h>
#define DECI 6
class function{
	public:
		float f(float x)
		{
			float y;
			y=x*x*x-x-11;
			return y;
		}
};
class SECANT
{
	private:
		float l,u,m;
		void start(function F)
		{
			int i;
			if(F.f(0)==0)
			{
				l=0;
				u=0;
				m=0;
				return;
			}
			if(F.f(0)>0)
			{
				u=0;
				for(i=1;F.f(i)>0&&F.f(-i)>0;i++);
				if(F.f(i)<0)
					l=i;
				else
					l=-i;
				return;
			}
			if(F.f(0)<0)
			{
				l=0;
				for(i=1;F.f(i)<0&&F.f(-i)<0;i++);
				if(F.f(i)>0)
					u=i;
				else
					u=-i;
				return;
			}
		}
		void meth(float g,float h,function F)
		{
			m=g-F.f(g)*(g-h)/(F.f(g)-F.f(h));
			if(g-m<pow(0.1,DECI)&&m-g<pow(0.1,DECI))
				return;
			meth(m,g,F);
		}
	public:	
		float secant(function F)
		{
			start(F);
			meth(l,u,F);
			return m;
		}			
};
int main()
{
	function f;
	SECANT a;
	printf("\nroot=%f",a.secant(f));	
}
