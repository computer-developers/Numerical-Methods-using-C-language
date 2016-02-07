#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<math.h>
#define DECI 6
class function{
	public:
		float f(float x)
		{
			return x*x*x-x-11;
		}
		float f1(float x)
		{
			return 3*x*x-1;
		}
};
class NR
{
	private:
		float x0,m;
		void start(function F)
		{
			int i;
			if(F.f(0)==0)
			{
				x0=0;
				m=0;
				return;
			}
			if(F.f(0)>0)
			{
				for(i=1;F.f(i)>0&&F.f(-i)>0;i++);
				if(F.f(i)<0)
					x0=i;
				else
					x0=-i;
				return;
			}
			if(F.f(0)<0)
			{
				for(i=1;(F.f(i)<0) && (F.f(-i)<0);i++);
				if(F.f(i)>0)
					x0=(float)i;
				else
					x0=-i;
				return;
			}
		}
		void meth(float g,function F)
		{
			m=g-F.f(g)/F.f1(g);
			if(g-m<pow(0.1,DECI)&&m-g<pow(0.1,DECI))
				return;
			meth(m,F);
		}
	public:	
		float nr(function F)
		{
			start(F);
			meth(x0,F);
			return m;
		}			
};
int main()
{
	function f;
	NR a;
	printf("\nroot=%f",a.nr(f));	
}
