#include <graphics.h> 
#include<bits/stdc++.h>
#include<ctime>
using namespace std;
int root=270;
int X_clk_center = 250; 
int Y_clk_center = 250;
int start_angle = 270; 
int end_angle = 270; 
int hr,min,sec;

void circ_b(int rad, int thick){
	setcolor(BLACK);
	for(int i=rad-(thick/2);i<rad+(thick/2);i++){
		arc(X_clk_center,Y_clk_center, start_angle, (start_angle+360), i); 
		
	} 
}

void circ(int rad,int e_angle,int col, int thick){
	setcolor(col);
	for(int i=rad-(thick/2);i<rad+(thick/2);i++){
		arc(X_clk_center,Y_clk_center, start_angle, e_angle, i); 
		
	} 
	
}

void lino(int rad,int e_angle,int col){
	setcolor(col);
	for(int i=-1;i<rad;i++){
		arc(X_clk_center,Y_clk_center, e_angle-1, e_angle+1, i); 
		
	} 
	
}

int main() 
{ 
	int gd = DETECT, gm;
	
	 
	int rad = 130; int sec1=0,min1=0,hr1=0;
	 initgraph(&gd, &gm, NULL);

	int i=270,j=i+3,k=i+6;
	while(i<=270+360){
		circ(rad-10,k,RED, 4);
		lino(rad-35,k,RED);
		lino(rad-35,k,BLACK);
		circ(rad-5,j,YELLOW, 4);
		lino(rad-25,j,YELLOW);
		lino(rad-25,j,BLACK);
		circ(rad,i,GREEN, 4);
		lino(rad-15,i,GREEN);
		lino(rad-15,i,BLACK);
		i++;j++;k++;
	}
		
		
	circ_b(rad,4);
	circ_b(rad-5,4);
	circ_b(rad-10,4);
	while(1){		
		time_t now =time(0);
		tm *ltm = localtime(&now);
		int sec =root+ 6*(ltm->tm_sec?ltm->tm_sec:60),
		min =root+ 6*(ltm->tm_min?ltm->tm_min:60),
		hour =root+ 30*((ltm->tm_hour)%12?(ltm->tm_hour)%12:12);
		if(sec!=sec1){
			lino(rad-15,sec1,BLACK);
			lino(rad-15,sec,GREEN);			
			lino(rad-25,min,YELLOW);
			lino(rad-35,hour,RED);
			circ(rad,sec,GREEN, 4);
			if(sec-root==360){
				delay(300);
				circ_b(rad,4);
			}sec1=sec;
			
		}
		
		if(min!=min1){
			lino(rad-25,min1,BLACK);
			if(min-root==6){
				delay(100);
				circ_b(rad-5,4);
			}
			circ(rad-5,min,YELLOW, 4);
			min1=min;
		}
		
		if(hour!=hr1){
			lino(rad-35,hr1,BLACK);
			
			if(hour-root==30){
				delay(100);
				circ_b(rad-10,4);
			}
			circ(rad-10,hour,RED, 4);
			hr1=hour;
		}
		
	}
		
	closegraph(); 
	return 0; 
} 
