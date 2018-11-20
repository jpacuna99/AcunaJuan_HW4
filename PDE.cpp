#include<iostream>
#include<stdio.h>
#include<cmath> 
#include<fstream>
using namespace std;

const int N=50;

float k=1.62;
float Cp=820.;
float rho=2710.;
float nu=k/(Cp*rho);

float deltax =10;
float deltay=10;
float TV =100.0;
float deltat= 0.5*deltax/nu;

float rocaN[N][N];
float rocaF[N][N];

int const cont1=3000;
int const cont2=6500;
void condicionesInciales(float nu0, int N0);
void resolverNormal(float nu0, int N0);
void resolverAbierto(float nu0, int N0);
void resolverPeriodico(float nu0, int N0);



int main()
{
	condicionesInciales(nu,N);
	resolverNormal(nu,N);

	condicionesInciales(nu,N);
	resolverAbierto( nu, N);

	condicionesInciales(nu,N);
	resolverPeriodico( nu, N);


	return 0;
}




float distancia(float x1, float y1,float x2 ,float y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));


}


void condicionesInciales(float nu0, int N0)
{
	ofstream f;
	
	
	for(int i=0;i<N0;i++)
	{
		for(int j=0;j<N0;j++)
		{
			float e=float(i);
			float m=float(j);
		

			if(distancia((float(N0)/2.)-1.,(float(N0)/2.)-1.,m,e)<=5.0)
			{
				rocaN[i][j]=100;	
			}
			else
			{
				rocaN[i][j]=10.;
			}

		}	


	} 
	f.open("condicionesI.txt");
	for(int i=0;i<N0;i++)
	{
		for(int j=0;j<N0;j++)
		{
			f<<rocaN[i][j]<<" ";
		}
		f<<endl;
	}
	f.close();


}



void resolverNormal(float nu0, int N0)
{	
	ofstream f;
	for(int l=1;l<1000;l++)
	{
	
	for(int i=1;i<N0+1;i++)
	{
		for(int j=0;j<N0;j++)
		{
			float o=float(i);
			float m=float(j);
		


		if(distancia((float(N0)/2.)-1.,(float(N0)/2.)-1.,m,o)>5.0)
			{
			rocaF[i][j]=(nu0*deltat/(deltax*deltax))*(rocaN[i+1][j]+rocaN[i-1][j]-2.0*rocaN[i][j])+(nu0*deltat/(deltay*deltay))*(rocaN[i][j+1]+rocaN[i][j-1]-2.0*rocaN[i][j])+rocaN[i][j];
					
			}
			else
			{
				
			rocaF[i][j]=100.;
			rocaN[i][j]=100.;
			}

		rocaF[0][j]=10.;
		rocaF[i][0]=10.;
		rocaF[i][49]=10.;
		rocaF[49][j]=10.;
		
		rocaN[i][j]=rocaF[i][j];
		
		}

	}
	
	if(l==cont1)
	{
	f.open("NormalInt1.txt");
	for(int i=0;i<N0;i++)
	{
		for(int j=0;j<N0;j++)
		{
			f<<rocaN[i][j]<<" ";
		}
		f<<endl;
	}
	f.close();
		
	}
	
	if(l==cont2)
	{
	f.open("NormalInt2.txt");
	for(int i=0;i<N0;i++)
	{
		for(int j=0;j<N0;j++)
		{
			f<<rocaN[i][j]<<" ";
		}
		f<<endl;
	}
	f.close();
	

	}
}



	
	
	f.open("Normalfinal.txt");
	for(int i=0;i<N0;i++)
	{
		for(int j=0;j<N0;j++)
		{
			f<<rocaN[i][j]<<" ";
		}
		f<<endl;
	}
	f.close();
	

}


