
#include "DuFortFrankel.h"
#include "CrankNicholson.h"
#include "LaasonenSimoleImplicit.h"
#include "Richardson.h"
#include "ASolution.cpp"
#include<iostream>
#include<fstream>
#include<ostream>
#include<math.h>


int main() {
	ofstream myfile;
	myfile.open("SolutionResultFile.csv");

	double i = 0.1;
	double sum = 0;
	double laasonenNode[622];//传出数组t=0.01
	double SolutionNode[622];//solution Result
	double soulutionNodeTn[622];


	//double* laasonenT1 = Lassonen(0.01, 0.05);
	//DufortFrankel( 0.0093,0.01,0.05); 
	//Richardson(0.0093, 0.01, 0.05);
	
	//CrankNicholson(0.01, 0.05);

	//Lassonen(0.01, 0.05,laasonenNode);
	//cout << node[2];
	//a = nextNode(149, 38, 38, 0.0093, 0.01, 0.05);

	//std::cout<<a;
	/*ASolution(149,38,93,5000,31,0.1,0.05,SolutionNode);
	for (int i = 0; i < 622; i++) {
		myfile << SolutionNode[i] << ",";
	}
	myfile << endl;
	
	ASolution(149, 38, 93, 5000, 31, 0.2, 0.05, SolutionNode);
	for (int i = 0; i < 622; i++) {
		myfile << SolutionNode[i] << ",";
	}
	myfile << endl;*/
	/*for (int i = 1; i <6; i++) {
		
		T = i / 10;
		ASolution(149, 38, 93, 5000, 31, T, 0.05, SolutionNode);
		for (int j = 0; j < 622; j++) {
			myfile << SolutionNode[j] << ",";
		}
		myfile << endl;
	}*/

	while (i < 0.6) {
		ASolution(149, 38, 93, 5000, 31, i, 0.05, SolutionNode);
		for (int j = 0; j < 622; j++) {
			myfile << SolutionNode[j] << ",";
		}
		myfile << endl;
		i = i + 0.1;
	}
	

	/*for (int i = 1; i < 620; i++) {
		sum = sum + (laasonenNode[i] - SolutionNode[i]) * (laasonenNode[i] - SolutionNode[i]);	   
	}
	sum = sqrt(sum) / 619;
	cout << sum << endl;*/
	//const int pi = 3.1415926;
	//int a = 0;
	//a = pow(-1, 3);
	//std::cout << a;
	return 0;
}