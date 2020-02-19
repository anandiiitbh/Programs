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
int arr[MAX_NUM];
void init(int x){
	for(int i=0;i<x;i++)
		arr[i] = rand()%1000;
}

void insertion(int x,int y){
	for(int i=0;i<number_of_frames;i++){
		if(frame[i].ref_num==-1){
			frame[i].ref_num=x;
			frame[i].position=0;
			return;
		}
	}
	for(int i=0;i<number_of_frames;i++){
		int count=0;
		for(int j=y;j<len_reference_string;j++){
			if(arr[j]==frame[i].ref_num){
				count++;
				frame[i].position=count;
			}
		}
	}
	int min=9999,k;
	for(int i=0;i<number_of_frames;i++){
		if(frame[i].position<min){
			k=i;min=frame[i].position;
		}
	}
	frame[k].ref_num=x;
	frame[k].position=0;
	return;
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
		if(frame[i].position>=0)
			printf("%d ",frame[i].ref_num);
	}
	printf("\n");
}



int main(){
	printf("ENTER THE LENGTH OF REFERENCE STRING :\t");
	scanf("%d",&len_reference_string);
	printf("ENTER THE NUMBER OF FRAMES TO BE ALLOCATED:\t");
	scanf("%d",&number_of_frames);
	init(len_reference_string);
	for(int i=0;i<len_reference_string;i++){
		int reference_number = arr[i];
		if(!hits(reference_number))
			insertion(reference_number,i);
		display(reference_number);
	}
	printf("\nTOTAL HITS:\t%d",total_hit);
	printf("\nTOTAL MISS:\t%d\n",total_miss);
	return 0;
}


