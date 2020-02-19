#include<stdio.h>
#define MAX_NUM 99


int total_process,total_resources;
int allocation[MAX_NUM][MAX_NUM];
int _max[MAX_NUM][MAX_NUM];
int need[MAX_NUM][MAX_NUM];
int resources_available[MAX_NUM];
int res_avl[MAX_NUM];

int safty_checking(){
	int work[MAX_NUM];
	for(int i=0;i<total_resources;i++)
		work[i]=res_avl[i];
	int finish[total_process];
	for(int i=0;i<total_process;i++){
		finish[i]=0;
	}
	int k=0;
	while(k==0){
		int m=-1;
		for(int i=0;i<total_process;i++){
			int l=0;
			if(finish[i]==0){
				for(int j=0;j<total_resources;j++){
					if(need[i][j]<=work[j]){
						l+=1;
					}
				}
			}
			if(l==3){
				m=i;
				k=0;
				break;
			}
			else
				k=1;
		}
		if(k==0){
			for(int j=0;j<total_resources;j++)
				work[j]+=allocation[m][j];
			finish[m]=1;
		}
	}
	for(int i=0;i<total_process;i++){
		if(finish[i]==1);
		else
			return 0;
	}
	return 1;
}

int resource_request(){
	int x,request[MAX_NUM];
	printf("\nENTER THE PROCESS NUMBER WHICH REQUEST THE RESOURCES:\t");
	scanf("%d",&x);
	for(int i=0;i<total_resources;i++){
		printf("ENTER THE REQUEST OF RESOURCE TYPE %d:\t",i+1);
		scanf("%d",&request[i]);
	}
	for(int i=0;i<total_resources;i++){
		if(request[i]<=need[x][i]);
		else{
			printf("\nPROCESS HAS EXCEEDED IT'S MAXIMUM CLAIM\n");
			return 0;
		}
	}
	for(int i=0;i<total_resources;i++){
		if(request[i]<=res_avl[i]);
		else{
			printf("\nRESOURCES ARE NOT AVAILABLE\n");
			return 0;
		}
	}
	int avl[MAX_NUM],allo[MAX_NUM],__need[MAX_NUM];
	for(int i=0;i<total_resources;i++){
		avl[i]=res_avl[i];
		allo[i]=allocation[x][i];
		__need[i]=need[x][i];
	}
	for(int i=0;i<total_resources;i++){
		res_avl[i]-=request[i];
		allocation[x][i]+=request[i];
		need[x][i]-=request[i];
	}
	if(safty_checking()){
		printf("\nAFTER ALLOCATION OF THIS REQUEST ALL PROCESS ARE IN SAFE STATE\nDO YOU WANT TO ALLOW THIS REQUEST PERMANENTLY 1 FOR YES 0 FOR NO:\t");
		int y;
		scanf("%d",&y);
		if(!y){
			for(int i=0;i<total_resources;i++){
				res_avl[i]=avl[i];
				allocation[x][i]=allo[i];
				need[x][i]=__need[i];
			}
		}
		return 1;
	}
	else{
		printf("\nAFTER ALLOWING THIS ALL PROCESS MAY NOT BE IN A SAFE STATE\n");
		return 0;
	}
}
	

	
void insertion(){
	printf("ENTER TOTAL NUMBER OF PROCESSES:\t");
	scanf("%d",&total_process);
	printf("ENTER TOTAL NUMBER OF RESOURCE TYPES AVAILABLE:\t");
	scanf("%d",&total_resources);
	
	for(int i=0;i<total_resources;i++){		//STORING TOTAL NUMBER OF INSTANCES AVAILABLE OF EACH RESOURCE TYPE 
		printf("ENTER THE TOTAL AVAILABLE INSTANCES OF RESOURCES TYPE %d:\t",i+1);
		scanf("%d",&resources_available[i]);
		res_avl[i]=resources_available[i];
	}
	for(int i=0;i<total_process;i++){
		printf("\n\t<------ENTER THE DATA FOR PROCESS %d ------>\n",i);
		for(int j=0;j<total_resources;j++){	
			printf("ENTER THE  ALLOCATED INSTANCES OF RESOURCES TYPE %d :\t",j+1);
			scanf("%d",&allocation[i][j]);
			res_avl[j]-=allocation[i][j];
			if(res_avl[j]<0){
				printf("\nHERE ALLOCATED RESOURCES OF TYPE %d EXCEEDS THE AVAILABLE INSTANCES OF THIS TYPE",j+1);
				return;
			}
		}
		for(int j=0;j<total_resources;j++){	
			printf("ENTER THE  MAXIMUM INSTANCES OF RESOURCES TYPE %d THAT WILL BE CONSUMED BY THIS PROCESS :\t",j+1);
			scanf("%d",&_max[i][j]);
			if(resources_available[j]<_max[i][j]){
				printf("\nHERE MAX DEMAND OF RESOURCES TYPE %d EXCEEDS THE AVAILABLE INSTANCES OF THIS TYPE",j+1);
				return;
			}
		}
		for(int j=0;j<total_resources;j++){
			need[i][j]=_max[i][j]-allocation[i][j];
		}
	}
}

int main(){

	// FOR INSERTION OF ALL DATA
	insertion(); 					
	
	// FOR INITALLY SAFETY CHECKING OF INSERTED DATA
	if(safty_checking()){						
		printf("\nGIVEN DATA IS SAFE\n");
	}
	else{
		printf("\nGIVEN DATA IS NOT SAFE\n");
		return 0;
	}

	//FOR RESOURCES REQUEST BY VARIOUS PROCESSES
	while(1){
		printf("\nWANT TO REQUEST RESOURCES FOR ANY PROCESS?(PRESS 1 FOR YES OR 0 FOR NO):\t");
		int v;
		scanf("%d",&v);
		if(v){
			if(resource_request())
				printf("\nREQUEST CHECKING DONE WITHOUT ANY ERROR\n");
			else
				printf("\nERROR OCCURED\n");
		}
		else 
			return 0;
	}
	return 0;
}	


