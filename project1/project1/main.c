#define F_CPU 11059200UL
#include "c4mlib.h"


int main()
{ 
	ASA_DEVICE_set(); 
	//Q1
	printf("\nHello! I can write program now.\n\n");
		
	//Q2
	printf("Character %c's ASCII code is %d\n",'A', (short int)'A');    
	printf("The ASCII code %d represents the Character %c \n",(short int)66, 66);        
	printf("Decimate number %d in Hexadecimal is %x\n", (short int)15,(short int)15);    
	printf("The scientific form of %f is %E\n\n", 0.001234,0.001234); 
		
		//Q3
	int input;    
	printf("Please keyin a number:");    
	scanf("%d", &input);
	printf("\nThe number you keyined is: %d\n\n", input);
	
	//Q4
	char ch;
	printf("Please keyin an alpha:");  
	scanf(" %c", &ch);
	printf("\nCharacter %c's ASCII code is %d\n\n",ch, (short int)ch);    
	
	//Q5
	int num;
	printf("Please keyin a number:");
	scanf(" %d", &num);
	printf("\nThe ASCII code %d represents the Character %c \n",(short int)num, num);        
	printf("Decimate number %d in Hexadecimal is %x\n\n", (short int)num,(short int)num); 
	
	//Q6   
	float f;
	printf("Please keyin a float number:");
	scanf(" %f", &f);
	printf("\nThe scientific form of %f is %e\n\n", f,f); 
	
	//Q7
	int a,b,c;
	a=85; // 8x10^1+5=80+5=85
	b=0x55; // 5x16^1+5x16^0=80+5=85
	c=0b01010101; // 1x2^6+1x2^4+1x2^2+1x2^0= 64+16+4+1=85
	printf("A=%d\nB=%d\nC=%d\n\n",a,b,c);
	
	//Q8
	float con;	
	printf("Please keyin a number:\n");
	scanf( "%f", &con);
	printf("sizeof(%f):\t %d bytes\n\n",con,(int)sizeof(con));

	return 0;
} 
