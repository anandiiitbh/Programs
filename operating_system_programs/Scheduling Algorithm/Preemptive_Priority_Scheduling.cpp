#include<iostream>
using namespace std;

struct process{
	int at,bt,bt1,pr,ct,tat,wt;
}pro[99];

int main(){
	int tp,tbt=0;
	cout<<"ENTER NO OF PROCESS YOU WANT TO ENTER\n";
	cin>>tp;
	for(int i=0;i<tp;i++){
		cout<<"ENTER THE ARRIVAL TIME OF PROCESS "<<i+1<<"\n";
		cin>>pro[i].at;
		cout<<"ENTER THE BRUST TIME OF PROCESS "<<i+1<<endl;
                cin>>pro[i].bt;tbt=tbt+pro[i].bt;pro[i].bt1=pro[i].bt;
		cout<<"ENTER THE PRIORITY OF THE PROCESS "<<i+1<<endl;
		cin>>pro[i].pr;
	}
	int cti=1,k;
	for(int i=0;i<tbt;i++){int pri=99;
		for(int j=0;j<tp;j++){
			if(pro[j].at<=cti && pro[j].pr<pri && pro[j].bt!=0){
				k=j;pri=pro[j].pr;
			}
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
	cout<<"PROCESS\t| AT\t| BT\t| PRIO\t| CT\t| TAT\t| WT\t|";
	for(int i=0;i<tp;i++){
		cout<<"\n P"<<i+1<<"\t| "<<pro[i].at<<"\t| "<<pro[i].bt1<<"\t| "<<pro[i].pr<<"\t| "<<pro[i].ct<<"\t| "<<pro[i].tat<<"\t| "<<pro[i].wt<<"\t|";
	}
	cout<<"\nAVERAGE TAT: "<<atat/tp;
	cout<<"\nAVERAGE WT: "<<awt/tp;
	return 0;
}


