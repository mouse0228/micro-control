#define F_CPU 11059200UL
#include "C4MLib.h"

struct students{
	char name[20];
	long int studentid;
	int score;
}stud[5];

int main(void)
{
	ASA_DEVICE_set();
// 	int num,tmp;
// 	printf("How many score do you want?\n");
// 	scanf(" %d", &num);
// 	int i,score[num],j;
// 	for(i=0;i<num;i++)
// 	{
// 		printf("Please input %d. score\n",i+1);
// 		scanf(" %d", &score[i]);
// 	}
// 	for (i=num;i>0;i--) 
// 	{
// 		for (j=0;j<i-1;j++) 
// 		{
// 			if (score[j] > score[j+1])
// 			{
// 				tmp=score[j];
// 				score[j]=score[j+1];
// 				score[j+1]=tmp;
// 			}
// 		}
// 		printf("%d. %d   ",num-i+1,score[i-1]);
// 	}
	
// 	int num;
// 	printf("How many score do you want?\n");
// 	scanf(" %d", &num);
// 	int i,j;
// 	unsigned long int score[num][2],tmp;
// 	for(i=0;i<num;i++)
// 	{
// 		printf("Please input %d. student ID\n",i+1);
// 		scanf(" %ld", &score[i][0]);
// 		printf("Please input %d. score\n",i+1);
// 		scanf(" %ld", &score[i][1]);
// 	}
// 	for (i=num;i>0;i--)
// 	{
// 		for (j=0;j<i-1;j++)
// 		{
// 			if (score[j][1] > score[j+1][1])
// 			{
// 				tmp=score[j][0];
// 				score[j][0]=score[j+1][0];
// 				score[j+1][0]=tmp;
// 				tmp=score[j][1];
// 				score[j][1]=score[j+1][1];
// 				score[j+1][1]=tmp;
// 			}
// 		}
// 		printf("%d. %ld  %ld ",num-i+1,score[i-1][0],score[i-1][1]);
// 	}	

// 	long int A[4][2];
// 	HMI_snget_matrix(2,4,2,A);
// 
// 	int i,j;
// 	long int tmp;
// 
// 	for (i=4;i>0;i--)
// 	{
// 		for (j=0;j<i-1;j++)
// 		{
// 			if (A[j][1] > A[j+1][1])
// 			{
// 				tmp=A[j][0];
// 				A[j][0]=A[j+1][0];
// 				A[j+1][0]=tmp;
// 				tmp=A[j][1];
// 				A[j][1]=A[j+1][1];
// 				A[j+1][1]=tmp;
// 			}
// 		}
// 		printf("%d. %ld  %ld ",4-i+1,A[i-1][0],A[i-1][1]);
// 	}
// 	
// 	
// 	HMI_snput_matrix(2,4,2,A);

	int i,j,k,tmp_score;
	long int tmp_studentid;
	char tmp_name;
	for(i=0;i<5;i++)
	{
		HMI_snget_struct("i8_20,i32_1,i16_1",sizeof(stud[i]),&stud[i]);
	}  

	for (i=5;i>0;i--)
	{
		for (j=0;j<i-1;j++)
		{
			if (stud[j].score > stud[j+1].score)
			{
				for(k=0;k<20;k++)
				{
					tmp_name=stud[j].name[k];
					stud[j].name[k]=stud[j+1].name[k];
					stud[j+1].name[k]=tmp_name;
				}
				tmp_studentid=stud[j].studentid;
				stud[j].studentid=stud[j+1].studentid;
				stud[j+1].studentid=tmp_studentid;
				
				tmp_score=stud[j].score;
				stud[j].score=stud[j+1].score;
				stud[j+1].score=tmp_score;								
			}
		}	
		HMI_snput_struct("i8_20,i32_1,i16_1",sizeof(stud[i-1]),&stud[i-1]);
	}

	return 0;
}

