#define F_CPU 11059200UL
#include "C4MLib.h"


int main(void)
{
	ASA_DEVICE_set();
	int a=1;
	int num;
	DIO_fpt(200,255,0,0);
	DIO_fpt(202,255,0,255);
	while(1){
		DIO_get(100,1,&a);
		printf("pinA=%d\n",a);
		printf("please input your output num:\n");
		scanf(" %d", &num);
		DIO_fpt(2,255,0,num);
		_delay_ms(200);
	}

// 	int num=0,out_mask,out_shift,out_data,in_mask,in_shift,in_data;
// 	int givedata=0,giveshift=0,givemask=0,readdata=0,readbytes=0;
// 	printf("input mask:\n");
// 	scanf(" %d", &in_mask);
// 	printf("input shift:\n");
// 	scanf(" %d", &in_shift);
// 	printf("input data:\n");
// 	scanf(" %d", &in_data);
// 	DIO_fpt(200,in_mask,0,0);
// 	printf("output mask:\n");
// 	scanf(" %d", &out_mask);
// 	printf("output shift:\n");
// 	scanf(" %d", &out_shift);
// 	printf("output data:\n");
// 	scanf(" %d", &out_data);
// 	DIO_fpt(202,out_mask,out_shift,out_data);
// 	
// 	while(num<=10){
// 		printf("input read bytes\n");
// 		scanf(" %d", &readbytes);
// 		DIO_get(100,readbytes,&readdata);
// 		printf("pinA=%d\n",readdata);
// 		printf("input give mask\n");
// 		scanf(" %d", &givemask);
// 		printf("input give shift\n");
// 		scanf(" %d", &giveshift);
// 		printf("input give data\n");
// 		scanf(" %d", &givedata);
// 		DIO_fpt(2,givemask,giveshift,givedata);
// 		num++;
// 		_delay_ms(200);
// 	}
	
// 	int a=1;
// 	DIO_fpt(200,1,0,0);
// 	DIO_fpt(202,255,0,255);
// 	while(1){
// 		DIO_get(100,1,&a);
// 		printf("pinA=%d\n",a);
// 		if(a==1)
// 		{
// 			DIO_fpt(2,255,0,255);
// 
// 		}
// 		else
// 		{			
// 			DIO_fpt(2,255,0,0);
// 		}		
// 		_delay_ms(200);
// 	}
}

