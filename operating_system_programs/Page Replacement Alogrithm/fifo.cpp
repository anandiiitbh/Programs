#include<stdio.h>
#include<stdlib.h>
#define MAX_NUM 1000
struct frames{
	int ref_num=-1;
	int position=-1;
}frame[MAX_NUM];
int number_of_frames;
int total_hit=0,total_miss=0;
int reference_number;
int len_reference_string;


void insertion(int x){
	for(int i=0;i<number_of_frames;i++)
		frame[i].position-=1;
	for(int i=0;i<number_of_frames;i++){
		if(frame[i].ref_num==-1){
			frame[i].ref_num=x;
			frame[i].position=number_of_frames;
			return;
		}
	}
	for(int i=0;i<number_of_frames;i++){
		if(frame[i].position<1){
			frame[i].ref_num=x;
			frame[i].position=number_of_frames;
			return;
		}
	}
}


int hits(int x){
	for(int i=0;i<number_of_frames;i++){
		if(frame[i].ref_num==x){
			total_hit+=1;
			return 1;
		}
	}
	total_miss+=1;
	return 0;
}


void display(int x){
	printf("%d:\t",x);
	for(int i=0;i<number_of_frames;i++){
		if(frame[i].position>0)
			printf("%d ",frame[i].ref_num);
	}
	printf("\n");
}



int main(){
	printf("ENTER THE LENGTH OF REFERENCE STRING :\t");
	scanf("%d",&len_reference_string);
	printf("ENTER THE NUMBER OF FRAMES TO BE ALLOCATED:\t");
	scanf("%d",&number_of_frames);
	for(int i=0;i<len_reference_string;i++){
		printf("ENTER THE REFERENCE:\t");
		scanf("%d",&reference_number);		
		//int reference_number = rand()%1000;
		if(!hits(reference_number))
			insertion(reference_number);
		display(reference_number);
	}
	printf("\nTOTAL HITS:\t%d",total_hit);
	printf("\nTOTAL MISS:\t%d\n",total_miss);
	return 0;
}


