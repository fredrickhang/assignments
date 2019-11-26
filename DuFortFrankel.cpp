
#include <iostream>
#include<fstream>
#include<ostream>
#include<math.h>
#include<stdlib.h>
#include "DuFortFrankel.h"

using namespace std;

double computeNodeD(double iBackwordn, double inBackword, double iForwardn, double D, double deltaT, double deltaX);
double nextNodeD(double in, double iForwardn, double iBackwardn, double D, double deltaT, double deltaX);

void DufortFrankel(double D, double deltaT,double deltaX) {
	//n=0
	double node0[621];
	node0[0] = 149;
	node0[620] = 149;
	for (int i = 1; i < 620;i++) {
		node0[i] = 38;
	
	}
	//n=1
	std::cout << "n=1" << "\n";
	double node1[621];
	node1[0] = 149;
	node1[620] = 149;
	for (int i = 1; i < 620; i++) {
		node1[i] = nextNodeD(node0[i],node0[i+1],node0[i-1],D,deltaT,deltaX);
		//std::cout << node1[i] << "\n";
	}
	
	double nodenext[621];
	double noden[621];
	double nodelast[621];
	ofstream myfile;
	myfile.open("resultFile.txt");
	for (int i = 0; i < 621;i++) {
		nodelast[i] = node0[i];
		noden[i] = node1[i];
	
	
	}
	
	for (int j = 0; j < 50;j++) {
		switch (j)
		{
		case 8:
			myfile << "t=0.1" << "\n";

			break;
		case 18:
			myfile << "t=0.2" << "\n";

			break;
		case 28:
			myfile << "t=0.3" << "\n";

			break;
		case 38:
			myfile << "t=0.4" << "\n";

			break;
		case 48:
			myfile << "t=0.5" << "\n";

			break;
		default:
			break;
		}
	
	
	for (int i = 0; i < 619;i++) {
		nodenext[0] = 149;
		nodelast[0] = 149;
		noden[0] = 149;
		nodenext[620] = 149;
		nodelast[620] = 149;
		noden[620] = 149;
		nodenext[i + 1] = computeNodeD(noden[i],nodelast[i+1],noden[i+2],D,deltaT,deltaX);
				
	
	}
		if (j == 8 || j == 18 || j == 28 || j == 38 || j == 48) {
			
			for (int h = 0; h < 621; h++) {

				myfile << nodenext[h] << "\n";
			}
				
		}
	
	for (int i = 0; i < 621;i++) {
		nodelast[i] = noden[i];
		noden[i] = nodenext[i];
	
	
	}
	}
	

}

double nextNodeD(double in, double iForwardn, double iBackwardn, double D, double deltaT, double deltaX ) {
	double Tinplus1;
	Tinplus1 = in + ( D * deltaT / (deltaX * deltaX)) * (iForwardn - 2 * in + iBackwardn);
	return Tinplus1;

}

double computeNodeD(double iBackwordn,double inBackword, double iForwardn, double D, double deltaT, double deltaX) {
	double Tinplus1;
	Tinplus1 = ((1 - 2 * (D) * deltaT / (deltaX * deltaX)) * inBackword + (2 * (D) * deltaT / (deltaX * deltaX)) * (iForwardn + iBackwordn)) / (1 + 2 * (D) * deltaT / (deltaX * deltaX));
	return Tinplus1;

}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           

