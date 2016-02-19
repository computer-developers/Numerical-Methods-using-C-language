#include<conio.h>
#include<stdio.h>
#define size 5
class NFI
{
	private:
		float a[size],x0,h,p;
		void scan()
		{
			int i;
			printf("\nenter starting value & difference...");
			scanf("%f %f",&x0,&h);
			for(i=0;i<size;i++)
			{
				printf("\nenter value of f(%.1f)",x0+i*h);
				scanf("%f",&a[i]);
			}
		}
		void table()
			{
				int i,j;
				for(i=1;i<size;i++)
				{
					for(j=0;j<size-i;j++)
					{
						a[j]=a[j+1]-a[j];
					}
				}
				for(i=0;i<size;i++)
				{
					printf("\n%f",a[i]);
				}
			}
		float method()
			{
				int i,j;
				float y=0,f,g;
				for(i=size-1;i>=0;i--)
				{
					printf("\np=%f y=%f",p,y);
					f=1;
					g=1;
					for(j=1;j<=size-i-1;j++)
					{
						g=g*(p+j-1);
						f=f*j;
					}
					y=y+(g*a[i]/f);
				}
				return y;
			}
	public:
		float nbi(float v)
			{
				p=(v-(x0+(size-1)*h))/h;
				return method();
			}
		NFI()
			{
				scan();
				table();
			}
};
int main()
{
	NFI a;
	float x;
	printf("\nenter value of x");
		scanf("%f",&x);
	printf("\nf(%.2f) = %f",x,a.nbi(x));
	return 0;
}

