
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
	////n=2
	//std::cout << "n=2" << "\n";
	//double node2[621];
	//node2[0] = 149;
	//node2[620] = 149;
	//for (int i = 1; i < 620; i++) {
	//	node2[i] = computeNodeD(node1[i-1], node0[i], node1[i + 1], D, deltaT, deltaX);
	//	//std::cout << node2[i]<<"\n";
	//}
	//
	////n=3
	//std::cout << "n=3" << "\n";
	//double node3[621];
	//node3[0] = 149;
	//node3[620] = 149;
	//for (int i = 1; i < 620; i++) {
	//	node3[i]= computeNodeD(node2[i-1], node1[i], node2[i + 1], D, deltaT, deltaX);
	//	//std::cout << node3[i]<<"\n";
	//}
	//n4
	//std::cout << "n=4" << "\n";
	//double node4[621];
	//node4[0] = 149;
	//node4[620] = 149;
	//for (int i = 1; i < 620; i++) {
	//	node4[i] = computeNodeD(node3[i - 1], node2[i], node3[i + 1], D, deltaT, deltaX);
	//	//std::cout << node4[i] << "\n";
	//}
	double nodenext[621];
	double noden[621];
	double nodelast[621];
	ofstream myfile;
	myfile.open("resultFile.txt");
	for (int i = 0; i < 621;i++) {
		nodelast[i] = node0[i];
		noden[i] = node1[i];
	
	
	}
	double t = 0.02;
	for (int j = 0; j < 50;j++) {
	
	
	
	for (int i = 0; i < 619;i++) {
		nodenext[0] = 149;
		nodelast[0] = 149;
		noden[0] = 149;
		nodenext[620] = 149;
		nodelast[620] = 149;
		noden[620] = 149;
		nodenext[i + 1] = computeNodeD(noden[i],nodelast[i+1],noden[i+2],D,deltaT,deltaX);
		
		
		switch (j)
		{
		case 8:
			myfile << nodenext[i + 1] << "\n";
			break;
		case 18:
			myfile << nodenext[i + 1] << "\n";
			break;
		case 28:
			myfile << nodenext[i + 1] << "\n";
			break;
		case 38:
			myfile << nodenext[i + 1] << "\n";
			break;
		case 48:
			myfile << nodenext[i + 1] << "\n";
			break;
		default:
			break;
		}
		
		//if (j == 8 || j == 18 || j == 28 || j == 38 || j == 48) {
		//	
		//	//myfile << t << "\n";
		//	//myfile << nodenext[0] << "\n";
		//	myfile << nodenext[i+1] << "\n";
		//	//myfile << nodenext[620] << "\n";
		//	//std::cout << nodenext[i + 1] < "\n";

		//}
	
	}
	t += 0.01;
	for (int i = 0; i < 621;i++) {
		nodelast[i] = noden[i];
		noden[i] = nodenext[i];
	
	
	}
	}
	//n5
	//std::cout << "n=5" << "\n";
	//double node5[621];
	//node5[0] = 149;
	//node5[620] = 149;
	//for (int i = 1; i < 620; i++) {
	//	node5[i] = computeNodeD(node4[i - 1], node3[i], node4[i + 1], D, deltaT, deltaX);
	//	//std::cout << node5[i] << "\n";
	//}
	
	/*myfile << "n=1" << "\n";
	for (int i = 0; i < 621;i++) {
		myfile << node1[i] << " \n";
		
	}
	myfile << "n=2" << "\n";
	for (int i = 0; i < 621; i++) {
		myfile << node2[i] << " \n";

	}
	myfile << "n=3" << "\n";
	for (int i = 0; i < 621; i++) {
		myfile << node3[i] << " \n";

	}
	myfile << "n=4" << "\n";
	for (int i = 0; i < 621; i++) {
		myfile << node4[i] << " \n";

	}
	myfile << "n=5" << "\n";
	for (int i = 0; i < 621; i++) {
		myfile << node5[i] << " \n";

	}*/
	



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
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           

