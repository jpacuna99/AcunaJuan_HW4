#include<iostream>
#include<stdio.h>
#include<cmath>
#include<fstream>
using namespace std;



void paso(float theta);

float m=0.2;
float c=0.2;
float g=10;
float v=300;
float k=c/m;
float vx[2000];
float vy[2000];
float x[2000];
float y[2000];
int main()
{	
	paso(45.);
	for(int i=1; i<8;i++)
	{	
		paso(i*10*3.1415926/180.);
	}
	return 0;
}





void paso(float theta)
{	ofstream f;

	
	float t=0;
	
	
	float deltat = 0.001;
	vx[0]=v*cos(theta)-deltat*(-v*cos(theta)*k*sqrt(v*sin(theta)*v*sin(theta)+v*cos(theta)*v*cos(theta)))/2.;
	vy[0]=v*sin(theta)-deltat*(-10.-v*sin(theta)*k*sqrt(v*sin(theta)*v*sin(theta)+v*cos(theta)*v*cos(theta)))/2.;
	
	x[0]=0.;
	y[0]=0.;
	

	
	

	for(int i=1; i<2000; i++)
	{
		t= t+deltat;
		vy[i]= vy[i-1]+2*deltat*(-10.-vy[i-1]*k*sqrt((vy[i-1]*vy[i-1])+(vx[i-1]*vx[i-1])));
		vx[i]=vx[i-1]+2*deltat*(-vx[i-1]*k*sqrt((vy[i-1]*vy[i-1])+(vx[i-1]*vx[i-1])));
		x[i]= x[i-1]+vx[i-1]*deltat;
		y[i]= y[i-1]+vy[i-1]*deltat;
		
		
	}
	
	f.open("45.txt", fstream::app);
	for(int i=0;i<2000;i++)
	{
		f<<x[i]<<" "<<y[i]<<endl;
	}
	f.close();
	

}
