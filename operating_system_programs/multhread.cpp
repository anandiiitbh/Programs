#include<iostream>
#include <pthread.h>
using namespace std;

void *hello(){
	cout<<"\nHI THIS IS MULTITHREAD PROGRAM: YOU ARE INSIDE THREAD\n";
}

int main(){
	cout<<"\nINSIDE MAIN FUNCTION\n";
	pthread_t hell;
	pthread_create(&hell,NULL,hello,NULL);
	pthread_exit(0);
	return 0;
}
