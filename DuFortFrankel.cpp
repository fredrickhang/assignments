
#include <iostream>
#include<fstream>
#include<ostream>
#include<math.h>
#include<stdlib.h>
#include "DuFortFrankel.h"
#include "LaasonenSimoleImplicit.h"
using namespace std;

double computeNodeD(double iBackwordn, double inBackword, double iForwardn, double D, double deltaT, double deltaX);
/*
compute Dufort-Frankel value
*/
void DufortFrankel(double D, double deltaT,double deltaX) {
	//compute the tempurature when n=0 
	double node0[621];
	node0[0] = 149;
	node0[620] = 149;
	for (int i = 1; i < 620;i++) {
		node0[i] = 38;
	
	}

	double nodet0[622];
	double nodet1[622];
	double nodetnmins1[622];
	double nodetn[621];


	//use Laasonen method to compute the value when n=1
	double ci_[622];
	double di_[622];
	double Di_[622];
	for (int i = 0; i < 621; i++) {
		nodet0[i] = 38;
	}

	nodet0[1] = 149;
	nodet1[0] = 149;


	double ai, bi, ci;
	ai = -(deltaT * 93) / (deltaX * deltaX);
	bi = 2 * (deltaT * 93) / (deltaX * deltaX) + 1;
	ci = -(deltaT * 93) / (deltaX * deltaX);

	//calculate ci_
	ci_[1] = ci / bi;
	for (int i = 2; i < 622; i++) {
		ci_[i] = ci / (bi - ai * ci_[i - 1]);
	}

	//calculate di_
	Di_[1] = (38 - ai * 149) / bi;
	for (int i = 2; i < 621; i++) {
		Di_[i] = (38 - ai * Di_[i - 1]) / (bi - ai * ci_[i - 1]);
	}
	Di_[621] = ((38 - ai * 149) - ai * Di_[620]) / (bi - ai * ci_[620]);
	nodet1[621] = Di_[621];
	//cout << nodet1[621] << endl;
	for (int i = 620; i > 0; i--) {
		nodet1[i] = Di_[i] - ci_[i] * nodet1[i + 1];
	}






	
	//std::cout << "n=1" << "\n";
	double node1[621];
	node1[0] = 149;
	node1[620] = 149;
	for (int i = 1; i < 620; i++) {
		node1[i] = nodet1[i];
		//std::cout << node1[i] << "\n";
	}
	
	double nodenext[621];
	double noden[621];
	double nodelast[621];

	//use oftream to create a .csv file to output result
	ofstream myfile;
	myfile.open("resultFile.csv");

	//compute each time leve's value
	for (int i = 0; i < 621;i++) {
		nodelast[i] = node0[i];
		noden[i] = node1[i];
	
	
	}
	//only output result when n=0.1,0.2,0.3,0.4,0.5
	for (int j = 0; j < 50;j++) {
		switch (j)
		{
		case 8:
			myfile << "t=0.1" << ",";

			break;
		case 18:
			myfile << "t=0.2" << ",";

			break;
		case 28:
			myfile << "t=0.3" << ",";

			break;
		case 38:
			myfile << "t=0.4" << ",";

			break;
		case 48:
			myfile << "t=0.5" << ",";

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

				myfile << nodenext[h] << ",";
			}
			myfile << endl;
				
		}
	
	for (int i = 0; i < 621;i++) {
		nodelast[i] = noden[i];
		noden[i] = nodenext[i];
	
	
	}
	}
	myfile.close();
}

/*compute the time leve's value after n=1*/
double computeNodeD(double iBackwordn,double inBackword, double iForwardn, double D, double deltaT, double deltaX) {
	double Tinplus1;
	Tinplus1 = ((1 - 2 * (D) * deltaT / (deltaX * deltaX)) * inBackword + (2 * (D) * deltaT / (deltaX * deltaX)) * (iForwardn + iBackwordn)) / (1 + 2 * (D) * deltaT / (deltaX * deltaX));
	return Tinplus1;

}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           

