
#include <iostream>
#include "DuFortFrankel.h"

double nextNode(double iBackwordn, double inBackword, double iForwardn, double D, double deltaT, double deltaX);


void DufortFrankel(double D, double deltaT,double deltaX) {
	//n=0
	double node0[311];
	for (int i = 0; i < 311;i++) {
		node0[i] = 38;
	
	}
	//n=1
	double node1[311];
	node1[0] = 149;
	for (int i = 1; i < 311; i++) {
		node1[i] = 38;
	}
	//n=2
	double node2[311];
	node2[0] = 149;
	for (int i = 0; i < 308; i++) {
		node2[i+1] = nextNode(node1[i], node0[i + 1], node1[i + 2], D, deltaT, deltaX);
		std::cout << node2[i+1]<<"\n";
	}
	//n=3
	double node3[311];
	node3[0] = 149;
	for (int i = 0; i < 308; i++) {
		node3[i+1]= nextNode(node2[i], node1[i + 1], node2[i + 2], D, deltaT, deltaX);
		std::cout << node3[i + 1]<<"\n";
	}
	
	




}

double nextNode(double iBackwordn,double inBackword, double iForwardn, double D, double deltaT, double deltaX) {
	double Tinplus1;
	Tinplus1 = ((1 - 2 * (-D) * deltaT / (deltaX * deltaX)) * inBackword + (2 * (-D) * deltaT / (deltaX * deltaX)) * (iForwardn + iBackwordn)) / (1 + 2 * (-D) * deltaT / (deltaX * deltaX));
	return Tinplus1;

}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           

