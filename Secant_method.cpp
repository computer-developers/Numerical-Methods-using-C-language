/*
	Designed by neel patel..
	This program can be able to find roots of eqution.
	The input eqution must be in following pattern..
	Some examples of input equation..
		x^3-x-11
		x$3-x-11
		X^3-1x-11
		x^2+24X^2+87x-24
		
	NOTE :- input equation can start with sign(+,-) or number(0-9) or x(X,x).
			don't leave space between any element of eqution.
			eqution must ended with new-line character(enter).
			don't press any other keys like backspace or delete.
	Limitation :- this program can not be able to solve equation which contain log or trigonometric functions.  	
*/
#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<math.h>
#define DECI 6
class function
{
	private:
		struct eq
		{
			float c;
			int p;
			int s;
			struct eq *l;
		}*first=NULL;		
		int ip(char c)
		{
			if(c>='0'&&c<='9')
			 	return 1;
			if(c=='+'||c=='-')
				return 2;
			if(c=='X'||c=='x')
				return 3;
			if(c=='^'||c=='$')
				return 4;
			if(c==13)
				return 0;
			return 5;
		}		
		int scan()
		{
			int k;
			char c;
			struct eq *t=NULL,*h=NULL;
			printf("enter polynominal equation in x...");
				for(;!ip(c=getche()););
		start:
				h=new struct eq;
				h->l=NULL;
				h->p=0;
				h->s=1;
				h->c=1;
				if(t==NULL)
					t=h;
				else
				{
					t->l=h;
					t=t->l;
				}
				if(first==NULL)
					first=t;
				if(ip(c)==5||ip(c)==4)
					goto err;
				else if(ip(c)==1)
				{
					t->s=1;
					k=c-48;
					goto num; 
				}
				else if(ip(c)==2)
				{
					if(c=='-')
						t->s=-1;
					else
						t->s=1;
					k=1;
					goto sym;
				}
				else if(ip(c)==3)
				{
					t->s=1;
					t->c=1;
					goto var;
				}
		num:		
				if(!ip(c=getche()))
				{
					t->c=k;
					return 1;
				}
				else if(ip(c)==1)
				{
					k=k*10+c-48;
					goto num; 
				}
				else if(ip(c)==2)
				{
					t->c=k;
					goto start;
				}
				else if(ip(c)==3)
				{
					t->c=k;
					goto var;
				}
				if(ip(c)==5||ip(c)==4)
					goto err;
		sym:		
				for(;!ip(c=getche()););
				if(ip(c)==1)
				{
					k=c-48;
					goto num; 
				}
				else if(ip(c)==3)
				{
					t->c=1;
					goto var;
				}
				if(ip(c)==5||ip(c)==4||ip(c)==2)
					goto err;
		var:
				t->p=1;
				if(!ip(c=getche()))return 1;
				else if(ip(c)==2)
					goto start; 
				else if(ip(c)==4)
					goto exp;
				if(ip(c)==1||ip(c)==3||ip(c)==5)
					goto err;
		exp:
				for(;!ip(c=getche()););
				if(ip(c)==1)
					t->p=c-48;
				else
					goto err;
				if(!ip(c=getche()))return 1;
				else if(ip(c)==2)
					goto start; 
				if(ip(c)==5||ip(c)==4||ip(c)==1||ip(c)==3)
					goto err;
		err:	printf("\ninvalid equation...");
				first=NULL;
				return 0;
		}
	public:
		float f(float x)
		{
			float y=0;
			struct eq *t;
			t=first;
			for(;t!=NULL;)
			{
				y=y+((t->c) * (t->s) * pow(x,t->p));
				t=t->l; 
			}
			return y;
		}
		function()
		{
			first=NULL;
			for(;!scan();)
				first=NULL;
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
			if(F.f(m)==0||g-h<pow(0.1,DECI)&&h-g<pow(0.1,DECI))
				return;
			m=g-F.f(g)*(g-h)/(F.f(g)-F.f(h));
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
//		Like to see you again....
