#include<iostream>

using namespace std;
struct process{
	int at,bt,bt1,ct,tat,wt,ch=0;
}pro[99];



int main(){
	int tp,tq,tbt=0;
	cout<<"ENTER THE NUMBER OF PROCESS YOU WANT TO ENTER\n";
	cin>>tp;
	cout<<"ENTER THE TIME QUANTUM\n";
	cin>>tq;
	

	for(int i=0;i<tp;i++){
		cout<<"ENTER ARRIVAL TIME OF PROCESS "<<i+1<<" \n";
		cin>>pro[i].at;
		cout<<"ENTER BRUST TIME OF PROCESS "<<i+1<<" \n";
		cin>>pro[i].bt;tbt=tbt+pro[i].bt;pro[i].bt1=pro[i].bt;
	}
	int cti=2,j=0,k=0,l=0,u=0,arr[tbt];cout<<"\n QUEUE ::: ";
	while(j<tbt){
		
		for(int i=0;i<tp;i++){
			if(pro[i].at<=cti && pro[i].ch==0){
				arr[k]=i;k++;pro[i].ch=1;      	
			}
		}
		if(l>0 && pro[arr[l-1]].bt!=0 ){
			arr[k]=arr[l-1];k++;
		}
	       	
		int m=0;
		while(m<tq){
			if(pro[arr[l]].bt!=0){
				cti=cti+1;
				pro[arr[l]].ct=cti;
				pro[arr[l]].bt=pro[arr[l]].bt-1;++j;
			}m++;
		}
		cout<<" P"<<arr[u]+1;u++;
		l++;
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
