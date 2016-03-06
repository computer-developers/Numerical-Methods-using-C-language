#include<conio.h>
#include<stdio.h>
class NBI
{
	private:
		float a[5],p;
		void scan()
		{
			int i;
			for(i=0;i<5;i++)
			{
				printf("\nenter value of f(%d)",i*2);
				scanf("%f",&a[i]);
			}
		}
		void table()
			{
				int i,j;
				for(i=1;i<5;i++)
				{
					for(j=0;j<4;j++)
					{
						a[j]=a[j+1]-a[j];
					}
				}
				printf("\ntable of y..");
				for(i=0;i<5;i++)
				{
					printf("\n%f",a[i]);
				}
			}
		float method()
			{
				int i,j;
				float y=0,f,g;
				for(i=4;i>=0;i--)
				{
					f=1;
					g=1;
					for(j=1;j<=4-i;j++)
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
				p=(v-(8))/2;
				return method();
			}
		NBI()
			{
				scan();
				table();
			}
};
int main()
{
	NBI a;
	float x;
	printf("\nenter value of x..");
		scanf("%f",&x);
	printf("\nf(%.2f) = %f",x,a.nbi(x));
	return 0;
}

