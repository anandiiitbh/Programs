/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
		BANKER'S ALGORITHM
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*/
#include<iostream>
#define MAX_NUM 99
using namespace std;

/*
----------------------------------------------------------
----------------------------------------------------------
		VARIAVLE DECLARETION
----------------------------------------------------------
----------------------------------------------------------
*/
int total_process,total_resources;
int allocation[MAX_NUM][MAX_NUM];
int _max[MAX_NUM][MAX_NUM];
int need[MAX_NUM][MAX_NUM];
int resources_available[MAX_NUM];
int res_avl[MAX_NUM];

/*
----------------------------------------------------------
----------------------------------------------------------
		SAFETY ALGORITHM
----------------------------------------------------------
----------------------------------------------------------
*/
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


/*
----------------------------------------------------------
----------------------------------------------------------
		RESOURCE-REQUEST ALGORITHM
----------------------------------------------------------
----------------------------------------------------------
*/
int resource_request(){
	int x,request[MAX_NUM];
	cout<<"\nENTER THE PROCESS NUMBER WHICH REQUEST THE RESOURCES:\t";
	cin>>x;
	for(int i=0;i<total_resources;i++){
		cout<<"ENTER THE REQUEST OF RESOURCE TYPE "<<i+1<<":\t";
		cin>>request[i];
	}
	for(int i=0;i<total_resources;i++){
		if(request[i]<=need[x][i]);
		else{
			cout<<"\nPROCESS HAS EXCEEDED IT'S MAXIMUM CLAIM\n";
			return 0;
		}
	}
	for(int i=0;i<total_resources;i++){
		if(request[i]<=res_avl[i]);
		else{
			cout<<"\nRESOURCES ARE NOT AVAILABLE\n";
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
		cout<<"\nAFTER ALLOCATION OF THIS REQUEST ALL PROCESS ARE IN SAFE STATE\nDO YOU WANT TO ALLOW THIS REQUEST PERMANENTLY 1 FOR YES 0 FOR NO:\t";
		int y;
		cin>>y;
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
		cout<<"\nAFTER ALLOWING THIS ALL PROCESS MAY NOT BE IN A SAFE STATE\n";
		return 0;
	}
}
	

	
/*
----------------------------------------------------------
----------------------------------------------------------
		ALL DATA INSERTION
----------------------------------------------------------
----------------------------------------------------------
*/

void insertion(){
	cout<<"ENTER TOTAL NUMBER OF PROCESSES:\t";
	cin>>total_process;
	cout<<"ENTER TOTAL NUMBER OF RESOURCE TYPES AVAILABLE:\t";
	cin>>total_resources;
	
	for(int i=0;i<total_resources;i++){		//STORING TOTAL NUMBER OF INSTANCES AVAILABLE OF EACH RESOURCE TYPE 
		cout<<"ENTER THE TOTAL AVAILABLE INSTANCES OF RESOURCES TYPE "<<i+1<<" :\t";
		cin>>resources_available[i];
		res_avl[i]=resources_available[i];
	}
	for(int i=0;i<total_process;i++){
		cout<<"\n\t<------ENTER THE DATA FOR PROCESS "<<i<<" ------>\n";
		for(int j=0;j<total_resources;j++){	
			cout<<"ENTER THE  ALLOCATED INSTANCES OF RESOURCES TYPE "<<j+1<<" :\t";
			cin>>allocation[i][j];
			res_avl[j]-=allocation[i][j];
			if(res_avl[j]<0){
				cout<<"\nHERE ALLOCATED RESOURCES OF TYPE "<<j+1<<" EXCEEDS THE AVAILABLE INSTANCES OF THIS TYPE";
				return;
			}
		}
		for(int j=0;j<total_resources;j++){	
			cout<<"ENTER THE  MAXIMUM INSTANCES OF RESOURCES TYPE "<<j+1<<" THAT WILL BE CONSUMED BY THIS PROCESS :\t";
			cin>>_max[i][j];
			if(resources_available[j]<_max[i][j]){
				cout<<"\nHERE MAX DEMAND OF RESOURCES TYPE "<<j+1<<" EXCEEDS THE AVAILABLE INSTANCES OF THIS TYPE";
				return;
			}
		}
		for(int j=0;j<total_resources;j++){
			need[i][j]=_max[i][j]-allocation[i][j];
		}
	}
}

/*
----------------------------------------------------------
----------------------------------------------------------
		     MAIN FUNCTION
----------------------------------------------------------
----------------------------------------------------------
*/

int main(){

	// FOR INSERTION OF ALL DATA
	insertion(); 					
	
	// FOR INITALLY SAFETY CHECKING OF INSERTED DATA
	if(safty_checking()){						
		cout<<"\nGIVEN DATA IS SAFE\n";
	}
	else{
		cout<<"\nGIVEN DATA IS NOT SAFE\n";
		return 0;
	}

	//FOR RESOURCES REQUEST BY VARIOUS PROCESSES
	while(1){
		cout<<"\nWANT TO REQUEST RESOURCES FOR ANY PROCESS?(PRESS 1 FOR YES OR 0 FOR NO):\t";
		int v;
		cin>>v;
		if(v){
			if(resource_request())
				cout<<"\nREQUEST CHECKING DONE WITHOUT ANY ERROR\n";
			else
				cout<<"\nERROR OCCURED\n";
		}
		else 
			return 0;
	}
	return 0;
}	

/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
-----------------------------------------------------------------------END-----------------------------------------------------------------------
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	
*/

