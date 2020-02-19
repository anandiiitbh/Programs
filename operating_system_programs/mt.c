#include<stdio.h>
#include <stdlib.h>
#include <pthread.h>


void *hello(){
	printf("\nHI THIS IS MULTITHREAD PROGRAM: YOU ARE INSIDE THREAD\n");
}

int main(){
	printf("\nINSIDE MAIN FUNCTION\n");
	pthread_t hell;
	pthread_create(&hell,NULL,hello,NULL);
	pthread_exit(0);
}
