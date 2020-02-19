#include<iostream>
using namespace std;

struct process{
	int at,bt,pr,ct,tat,wt,ch=0;
}pro[99];

int main(){
	int tp;
	cout<<"ENTER NO OF PROCESS YOU WANT TO ENTER\n";
	cin>>tp;
	for(int i=0;i<tp;i++){
		cout<<"ENTER THE ARRIVAL TIME OF PROCESS "<<i+1<<"\n";
		cin>>pro[i].at;
		cout<<"ENTER THE BRUST TIME OF PROCESS "<<i+1<<endl;
                cin>>pro[i].bt;
		cout<<"ENTER THE PRIORITY OF THE PROCESS "<<i+1<<endl;
		cin>>pro[i].pr;
	}
	int cti=0,k;
	for(int i=0;i<tp;i++){
		int min=99;
		for(int j=0;j<tp;j++){
			if(pro[j].at<=cti && pro[j].pr<min && pro[j].ch == 0){
				k=j;min=pro[j].pr;
			}
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
	cout<<"PROCESS\t| AT\t| BT\t| PRIO\t| CT\t| TAT\t| WT\t|";
	cout<<"\n";
	for(int k=0;k<7;k++)
		cout<<" ------ ";
	for(int i=0;i<tp;i++){
		cout<<"\n P"<<i+1<<"\t| "<<pro[i].at<<"\t| "<<pro[i].bt<<"\t| "<<pro[i].pr<<"\t| "<<pro[i].ct<<"\t| "<<pro[i].tat<<"\t| "<<pro[i].wt<<"\t|";
	}
	cout<<"\nAVERAGE TAT: "<<atat/tp;
	cout<<"\nAVERAGE WT: "<<awt/tp;
	return 0;
}


