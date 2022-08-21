#define F_CPU 11059200UL
#define bit(m) (0x01<<(m)) 
#define bit_set(p,m) ((p)|=(bit(m)))
#define bit_clear(p,m) ((p)&=~(bit(m)))	
#include "C4MLib.h"

int extport_get(int ext_num)
{
	DIO_fpt(202,255,0,0); //設定 PORTC 為輸入(DATA 匯流排輸入)
	DIO_fpt(200,7,0,7); //設定 PORTA2:0 為輸出。(住址匯流排輸出)
	DIO_fpt(200,8,0,8); //設定 PORTA3 為輸出。(RD 控制線輸出)
	DIO_fpt(0,6,0,6); //由 PORTA2:0 送出住址。
	DIO_fpt(0,8,0,8); //由 PORTA3 送出 RD 旗標為 1。
	_delay_ms(200); //延遲足夠時間，等三態器輸出穩定。
	DIO_get(102,1,&ext_num); //讀取 PORTC 輸入值
	DIO_fpt(0,8,0,0); //由 PORTA3 送出 RD 旗標為 0。將讀得值回傳。
	return ext_num;
}

void extport_put(int ex_num)
{
	DIO_fpt(202,255,0,255); //設定 PORTC 為輸出(DATA 匯流排輸出)
	DIO_fpt(200,7,0,7); //設定 PORTA2:0 為輸出。(住址匯流排輸出)
	DIO_fpt(200,16,0,16); //設定 PORTA4 為輸出。(WR 控制線輸出)
	DIO_fpt(2,255,0,ex_num);//由 PORTC 輸出值
	DIO_fpt(0,6,0,6); //由 PORTA2:0 送出住址。
	DIO_fpt(0,16,0,0); //PORTA4 送出 WR 旗標為 0。
	DIO_fpt(0,16,0,16); //由 PORTA4 送出 WR 旗標為 1，產生上升緣栓鎖
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

