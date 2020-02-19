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
	int min=99;
	for(int i=0;i<tp;i++)
		if(pro[i].at<min)
			min=pro[i].at; //finding initial clock time
	int cti=min,k;
	for(int i=0;i<tbt;i++){int pri=-1;
		for(int j=0;j<tp;j++){
			if(pro[j].at<=cti && pro[j].pr>pri && pro[j].bt!=0){
				k=j;pri=pro[j].pr;
			}
		}
		for(int v=0;v<tp;v++)	
			if(v!=k && pro[v].at<=cti)
				pro[v].pr+=1;		//process waiting in ready queue dynamicall increase their priority by 1
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


