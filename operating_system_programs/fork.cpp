#include<iostream>
#include<unistd.h>
using namespace std;

int fibonacci(int n);
int factorial(int n);
void forkki(int n){int y;
	
	if(fork()==0){
		if(n%2==0){ cout<<"FIBO :\t";
			for(int i=0;i<n;i++){
				y=fibonacci(i);
				cout<<" "<<y;
			}
		}
		else{
			y=factorial(n);
		        cout<<"\n FACTORIAL :\t"<<y;
		}
	}
	
}

int factorial(int n){   
	if(n<0)    
		return(-1);       
	if(n==0)    
		return(1);    
	else    
	{    
		return(n*factorial(n-1));        
	}
}

int fibonacci(int n){
	    if((n==1)||(n==0)){
		return(n);
	    }
	    else{
		    return(fibonacci(n-1)+fibonacci(n-2));
	    }
}




int main(){
	int x;
	cout<<"ENTER A NUMBER";
	cin>>x;
	forkki(x);
	return 0;
}