void resolverAbierto(float nu0, int N0)
{
	ofstream f;
	for(int k= 1;k<10000;k++)
	{
	
	for(int i=1;i<N0+1;i++)
	{
		for(int j=0;j<N0;j++)
		{
			float o=float(i);
			float m=float(j);
		

		if(distancia((float(N0)/2.)-1.,(float(N0)/2.)-1.,m,o)>5.0)
			{
				rocaF[i][j]=(nu0*deltat/(deltax*deltax))*(rocaN[i+1][j]+rocaN[i-1][j]-2.0*rocaN[i][j])+(nu0*deltat/(deltay*deltay))*(rocaN[i][j+1]+rocaN[i][j-1]-2.0*rocaN[i][j])+rocaN[i][j];
					
			}
			else
			{
				
			rocaF[i][j]=100.;
			rocaN[i][j]=100.;
			}
		rocaF[i][0]=rocaF[i][1];
		rocaF[0][j]=rocaF[1][j];
		rocaF[i][49]=rocaF[i][48];
		rocaF[49][j]=rocaF[48][j];
		
		rocaN[i][j]=rocaF[i][j];
		
		}

	}
	if(k==cont1)
	{
	f.open("AbiertolInt1.txt");
	for(int i=0;i<N0;i++)
	{
		for(int j=0;j<N0;j++)
		{
			f<<rocaF[i][j]<<" ";
		}
		f<<endl;
	}
	f.close();
		
	}
	
	if(k==cont2)
	{
	f.open("AbiertoInt2.txt");
	for(int i=0;i<N0;i++)
	{
		for(int j=0;j<N0;j++)
		{
			f<<rocaF[i][j]<<" ";
		}
		f<<endl;
	}
	f.close();


	}



	}
	

	f.open("Abiertofinal.txt");

	for(int i=0;i<N0;i++)
	{
		for(int j=0;j<N0;j++)
		{
			f<<rocaF[i][j]<<" ";
		}
		f<<endl;
	}
	f.close();
	


}

void resolverPeriodico(float nu0, int N0)
{
	ofstream f;
	for(int k= 1;k<20000;k++)
	{
	
	for(int i=1;i<N0+1;i++)
	{
		for(int j=0;j<N0;j++)
		{
			float o=float(i);
			float m=float(j);
		

		if(distancia((float(N0)/2.)-1.,(float(N0)/2.)-1.,m,o)>5.0)
			{
				rocaF[i][j]=(nu0*deltat/(deltax*deltax))*(rocaN[i+1][j]+rocaN[i-1][j]-2.0*rocaN[i][j])+(nu0*deltat/(deltay*deltay))*(rocaN[i][j+1]+rocaN[i][j-1]-2.0*rocaN[i][j])+rocaN[i][j];
					
			}
			else
			{
				
			rocaF[i][j]=100.;
			rocaN[i][j]=100.;
			}
		
		rocaF[i][49]=rocaF[i][0];
		rocaF[49][j]=rocaF[0][j];
		
		rocaF[0][j]=rocaF[49][j];
		rocaF[i][0]=rocaF[i][49];
		
		rocaF[49][i]=rocaF[0][i];
		rocaF[j][49]=rocaF[j][0];
		
		rocaF[j][0]=rocaF[j][49];
		rocaF[0][i]=rocaF[49][i];

		
		
		
		rocaN[i][j]=rocaF[i][j];
		
		}

	}
	if(k==cont1)
	{
	f.open("PeridicolInt1.txt");
	for(int i=0;i<N0;i++)
	{
		for(int j=0;j<N0;j++)
		{
			f<<rocaF[i][j]<<" ";
		}
		f<<endl;
	}
	f.close();
		
	}
	
	if(k==cont2)
	{
	f.open("PeriodicoInt2.txt");
	for(int i=0;i<N0;i++)
	{
		for(int j=0;j<N0;j++)
		{
			f<<rocaF[i][j]<<" ";
		}
		f<<endl;
	}
	f.close();


	}
	}



	

	f.open("Periodicofinal.txt");

	for(int i=0;i<N0;i++)
	{
		for(int j=0;j<N0;j++)
		{
			f<<rocaF[i][j]<<" ";
		}
		f<<endl;
	}
	f.close();
	

}

