#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
void *fact(void *arg1){
	int y=1,x=atoi(arg1);
	for(int i=1;i<=x;i++)
		y=y*i;
	printf("\nFACTORIAL OF THE NUMBER IS:\t%d",y);	
}

int fi(int n){
	    if((n==1)||(n==0)){
		return(n);
	    }
	    else{
		    return(fi(n-1)+fi(n-2));
	    }
}

void *fib(void *arg2){
	int y=atoi(arg2);
	printf("\nFIBONACCI SERIES:\n");
	for(int i=0;i<y;i++){
		int u=fi(i);
		printf(" %d",u);
	}
}

void *pal(void *arg3){
	int y=atoi(arg3);
	int temp=y,rev=0;
	while(temp!=0){
		rev=(rev*10)+(temp%10);
		temp=temp/10;
	}
	if(rev==y)
		printf("\nNUMBER IS PALINDROME");
	else
		printf("\nNUMBER IS NOT PALINDROME");
}
 
int main(int argc , char *argv[]){
	/*int y=atoi(argv[1]);
	if(y!=0){
		printf("INSERT A NUMBER IN COMMAND LINE ARGUMENT GREATER THAN 0");
		return 0;
	}*/
	pthread_t kill,kill1,kill2;
	pthread_create(&kill,NULL,fact,argv[1]);sleep(5);
	pthread_create(&kill1,NULL,fib,argv[1]);
	pthread_create(&kill2,NULL,pal,argv[1]);
	pthread_exit(0);
}
