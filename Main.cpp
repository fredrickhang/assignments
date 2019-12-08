
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
	double laasonenNode[622];//Passing an array of values t=0.01
	double SolutionNode[622];//solution Result
	double soulutionNodeTn[622];
	try
	{
		std::cout << "Begin computing tempurature in each time leve" << "\n";
		/*compute Dufort-Frankel value*/
		DufortFrankel(93, 0.01, 0.05);

		/*compute Richardson value*/
		Richardson(93, 0.01, 0.05);

		/*compute Crank-Nicholson value*/
		CrankNicholson(0.01, 0.05);

		/*compute Lassonen value*/
		Lassonen(0.1, 0.05, laasonenNode);

		/*compute analytical solution value*/
		while (i < 0.6) {
			ASolution(149, 38, 93, 5000, 31, i, 0.05, SolutionNode);
			for (int j = 0; j < 622; j++) {
				myfile << SolutionNode[j] << ",";
			}
			myfile << endl;
			i = i + 0.1;
		}
	}
	catch (exception e)
	{
		throw e;
	}
	
	std::cout << "complete! All result ouput to each file" << endl;

	return 0;
}