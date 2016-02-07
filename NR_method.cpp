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
		float f1(float x)
		{
			float y;
			y=3*x*x-1;
			return y;
		}
};
class NR
{
	private:
		float x0,m;
		void start(function F)
		{
			printf("\nenter initial value..");
			scanf("%f",&x0);
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
