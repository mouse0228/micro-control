#define F_CPU 11059200UL
#include "C4MLib.h"


int Linear(int a,int b,int c,int d,int u);
float exponent(float x,float y);
int main()
{
	ASA_DEVICE_set();
	float x,y,ans;
	printf("\nx=:");
	scanf(" %f",&x);
	printf("\n%f",x);
	printf("\nn=:");
	scanf(" %f",&y);
	printf("\n%f",y);
	ans=exponent(x,y);
	printf("\nans=%f",ans);
	float m,n;
	printf("\na=");
	scanf(" %f", &m);
	printf("\n%f",m);
	printf("\nb=");
	scanf(" %f", &n);
	printf("\n%f",n);
	printf("\n---change---");
	swap(&m,&n);
	printf("\na=%f",m);
	printf("b=%f",n);
	int a,b,c,d,u;
	float t;
	
	
	printf("\n---part1---\n");
	printf("a=");
	scanf(" %d", &a);
	printf("\n%d",a);
	printf("\nb=");
	scanf(" %d", &b);
	printf("\n%d",b);
	printf("\nc=");
	scanf(" %d", &c);
	printf("\n%d",c);	
	printf("\nd=");
	scanf(" %d", &d);
	printf("\n%d",d);	
	printf("\nu=");
	scanf(" %d", &u);
	printf("\n%d",u);
	int i;
	for(i=0;i<10;i++)
	{
		t=Linear(a,b,c,d,u);
		printf("\ny=%f",t);
	}
}

float exponent(float x,float y)
{
	float ans=1.0;
	int i ;
	for (i=y;i>0;i--)
	{
		ans = ans*x;
	}
	return(ans);
}swap(float *x,float *y)
{
	float temp;
	temp=*x;
	*x=*y;
	*y=temp;
	
}

int Linear(int a,int b,int c,int d,int u)
{
	static int x=0;
	float y;
	x=a*x+b*u;
	y=c*x+d*u;
	return y;
}