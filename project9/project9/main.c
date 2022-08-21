#define F_CPU 11059200UL
#include "C4MLib.h"
#include "math.h"
int flag2=0,flag3=0,int4=0;
void export(int value1);
int whatnum(int a,int b);
long int exert(long int temp1,long int temp2,int sign);
void mat_val(long int temp3,int num[]);

void INT5_vect(void ){
	 	int4=1;
		printf("%d",int4);
	 	cli();//中斷關閉，全部禁能
}


int main(void)
{
	ASA_DEVICE_set();
	static long int temp1,temp2;
	int flag1 = 0,sign = 0,temp4=0,count=0;
	long int temp3 = 0;
	printf("START\n");
	int num[4]={0,0,0,0};
	DIO_fpt(202,127,0,127);
	DIO_fpt(2,127,0,0b1111111);
	DIO_fpt(200,31,0,31);
	DIO_fpt(0,16,0,16);
	DIO_fpt(0,7,0,0);
	_delay_ms(1);
	DIO_fpt(0,7,0,1);
	_delay_ms(1);
	DIO_fpt(0,7,0,2);
	_delay_ms(1);
	DIO_fpt(0,7,0,7);
	_delay_ms(1);
	DIO_fpt(2,127,0,0b1000000);
	DIO_fpt(0,7,0,3);
	_delay_ms(1);
	DIO_fpt(0,7,0,7);

 	EICRB = (1<<2)|(1<<3);
 	EIMSK = (1<<5);
 	DDRE = 0<<5;
	sei();
	while(1)
	{
				
		DIO_fpt(202,240,0,240);
		DIO_fpt(202,15,0,0);
		for(int i=0;i<4;i++)
		{
			
			
			_delay_ms(20);
			DIO_fpt(0,16,0,0);
			int a=5,b=0,value1=17;
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
			if(value1==16){count++;}
			else{count=0;}
			if(count>=4){count=0;sei();}
			
			if(int4==1)
			{
				if(flag2==0||value1==10)
				{
					if(value1>11&&value1<16)
					{
						flag1=1;
					}
					if(temp4>11&&temp4<16&&value1>11&&value1<16)
					{
						flag3=0;
					}
					if(temp4==11&&value1>=0&&value1<10)
					{
						temp1=0;
						temp2=0;
						flag1=0;
						flag3=0;
						sign=0;
					}
					if(value1>=0 && value1<10 && flag1==0)
					{
						printf("%d",value1);
						temp1=temp1*10+value1;
						mat_val(temp1,num);
						for(int i=0;i<4;i++)
						{
							export(num[i]);
							DIO_fpt(0,7,0,i);
							DIO_fpt(0,7,0,4);
						}
					}
					else if(value1>=0 && value1<10 && flag1==1)
					{
						printf("%d",value1);
						temp2=temp2*10+value1;
						mat_val(temp2,num);
						for(int i=0;i<4;i++)
						{
							export(num[i]);
							DIO_fpt(0,7,0,i);
							DIO_fpt(0,7,0,4);
						}
					}
					else if(value1==10)
					{
						printf("c\n");
						temp1=0;
						temp2=0;
						flag1=0;
						flag3=0;
						sign=0;
						num[0]=11;
						num[1]=11;
						num[2]=11;
						num[3]=0;
						for(int i=0;i<4;i++)
						{
							export(num[i]);
							DIO_fpt(0,7,0,i);
							DIO_fpt(0,7,0,4);
						}
						flag2=0;
					}
					else if(value1==11)
					{
						printf("=");
						temp3=exert(temp1,temp2,sign);
						temp1=temp3;
						mat_val(temp3,num);
						printf("%ld",temp3);
						for(int i=0;i<4;i++)
						{
							
							export(num[i]);
							DIO_fpt(0,7,0,i);
							DIO_fpt(0,7,0,4);
							
						}
						printf("\n");
					}
					else if(value1==12)
					{
						printf("^");

						if (flag3==1&& 0<=temp4 && temp4<=9)
						{
							temp3=exert(temp1,temp2,sign);
							temp1=temp3;
							mat_val(temp3,num);
							printf("%ld",temp3);
							for(int i=0;i<4;i++)
							{
								export(num[i]);
								DIO_fpt(0,7,0,i);
								DIO_fpt(0,7,0,4);
							}
							temp2=0;
							sign = 1;
							printf("\n");
						}
						else
						{
							sign = 1;
							temp2 = 0;
							flag3=1;
						}
					}
					else if(value1==13)
					{
						printf("-");

						if (flag3==1&& 0<=temp4 && temp4<=9)
						{
							temp3=exert(temp1,temp2,sign);
							temp1=temp3;
							mat_val(temp3,num);
							printf("%ld",temp3);
							for(int i=0;i<4;i++)
							{
								export(num[i]);
								DIO_fpt(0,7,0,i);
								DIO_fpt(0,7,0,4);
							}
							temp2=0;
							sign = 2;
							printf("\n");
						}
						else
						{
							sign = 2;
							temp2 = 0;
							flag3=1;
						}
					}
					else if(value1==14)
					{
						printf("x");

						if (flag3==1&& 0<=temp4 && temp4<=9)
						{
							temp3=exert(temp1,temp2,sign);
							
							temp1=temp3;
							mat_val(temp3,num);
							printf("%ld",temp3);
							for(int i=0;i<4;i++)
							{
								export(num[i]);
								DIO_fpt(0,7,0,i);
								DIO_fpt(0,7,0,4);
							}
							temp2=0;
							sign = 3;
							printf("\n");
						}
						else
						{
							sign = 3;
							temp2 = 0;
							flag3=1;
						}
					}
					else if(value1==15)
					{
						printf("/");

						if(flag3==1 && 0<=temp4 && temp4<=9)
						{
							temp3=exert(temp1,temp2,sign);
							temp1=temp3;
							mat_val(temp3,num);
							printf("%ld",temp3);
							for(int i=0;i<4;i++) 
							{
								export(num[i]);
								DIO_fpt(0,7,0,i);
								DIO_fpt(0,7,0,4);
							}
							temp2=0;
							sign = 4;
							
							printf("\n");
						}
						else
						{
							sign = 4;
							temp2 = 0;
							flag3=1;
						}
					}
					if(value1<16&&value1>=0)
					{
						temp4=value1;
						int4=0;
					}
				}
			}
		}
	}
}
void mat_val(long int temp3,int num[])
{
	
	if(temp3>=10000)
	{
		flag2=1;
		num[0]=10;
		num[1]=10;
		num[2]=10;
		num[3]=10;
	}
	else if(temp3<10000 && temp3>=1000)
	{
		num[0]=(temp3/1000)%10;
		num[1]=(temp3/100)%10;
		num[2]=(temp3/10)%10;
		num[3]=temp3%10;
	}
	else if(temp3<1000 && temp3>=100)
	{
		num[0]=11;
		num[1]=(temp3/100)%10;
		num[2]=(temp3/10)%10;
		num[3]=temp3%10;
	}
	else if(temp3<100 && temp3>=10)
	{
		num[0]=11;
		num[1]=11;
		num[2]=(temp3/10)%10;
		num[3]=temp3%10;
	}
	else if(temp3<10 && temp3>=0)
	{
		num[0]=11;
		num[1]=11;
		num[2]=11;
		num[3]=temp3;
	}
	else if(temp3<=-1000)
	{
		num[0]=10;
		num[1]=10;
		num[2]=10;
		num[3]=10;
		flag2=1;
	}
	else if(temp3<0 && temp3>-1000)
	{
		if(temp3>-10)
		{
			temp3=temp3*-1;
			num[0]=11;
			num[1]=11;
			num[2]=10;
			num[3]=temp3;
		}
		else if(temp3<=-10&&temp3>-100)
		{
			temp3=temp3*-1;
			num[0]=11;
			num[1]=10;
			num[2]=(temp3/10)%10;
			num[3]=temp3%10	;
		}
		else if(temp3<=-100)
		{
			temp3=temp3*-1;
			num[0]=10;
			num[1]=(temp3/100)%10;
			num[2]=(temp3/10)%10;
			num[3]=temp3%10;
		}
	}
}

