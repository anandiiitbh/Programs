#include<iostream>
using namespace std;
struct process{
	int at,bt,ct,tat,wt,ch=0;
}pro[99];



int main(){
	int tp;
	cout<<"ENTER THE "<<"NUMBER OF PROCESS"<<" YOU WANT TO ENTER\n";
	cin>>tp;
	for(int i=0;i<tp;i++){
		cout<<"ENTER ARRIVAL TIME OF PROCESS "<<i+1<<" \n";
		cin>>pro[i].at;
		cout<<"ENTER BRUST TIME OF PROCESS "<<i+1<<" \n";
		cin>>pro[i].bt;
	}
	int cti=1;
	for(int j=0;j<tp;j++){
		int min=99,k;
		for(int i=0;i<tp;i++){
			if(pro[i].at<=cti && pro[i].ch==0){
			       	if(pro[i].at<min){
					min=pro[i].at;k=i;}}
		}
		cti=cti+pro[k].bt;pro[k].ct=cti;pro[k].ch=1;
	}
	float atat=0,awt=0;
	for(int i=0;i<tp;i++){
		pro[i].tat=pro[i].ct-pro[i].at;atat=atat+pro[i].tat;
	}
	for(int i=0;i<tp;i++){
		pro[i].wt=pro[i].tat-pro[i].bt;awt=awt+pro[i].wt;
	}
	cout<<"\nPROCESS"<<"\t| "<<"AT"<<"\t| "<<"BT"<<"\t| "<<"CT"<<"\t| "<<"TAT"<<"\t| "<<"WT"<<"\t|";
	for(int i=0;i<tp;i++){
		cout<<"\nP"<<i+1<<"\t| "<<pro[i].at<<"\t| "<<pro[i].bt<<"\t| "<<pro[i].ct<<"\t| "<<pro[i].tat<<"\t| "<<pro[i].wt<<"\t|";
	}
	cout<<"\n\nAVERAGE TURN AROUND TIME:\t"<<atat/tp;
	cout<<"\nAVERAGE WAITING TIME:\t"<<awt/tp<<"\n";
			
	return 0;
}
