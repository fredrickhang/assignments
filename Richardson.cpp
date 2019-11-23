#include <iostream>
#include<fstream>
#include<ostream>
#include<math.h>
#include<stdlib.h>
using namespace std;

double computeNodeR(double iBackwordn, double inBackword, double iForwardn, double nBackwardi, double D, double deltaT, double deltaX);
double nextNodeR(double in, double iForwardn, double iBackwardn, double D, double deltaT, double deltaX);

void Richardson(double D, double deltaT, double deltaX) {
	//n=0
	double node0[621];
	node0[0] = 149;
	node0[620] = 149;
	for (int i = 1; i < 620; i++) {
		node0[i] = 38;

	}
	//n=1
	std::cout << "n=1" << "\n";
	double node1[621];
	node1[0] = 149;
	node1[620] = 149;
	for (int i = 1; i < 620; i++) {
		node1[i] = nextNodeR(node0[i], node0[i + 1], node0[i - 1], D, deltaT, deltaX);
		//std::cout << node1[i] << "\n";
	}

	//n=2
	std::cout << "n=2" << "\n";
	double node2[621];
	node2[0] = 149;
	node2[620] = 149;
	for (int i = 1; i < 620; i++) {
		node2[i] = computeNodeR(node1[i - 1], node1[i], node1[i + 1],node0[i], D, deltaT, deltaX);
		//std::cout << node2[i]<<"\n";
	}

	//n=3
	std::cout << "n=3" << "\n";
	double node3[621];
	node3[0] = 149;
	node3[620] = 149;
	for (int i = 0; i < 620; i++) {
		node3[i] = computeNodeR(node2[i - 1], node1[i], node2[i + 1], node1[i], D, deltaT, deltaX);
		//std::cout << node3[i]<<"\n";
	}
	//n4
	std::cout << "n=4" << "\n";
	double node4[621];
	node4[0] = 149;
	node4[620] = 149;
	for (int i = 0; i < 620; i++) {
		node4[i] = computeNodeR(node3[i - 1], node2[i], node3[i + 1], node2[i], D, deltaT, deltaX);
		//std::cout << node4[i] << "\n";
	}

	//n5
	std::cout << "n=5" << "\n";
	double node5[621];
	node5[0] = 149;
	node5[620] = 149;
	for (int i = 0; i < 619; i++) {
		node5[i] = computeNodeR(node4[i - 1], node3[i], node4[i + 1], node3[i], D, deltaT, deltaX);
		//std::cout << node5[i] << "\n";
	}
	ofstream myfile;
	myfile.open("richardsonResultFile.txt");
	myfile << "n=1" << "\n";
	for (int i = 0; i < 621; i++) {
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

	}


}

double nextNodeR(double in, double iForwardn, double iBackwardn, double D, double deltaT, double deltaX) {
	double Tinplus1;
	Tinplus1 = in + (D * deltaT / (deltaX * deltaX)) * (iForwardn - 2 * in + iBackwardn);
	return Tinplus1;

}

double computeNodeR(double iBackwardn, double in, double iForwardn,double nBackwardi, double D, double deltaT, double deltaX) {
	double Tinplus1;
	Tinplus1 = ( 2 * D* deltaT / (deltaX * deltaX)) * (iForwardn-2*in+iBackwardn)+nBackwardi;
	return Tinplus1;

}