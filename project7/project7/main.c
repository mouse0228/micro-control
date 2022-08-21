#define F_CPU 11059200UL
#include "C4MLib.h"

int whatnum(int a,int b);
void export(int value1);
int main(void)
{
	ASA_DEVICE_set();
// 	DIO_fpt(200,15,0,15);
// 	for(int i=0;i<10;i++)
// 	{
// 		DIO_fpt(0,15,0,i);
// 		printf("READ");
// 		_delay_ms(500);
// 		if(i==9){i=0;}
// 	}
// 	DIO_fpt(200,127,0,127);
// 
// 	while(1)
// 	{
// 		DIO_fpt(0,127,0,0b1000000);
// 		_delay_ms(500);
// 		DIO_fpt(0,127,0,0b1111001);
// 		_delay_ms(500);
// 		DIO_fpt(0,127,0,0b100100);
// 		_delay_ms(500);
// 		DIO_fpt(0,127,0,0b110000);		
// 		_delay_ms(500);
// 		DIO_fpt(0,127,0,0b11001);
// 		_delay_ms(500);
// 		DIO_fpt(0,127,0,0b10010);
// 		_delay_ms(500);
// 		DIO_fpt(0,127,0,0b10);
// 		_delay_ms(500);
// 		DIO_fpt(0,127,0,0b1111000);
// 		_delay_ms(500);
// 		DIO_fpt(0,127,0,0);
// 		_delay_ms(500);
// 		DIO_fpt(0,127,0,0b10000);
// 		_delay_ms(500);
// 	}	
	
	printf("START");
	int num[4]={0,0,0,0};
	DIO_fpt(202,127,0,127);
	DIO_fpt(2,127,0,0b1000000);
	DIO_fpt(200,31,0,31);
	DIO_fpt(0,7,0,0);
	_delay_ms(1);
	DIO_fpt(0,7,0,1);
	_delay_ms(1);
	DIO_fpt(0,7,0,2);
	_delay_ms(1);
	DIO_fpt(0,7,0,3);
	_delay_ms(1);
	DIO_fpt(0,7,0,7);
	while(1)
	{	
		DIO_fpt(202,240,0,240);
		DIO_fpt(202,15,0,0);
		DIO_fpt(0,16,0,0);
		for(int i=0;i<4;i++)
		{	
			int a=5,b=0,value1=0;
			if(i==0){	DIO_fpt(2,240,0,16);a=1;	}
			else if(i==1){	DIO_fpt(2,240,0,32);a=2;	}
			else if(i==2){	DIO_fpt(2,240,0,64);a=3;	}
			else {	DIO_fpt(2,240,0,128);a=4;	}	
			DIO_fpt(0,8,0,8);
			_delay_ms(1);
			DIO_fpt(0,8,0,0);
			DIO_fpt(2,240,0,0);		
			DIO_get(102,1,&b);
			value1=whatnum(a,b);
			if(value1>=0&&value1<=9)
			{	
				int c=0;
				num[0]=num[1];
				num[1]=num[2];
				num[2]=num[3];
				num[3]=value1;
				while(c<4)
				{
					printf("%d\n",num[c]);
					export(num[c]);
					DIO_fpt(0,7,0,c);
					_delay_ms(1);
					DIO_fpt(0,7,0,7);
					c++;
				}
				DIO_fpt(0,16,0,0);
			}
			_delay_ms(200);
			
		}
	}
}

void export(int value1)
{	
	DIO_fpt(0,16,0,16);
	DIO_fpt(202,255,0,255);

	if (value1==0)
	{
		DIO_fpt(2,127,0,0b1000000);
	}
	else if(value1==1)
	{
		DIO_fpt(2,127,0,0b1111001);
	}
	else if(value1==2)
	{
		DIO_fpt(2,127,0,0b100100);
	}	
	else if(value1==3)
	{
		DIO_fpt(2,127,0,0b110000);
	}
	else if(value1==4)
	{
		DIO_fpt(2,127,0,0b11001);
	}
	else if(value1==5)
	{
		DIO_fpt(2,127,0,0b10010);
	}
	else if(value1==6)
	{
		DIO_fpt(2,127,0,0b10);
	}
	else if(value1==7)
	{
		DIO_fpt(2,127,0,0b1111000);
	}
	else if(value1==8)
	{
		DIO_fpt(2,127,0,0);
	}
	else if(value1==9)
	{
		DIO_fpt(2,127,0,0b10000);
	}
}
int whatnum(int a,int b)
{
		if(b==1)
		{	if(a==4)	{return 0;}	}
		if(b==2)
		{	if(a==4)	{return 1;}	}
		if(b==4)
		{	if(a==4)	{return 4;}	}
		if(b==8)
		{	if(a==4)	{return 7;}	}
		if(b==2)
		{	if(a==3)	{return 2;}	}
		if(b==4)
		{	if(a==3)	{return 5;}	}	
		if(b==8)
		{	if(a==3)	{return 8;}	}		
		if(b==2)
		{	if(a==2)	{return 3;}	}
		if(b==4)
		{	if(a==2)	{return 6;}	}
		if(b==8)
		{	if(a==2)	{return 9;}	}
	return 10;
}