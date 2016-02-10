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
class FP
{
	private:
		float l,u,m,k;
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
			m=(g*F.f(h)-h*F.f(g))/(F.f(h)-F.f(g));
			if(k-m<pow(0.1,DECI)&&m-k<pow(0.1,DECI))
				return;
			k=m;
			if(F.f(m)>0)
				meth(g,m,F);
			else
				meth(m,h,F);
		}
	public:	
		float fp(function F)
		{
			start(F);
			meth(l,u,F);
			return m;
		}			
};
int main()
{
	function f;
	FP a;
	printf("\nroot=%f",a.fp(f));	
}
