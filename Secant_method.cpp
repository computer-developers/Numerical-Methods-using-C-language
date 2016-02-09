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
			printf("\nenter limits..");
			for(;!scan(F);)
				printf("\ninvalid!!!");
		}
		int scan(function F)
		{
			scanf("%f %f",&l,&u);
			if(F.f(u)<0)
			{
				if(F.f(l)<0)
					return 0;
				else
					{
						l=l+u;
						u=l-u;
						l=l-u;
						return 1;
					}
			}
			if(F.f(u)>0)
			{
				if(F.f(l)>0)
					return 0;
				else
					return 1;	
			}
			else
			{
				m=u;
				return 1;
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
