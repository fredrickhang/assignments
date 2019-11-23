#include<iostream>
#include<math.h>
using namespace std;
const double pi = 3.1415926535897;

void ASolution(double tSur,double tIn,double D,double m,double L,double deltaT,double deltaX) {
	double tNext=0;
	double x = 0;
	double t = 0;
	double node[10];
	int j = 1;
	for (int i = 0; i < m;i++) {
	
	tNext = tSur + 2 * (tIn - tSur) * (exp(-D * ((j * pi / L) * (j * pi / L)) * t) * (1 - pow(-1, j) / (j * pi)) * (sin((j * pi * x) / L)));
	x = x + deltaX;
	t = t + deltaT;
	j++;
	node[i] = tNext;
	cout << tNext<<"\n";
	
	}



}