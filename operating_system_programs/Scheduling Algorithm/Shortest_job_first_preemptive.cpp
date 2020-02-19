#include<iostream>
using namespace std;
struct process{
	int at,bt,bt1,ct,tat,wt;
}pro[99];



int main(){
	int tp,tbt=0;
	cout<<"ENTER THE "<<"NUMBER OF PROCESS"<<" YOU WANT TO ENTER\n";
	cin>>tp;
	for(int i=0;i<tp;i++){
		cout<<"ENTER ARRIVAL TIME OF PROCESS "<<i+1<<" \n";
		cin>>pro[i].at;
		cout<<"ENTER BRUST TIME OF PROCESS "<<i+1<<" \n";
		cin>>pro[i].bt;tbt=tbt+pro[i].bt;pro[i].bt1=pro[i].bt;
	}
	int cti=0; //INITALLY CLOCK TIME TAKEN
	for(int j=0;j<tbt;j++){
		int min=99,k;
		for(int i=0;i<tp;i++){
			if(pro[i].at<=cti && pro[i].bt!=0 && pro[i].bt<min){
					min=pro[i].bt;k=i;}
		}
		cti=cti+1;pro[k].ct=cti;pro[k].bt=pro[k].bt-1;
	}
	float atat=0,awt=0;
	for(int i=0;i<tp;i++){
		pro[i].tat=pro[i].ct-pro[i].at;atat=atat+pro[i].tat;
	}
	for(int i=0;i<tp;i++){
		pro[i].wt=pro[i].tat-pro[i].bt1;awt=awt+pro[i].wt;
	}
	cout<<"\nPROCESS"<<"\t| "<<"AT"<<"\t| "<<"BT"<<"\t| "<<"CT"<<"\t| "<<"TAT"<<"\t| "<<"WT"<<"\t|";
	for(int i=0;i<tp;i++){
		cout<<"\nP"<<i+1<<"\t| "<<pro[i].at<<"\t| "<<pro[i].bt1<<"\t| "<<pro[i].ct<<"\t| "<<pro[i].tat<<"\t| "<<pro[i].wt<<"\t|";
	}
	cout<<"\n\nAVERAGE TURN AROUND TIME:\t"<<atat/tp;
	cout<<"\nAVERAGE WAITING TIME:\t"<<awt/tp<<"\n";
			
	return 0;
}
