#define F_CPU 11059200UL
#include "C4MLib.h"


int main()
{
	ASA_DEVICE_set();
	int ans1,ans2,ans3,ans4,ans5,ans6,ans7,ans8,ans9,ans10,score = 0,level;
	printf("7*9=?\n");
	scanf( "%d", &ans1);
	if (ans1 == 63){
		printf("correct\n");
		score=score+10;
	}
	else {
		printf("incorrect\n");
	}
	printf("1*4=?\n");
	scanf( "%d", &ans2);
	if (ans2 == 4){
		printf("correct\n");
		score=score+10;
	}
	else {
		printf("incorrect\n");
	}
	printf("0*0=?\n");
	scanf( "%d", &ans3);
	if (ans3 == 0){
		printf("correct\n");
		score=score+10;
	}
	else {
		printf("incorrect\n");
	}
	printf("0*8=?\n");
	scanf( "%d", &ans4);
	if (ans4 == 0){
		printf("correct\n");
		score=score+10;
	}
	else {
		printf("incorrect\n");
	}
	printf("9*1=?\n");
	scanf( "%d", &ans5);
	if (ans5 == 9){
		printf("correct\n");
		score=score+10;
	}
	else {
		printf("incorrect\n");
	}
	printf("6*5=?\n");
	scanf( "%d", &ans6);
	if (ans6 == 30){
		printf("correct\n");
		score=score+10;
	}
	else {
		printf("incorrect\n");
	}
	printf("8*2=?\n");
	scanf( "%d", &ans7);
	if (ans7 == 16){
		printf("correct\n");
		score=score+10;
	}
	else {
		printf("incorrect\n");
	}
	printf("3*1=?\n");
	scanf( "%d", &ans8);
	if (ans8 == 3){
		printf("correct\n");
		score=score+10;
	}
	else {
		printf("incorrect\n");
	}
	printf("5*7=?\n");
	scanf( "%d", &ans9);
	if (ans9 == 35){
		printf("correct\n");
		score=score+10;
	}
	else {
		printf("incorrect\n");
	}
	printf("4*2=?\n");
	scanf( "%d", &ans10);
	if (ans10 == 8){
		printf("correct\n");
		score=score+10;
	}
	else {
		printf("incorrect\n");
	}
	printf("your score is %d\n",score);
	level = score/10; 
	switch(level) {
		case 10:
		case 9:
		printf("Your level is A.\n");
		break;
		case 8:
		printf("Your level is B.\n");
		break;
		case 7:
		printf("Your level is C.\n");
		break;
		case 6:
		printf("Your level is D.\n");
		break;
		
		default:
		printf("Your level is F.\n");
	}
	int i,j;
	printf("\n\t1\t2\t3\t4\t5\t6\t7\t8\t9\n");
	printf("--+");
	for(i=1;i<30;i++)
	{
		printf("---");
	}
		printf("\n");
	
	for(i=1;i<10;i++)
	{
		printf(" %d|\t",i);
		for(j=1;j<10;j++)
		{
			printf("%d\t",i*j);
			if (j==9)
			{
				printf("\n");
			}
		}	
	}
	int k=1,l=1;
	printf("\n\t1\t2\t3\t4\t5\t6\t7\t8\t9\n");
	printf("--+");
	for(i=1;i<30;i++)
	{
		printf("---");
	}
	printf("\n");
	
	while(k!=10)
	{
		printf(" %d|\t",k);
		while(l!=10)
		{
			printf("%d\t",k*l);

			if(l==9)
			{
				printf("\n");
			}			
			l=l+1;
		}
		l=1;
		k=k+1;
	}
}

