#include<iostream>
#include<fstream>
#include<math.h>
using namespace std;
const double pi = 3.1415926535897;
/*
compute analytical solution value
*/
void ASolution(double tSur,double tIn,double D,double m,double L,double deltaT,double deltaX,double node[622]) {
	double tNext=0;
	double x = 0;
	double t = 0;
	double sum = 0;
	//use oftream to create a .csv file to output result
	ofstream myfile;
	myfile.open("ASresultFile.csv");
	for (int j = 1; j < 621; j++) {
		sum = 0;
		for (int i = 1; i < m; i++) {
			//sum = 0;
			sum = sum + ((exp((-D) * ((i * pi / L) * (i * pi / L)) * deltaT) )* ((1 - pow(-1, i)) / (i * pi)) * (sin((i * pi * x) / L)));
		}
		x = x + deltaX;
		tNext = tSur + (2 * (tIn - tSur) * sum);
		node[j] = tNext;
		myfile << node[j] << ",";


	}
	
	myfile.close();
}