long int exert(long int temp1,long int temp2,int sign)
{
	long int temp3=0;
	if(sign==1)
	{
		temp3=round(pow(temp1,temp2));
	}
	else if(sign==2)
	{
		temp3=temp1-temp2;
	}
	else if(sign==3)
	{
		temp3=temp1*temp2;
	}
	else if(sign==4)
	{
		if(temp2==0)
		{
			return 10000;
		}
		temp3=temp1/temp2;
	}
	else if(sign==0)
	{
		return temp1;
	}
	return temp3;
}

void export(int value1)
{
	DIO_fpt(0,16,0,16);
	DIO_fpt(202,255,0,255);
	if (value1==0)
	{	DIO_fpt(2,127,0,0b1000000);	}
	else if(value1==1)
	{	DIO_fpt(2,127,0,0b1111001);	}
	else if(value1==2)
	{	DIO_fpt(2,127,0,0b100100);	}
	else if(value1==3)
	{	DIO_fpt(2,127,0,0b110000);	}
	else if(value1==4)
	{	DIO_fpt(2,127,0,0b11001);	}
	else if(value1==5)
	{	DIO_fpt(2,127,0,0b10010);	}
	else if(value1==6)
	{	DIO_fpt(2,127,0,0b10);		}
	else if(value1==7)
	{	DIO_fpt(2,127,0,0b1111000);	}
	else if(value1==8)
	{	DIO_fpt(2,127,0,0);			}
	else if(value1==9)
	{	DIO_fpt(2,127,0,0b10000);	}
	else if(value1==10)
	{	DIO_fpt(2,127,0,0b111111);	}
	else if (value1==11)
	{	DIO_fpt(2,127,0,0b1111111);	}
}
int whatnum(int a,int b)
{
	if(b==1)
	{	if(a==4)	{return 0;}
	else if(a==3)	{return 10;}
	else if(a==2)	{return 11;}
	else if(a==1)	{return 12;}
}
else if(b==2)
{	if(a==4)		{return 1;}
else if(a==3)	{return 2;}
else if(a==2)	{return 3;}
else if(a==1)	{return 13;}
}
else if(b==4)
{	if(a==4)	{return 4;}
else if(a==3)	{return 5;}
else if(a==2)	{return 6;}
else if(a==1)	{return 14;}
}
else if(b==8)
{	if(a==4)	{return 7;}
else if(a==3)	{return 8;}
else if(a==2)	{return 9;}
else if(a==1)	{return 15;}
}

return 16;
}
