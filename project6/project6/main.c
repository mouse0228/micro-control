#define F_CPU 11059200UL
#define bit(m) (0x01<<(m)) 
#define bit_set(p,m) ((p)|=(bit(m)))
#define bit_clear(p,m) ((p)&=~(bit(m)))	
#include "C4MLib.h"

int extport_get(int ext_num)
{
	DIO_fpt(202,255,0,0); //�]�w PORTC ����J(DATA �׬y�ƿ�J)
	DIO_fpt(200,7,0,7); //�]�w PORTA2:0 ����X�C(��}�׬y�ƿ�X)
	DIO_fpt(200,8,0,8); //�]�w PORTA3 ����X�C(RD ����u��X)
	DIO_fpt(0,6,0,6); //�� PORTA2:0 �e�X��}�C
	DIO_fpt(0,8,0,8); //�� PORTA3 �e�X RD �X�Ь� 1�C
	_delay_ms(200); //���𨬰��ɶ��A���T�A����Xí�w�C
	DIO_get(102,1,&ext_num); //Ū�� PORTC ��J��
	DIO_fpt(0,8,0,0); //�� PORTA3 �e�X RD �X�Ь� 0�C�NŪ�o�Ȧ^�ǡC
	return ext_num;
}

void extport_put(int ex_num)
{
	DIO_fpt(202,255,0,255); //�]�w PORTC ����X(DATA �׬y�ƿ�X)
	DIO_fpt(200,7,0,7); //�]�w PORTA2:0 ����X�C(��}�׬y�ƿ�X)
	DIO_fpt(200,16,0,16); //�]�w PORTA4 ����X�C(WR ����u��X)
	DIO_fpt(2,255,0,ex_num);//�� PORTC ��X��
	DIO_fpt(0,6,0,6); //�� PORTA2:0 �e�X��}�C
	DIO_fpt(0,16,0,0); //PORTA4 �e�X WR �X�Ь� 0�C
	DIO_fpt(0,16,0,16); //�� PORTA4 �e�X WR �X�Ь� 1�A���ͤW�ɽt����
}
int main(void)
{
	ASA_DEVICE_set();
/*	int a,data=1;*/
// 	while(1)
// 	{
// 		printf("input any num get data ,0 for exit\n");
// 		scanf(" %d", &a);
// 		
// 		printf("pinC=%d\n",extport_get(data));
// 		if (a==0)
// 		{
// 			printf("exit!\n");
// 			break;		
// 		}
//  	}	
	
// 	int a=1;
// 	while(1){
// 		printf("Input num:\n");
// 		scanf(" %d", &a);
// 		extport_put(a);
// 	}
// 	
	int a=1,data=1;
	while(1)
	{
		printf("input any num get data ,0 for exit\n");
		scanf(" %d", &a);

		data=extport_get(data);
		printf("data=%d\n",data);
		extport_put(data);		
		if (a==0)
		{
			printf("exit!\n");
			break;
		}
 	}
}

