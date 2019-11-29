#include <stdio.h>
#include <iostream>
#include<fstream>
#include<ostream>

using namespace std;
#define D 93// diffusivity of D = 93 cm2/hr.

double Ci_1L(double ci, double bi);
double Ci_nL(double ci, double bi, double ai, double ci_0);
double Di_1L(double di, double bi);
double Di_nL(double ai, double bi, double ci_, double di, double di_0);

void Lassonen(double DistanceT, double DistanceX, double nodet1[622]) {


	    ofstream myfile;
	    myfile.open("LaasonenResultFile.csv");

	    double nodet0[622];
		//double nodet1[622];
		double nodetnmins1[622];
		double nodetn[621];

		double ci_[622];
		//double di_[622];
		double Di_[622];
		//double DistanceT, DistanceX;
		DistanceT = 0.01;
		DistanceX = 0.05;
		for (int i = 0; i < 621; i++) {
			nodet0[i] = 38;
		}
	
		nodet0[1] = 149;
		nodet1[0] = 149;
		double ai,bi, ci;
		ai = -(DistanceT * D) / (DistanceX * DistanceX);
		bi = 2 * (DistanceT * D) / (DistanceX * DistanceX) + 1;
		ci= -(DistanceT * D) / (DistanceX * DistanceX);
	
		cout << ai <<"  "<< bi <<"   "<< ci << endl;
		//calculate ci_
		ci_[1] = ci / bi;
		for (int i = 2; i < 620; i++) {
			ci_[i] = ci / (bi - ai * ci_[i - 1]);
		}

	    //calculate di_
		Di_[1] = (38 - ai * 149) / bi;
		//Di_[621] = ((38 - ai * 149) - ai * Di_[620]) / (bi - ai * ci_[620]);
		//cout << Di_[621];
		for (int i = 2; i < 620; i++) {
			Di_[i] = (38 - ai * Di_[i - 1]) / (bi - ai * ci_[i - 1]);
			//cout << Di_[i] << endl;
		}
		Di_[619] = ((38 - ai * 149) - ai * Di_[618]) / (bi - ai * ci_[618]);
		//cout << Di_[621];
		nodet1[619] = Di_[619];
		//cout << nodet1[619] << endl;
		for (int i = 618; i > 0; i--) {
			nodet1[i] = Di_[i]-ci_[i] * nodet1[i + 1];
			//cout <<i<<" "<< nodet1[i] << endl;
		}
		
		//other temperature
		for(int i = 0; i < 620; i++ ){
			nodetnmins1[i] = nodet1[i];
		
		}

		for (int j = 2; j < 51; j++) {
			double T = 0;
				T = 0.01 * j;
				if (T == 0.1 || T == 0.2 || T == 0.3 || T == 0.4 || T == 0.5) {
					//cout << "time is " << T << endl;
					myfile << endl;
					myfile << "time is" << ","<<T << ",";
					
				}

			Di_[1] = (nodetnmins1[1] - ai * 149) / bi;
			
			//cout << Di_[621];
			for (int i = 2; i < 620; i++) {
				Di_[i] = (nodetnmins1[i] - ai * Di_[i - 1]) / (bi - ai * ci_[i - 1]);
				//cout << Di_[i] << endl;
			}
			Di_[619] = ((nodetnmins1[619] - ai * 149) - ai * Di_[618]) / (bi - ai * ci_[618]);

			nodetn[619] = Di_[619];
			//cout << nodetn[619] << endl;

			if (T == 0.1 || T == 0.2 || T == 0.3 || T == 0.4 || T == 0.5) {
				//cout << 619 << " " << nodetn[619] << endl;
				myfile << nodetn[619] << ",";
			}
			
			for (int i = 618; i > 0; i--) {
				nodetn[i] = Di_[i] - ci_[i] * nodetn[i + 1];
				
				if (T == 0.1 || T == 0.2 || T == 0.3 || T == 0.4 || T == 0.5) {
				 // cout << i << " " << nodetn[i] << endl;
				  myfile << nodetn[i] << ",";
				}
				
			}

			for (int i = 0; i < 620; i++) {
				nodetnmins1[i] = nodetn[i];
			}
		 
		}

		//return nodet1;

}

double Ci_1L(double ci, double bi) {
	double ci_;
	 ci_ = ci / bi;
	return ci_;
}

double Ci_nL(double ci, double bi, double ai, double ci_0) {
	double ci_;
	ci_ = ci / (bi - (ai * ci_0));
	return ci_;
}

double Di_1L(double di, double bi) {
	double di_;
	di_ = di / bi;
	return di_;
}

double Di_nL(double ai, double bi, double ci_,double di, double di_0) {
	
	
    double di_ = (di - ai * di_0) / (bi - ai * ci_);
	return di_;
}