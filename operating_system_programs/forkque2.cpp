#include<iostream>
#include<unistd.h>
using namespace std;
void pro(){

	if(fork()==0){
		cout<<"\n\nPARENT(INIT) :\t"<<getppid()<<"\tCHILD(LOGIN) :\t"<<getpid()<<endl;
		if(fork()==0){
			cout<<"\n\nPARENT(login) :\t"<<getppid()<<"\tCHILD(BASH) :\t"<<getpid()<<endl;
			if(fork()==0){
				cout<<"\n\nPARENT(bash) :\t"<<getppid()<<"\tCHILD(ps) :\t"<<getpid()<<endl;
			exit(0);}
			if(fork()==0){
				cout<<"\n\nPARENT(bash) :\t"<<getppid()<<"\tCHILD(emacs) :\t"<<getpid()<<endl;
			exit(0);}exit(0);
		}exit(0);
	}
	if(fork()==0){
		cout<<"\n\nPARENT(INIT) :\t"<<getppid()<<"\tCHILD(KTHREAD) :\t"<<getpid()<<endl;
		if(fork()==0){
			cout<<"\n\nPARENT(KTHREAD) :\t"<<getppid()<<"\tCHILD(KHELPER) :\t"<<getpid()<<endl;
		exit(0);}
		if(fork()==0){
			cout<<"\n\nPARENT(KTHREAD) :\t"<<getppid()<<"\tCHILD(PDHELPER) :\t"<<getpid()<<endl;
		exit(0);}exit(0);
	}
	if(fork()>0){
		cout<<"\n\nPARENT(INIT) :\t"<<getppid()<<"\tCHILD(SSHD) :\t"<<getpid()<<endl;
		if(fork()==0){
			cout<<"\n\nPARENT(KTHREAD) :\t"<<getppid()<<"\tCHILD(TESCH) :\t"<<getpid()<<endl;
		}exit(0);
	}exit(0);
}
int main(){
	pro();
	return 0;
}


