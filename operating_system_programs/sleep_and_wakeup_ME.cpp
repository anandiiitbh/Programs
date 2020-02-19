#include<iostream>
using namespace std;
#include<unistd.h>
#define TRUE 1
#define BUFFER_SIZE 10
int count =0, in=0, out=0,BUFFER[BUFFER_SIZE],ans=0;
void consumer(void);
int produce_item(){
	int temp;
	cout<<"\nINSERT THE NUMBER:\t";
	cin>>temp;
	return temp;
}

void producer(void){
	int next_item;
	while(TRUE){
		next_item=produce_item();
		if(count==BUFFER_SIZE)
			sleep();
		BUFFER[in]=next_item;
		in=(in+1)%BUFFER_SIZE;
		count++;
		if(count==1)
			wakeup(consumer);
	}
}

void consumer(void){
	int get_item;
	while(TRUE){
		if(count==0)
			sleep();
		get_item = BUFFER[out];
		ans=ans+get_item;
		cout<<"\n"<<ans;
		out=(out+1)%BUFFER_SIZE;
		count--;
		if(out==in){
			in=0;
			out=0;
		}
		if(count==BUFFER_SIZE-1)
			wakeup(producer);
	}
}

int main(){
	producer();
	return 0;
}
