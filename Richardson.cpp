#include <iostream>
#include<fstream>
#include<ostream>
#include<math.h>
#include<stdlib.h>
using namespace std;

double computeNodeR(double iBackwordn, double inBackword, double iForwardn, double nBackwardi, double D, double deltaT, double deltaX);


void Richardson(double D, double deltaT, double deltaX) {
	//n=0
	double node0[621];
	node0[0] = 149;
	node0[620] = 149;
	for (int i = 1; i < 620; i++) {
		node0[i] = 38;

	}


	double nodet0[622];
	double nodet1[622];
	double nodetnmins1[622];
	double nodetn[621];

	double ci_[622];
	double di_[622];
	double Di_[622];

	double ai, bi, ci;
	ai = -(deltaT * 93) / (deltaX * deltaX);
	bi = 2 * (deltaT * 93) / (deltaX * deltaX) + 1;
	ci = -(deltaT * 93) / (deltaX * deltaX);

	cout << ai << "  " << bi << "   " << ci << endl;
	//calculate ci_
	ci_[1] = ci / bi;
	for (int i = 2; i < 622; i++) {
		ci_[i] = ci / (bi - ai * ci_[i - 1]);
	}

	//calculate di_
	Di_[1] = (38 - ai * 149) / bi;
	//Di_[621] = ((38 - ai * 149) - ai * Di_[620]) / (bi - ai * ci_[620]);
	//cout << Di_[621];
	for (int i = 2; i < 621; i++) {
		Di_[i] = (38 - ai * Di_[i - 1]) / (bi - ai * ci_[i - 1]);
		//cout << Di_[i] << endl;
	}
	Di_[621] = ((38 - ai * 149) - ai * Di_[620]) / (bi - ai * ci_[620]);
	//cout << Di_[621];
	nodet1[621] = Di_[621];
	cout << nodet1[621] << endl;
	for (int i = 620; i > 0; i--) {
		nodet1[i] = Di_[i] - ci_[i] * nodet1[i + 1];
		//cout << i << " " << nodet1[i] << endl;
	}
	//n=1
	std::cout << "n=1" << "\n";
	double node1[621];
	node1[0] = 149;
	node1[620] = 149;
	for (int i = 1; i < 620; i++) {
		node1[i] = nodet1[i];
		std::cout << node1[i]<<"\n";
	}



	double nodenext[621];
	double noden[621];
	double nodelast[621];
	ofstream myfile;
	myfile.open("richardsonResultFile.csv");
	for (int i = 0; i < 621; i++) {
		nodelast[i] = node0[i];
		noden[i] = node1[i];


	}


	for (int j = 0; j < 50; j++) {

		switch (j)
		{
		case 8:
			myfile <<"t=0.1" << ",";
			
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
		
		for (int i = 0; i < 619; i++) {
			nodenext[0] = 149;
			nodelast[0] = 149;
			nodenext[620] = 149;
			nodelast[620] = 149;
		
			nodenext[i + 1] = computeNodeR(noden[i], noden[i + 1], noden[i + 2], nodelast[i + 1], D, deltaT, deltaX);


		}
			if (j == 8 || j == 18 || j == 28 || j == 38 || j == 48) {

				for (int h = 0; h < 621;h++) {
				
				myfile << nodenext[h] << ",";
				}

				myfile << endl;
				

			}
			
		//myfile << "149"<<"\n";
		for (int i = 0; i < 621; i++) {
			nodelast[i] = noden[i];
			noden[i] = nodenext[i];


		}
		
	}

}
//double nextNodeR(double in, double iForwardn, double iBackwardn, double D, double deltaT, double deltaX) {
//	double Tinplus1;
//	Tinplus1 = in + (D * deltaT / (deltaX * deltaX)) * (iForwardn - 2 * in + iBackwardn);
//	return Tinplus1;
//
//}

double computeNodeR(double iBackwardn, double in, double iForwardn,double nBackwardi, double D, double deltaT, double deltaX) {
	double Tinplus1;
	Tinplus1 = ( 2 * D* deltaT / (deltaX * deltaX)) * (iForwardn-2*in+iBackwardn)+nBackwardi;
	return Tinplus1;

}