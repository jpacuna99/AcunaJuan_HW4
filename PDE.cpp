#include<iostream>
#include<stdio.h>
#include<cmath> 
#include<fstream>
using namespace std;

int N=50;

float k=1.62;
float Cp=820.;
float rho=2710.;
float nu=k/(Cp*rho);
void condicionesInciales(float nu0, int N0);
float deltax =0.01;
float TV =100.0;
float deltat= 0.5*deltax/nu;


void primerpaso(float L0, float A0, int N0);

void resolverNormal(float L0, float A0, int N0);
void resolverPeriodico(float L0, float A0, int N0);
void resolverExtremo(float L0, float A0, int N0);
float rocaP[N][N];
float rocaN[N][N];
float rocaF[N][N];




int main()
{
	condicionesInciales( L,  A,  N); 
	primerpaso( L, A,  N);
	resolverNormal(L, A, N);

	condicionesInciales( L,  A,  N); 
	primerpaso( L, A,  N);
	resolverPeriodico(L, A, N);

	condicionesInciales( L,  A,  N); 
	primerpaso( L, A,  N);
	resolverExtremo(L, A, N);


	return 0;
}




float distancia(float x1, float y1,float x2 ,float y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));


}


void condicionesInciales(float nu0, int N0)
{
	
	for(int i=0;i<N0;i++)
	{
		for(int j=0;j<N0;j++)
		{
			if(distancia(25.,25.,float(i),float(j))<5.0)
			{
				float rocaP[i][j]=100;	
			}
			else
			{
				rocaP=10.;
			}

		}	


	} 
	ofstream f;
	f.open("condicionesI.txt");
	for(int i=1;i<N0;i++)
	{
		for(int j=0;j<N0;j++)
		{
			f<<rocaN[i][j]<<",";
		}
		f<<endl;
	}
	f.close();


}



void primerpaso(float nu0, int N0)
{

	cuerdaN[0]=0.;
	for(int i=1;i<N0+1;i++)
	{
		rocaN[i]=0.5*((c*c*deltat*deltat)/(deltax*deltax))*(cuerdaP[i+1]+cuerdaP[i-1]-2.0*cuerdaP[i])+cuerdaP[i];
	}

	
	ofstream f;
	f.open("primerpaso.txt");
	for(int i=1;i<N0;i++)
	{
		f<<cuerdaN[i]<<","<<i<<endl;
		
	}
	f.close();
	
}

/*

void resolverNormal(float L0, float A0, int N0)
{


	for(int j= 1;j<80;j++)
	{
		for(int i=1; i<N0;i++){
			cuerdaF[i]=(c*c*deltat*deltat)/(deltax*deltax)*(cuerdaN[i+1]+cuerdaN[i-1]-2*cuerdaN[i])- cuerdaP[i] +2*cuerdaN[i];
		}
		
		for(int i=1; i<N0;i++){
			cuerdaP[i]=cuerdaN[i];
			cuerdaN[i]=cuerdaF[i];
			
		}
		cuerdaN[99]=0.;
		


		
	}



	ofstream f;
	f.open("normal.txt");
	for(int i=1;i<N0;i++)
	{
		f<<cuerdaN[i]<<","<<i<<endl;
		
	}
	f.close();

	
}



void resolverExtremo(float L0, float A0, int N0)
{


	for(int j= 1;j<80;j++)
	{
		for(int i=1; i<N0;i++){
			cuerdaF[i]=(c*c*deltat*deltat)/(deltax*deltax)*(cuerdaN[i+1]+cuerdaN[i-1]-2*cuerdaN[i])- cuerdaP[i] +2*cuerdaN[i];
		}
		
		for(int i=1; i<N0;i++){
			cuerdaP[i]=cuerdaN[i];
			cuerdaN[i]=cuerdaF[i];
			
		}
		cuerdaN[99]=cuerdaN[98];
		


		
	}



	ofstream f;
	f.open("extremo.txt");
	for(int i=1;i<N0;i++)
	{
		f<<cuerdaN[i]<<","<<i<<endl;
		
	}
	f.close();

	
}

void resolverPeriodico(float L0, float A0, int N0)
{


	for(int j= 1;j<80;j++)
	{
		for(int i=1; i<N0;i++){
			cuerdaF[i]=(c*c*deltat*deltat)/(deltax*deltax)*(cuerdaN[i+1]+cuerdaN[i-1]-2*cuerdaN[i])- cuerdaP[i] +2*cuerdaN[i];
		}
		
		for(int i=1; i<N0;i++){
			cuerdaP[i]=cuerdaN[i];
			cuerdaN[i]=cuerdaF[i];
			
		}
		cuerdaN[99]=0.1*cos(3.0*300*j*3.1415926);
		


		
	}



	ofstream f;
	f.open("periodico.txt");
	for(int i=1;i<N0;i++)
	{
		f<<cuerdaN[i]<<","<<i<<endl;
		
	}
	f.close();

	
}
*/


