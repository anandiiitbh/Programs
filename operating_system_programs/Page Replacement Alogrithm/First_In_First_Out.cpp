/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
		FIRST IN FIRST OUT : PAGE REPLACEMENT ALGORITHM
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/

#include<iostream>
#define MAX_NUM 99
using namespace std;
/*****************************************************************************
			STRUCTURES AND VARIABLES
 *****************************************************************************/
struct frames{
	int ref_num=-1;
	int position=-1;
}frame[MAX_NUM];
int number_of_frames;
int total_hit=0,total_miss=0;
int reference_number;
int len_reference_string;

/*****************************************************************************
		    INSERTION OF REFERENCE NUMBER INTO FRAMES
*****************************************************************************/

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

/*****************************************************************************
			CHECKING FOR HITS INTO FRAMES
*****************************************************************************/

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

/*****************************************************************************
				DISPLAY FUNCTION
*****************************************************************************/
void display(int x){
	cout<<x<<" :\t";
	for(int i=0;i<number_of_frames;i++){
		if(frame[i].position>0)
			cout<<frame[i].ref_num<<"  ";
	}
	cout<<endl;
}

/*****************************************************************************
				MAIN FUNCTION
*****************************************************************************/	

int main(){
	cout<<"ENTER THE LENGTH OF REFERENCE STRING :\t";
	cin>>len_reference_string;
	cout<<"ENTER THE NUMBER OF FRAMES TO BE ALLOCATED:\t";
	cin>>number_of_frames;
	for(int i=0;i<len_reference_string;i++){
		int reference_number = rand()%10;
		if(!hits(reference_number))
			insertion(reference_number);
		display(reference_number);
	}
	cout<<"\nTOTAL HITS:\t"<<total_hit;
	cout<<"\nTOTAL MISS:\t"<<total_miss<<endl;
	return 0;
}
/*****************************************************************************
				END OF THE PROGRAM
*****************************************************************************/

