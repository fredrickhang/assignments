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

void Lassonen(double DistanceT, double DistanceX) {

	    double nodet0[622];
		double nodet1[622];
		double nodetnmins1[622];
		double nodetn[621];

		double ci_[622];
		double di_[622];
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
			nodet1[i] = Di_[i]-ci_[i] * nodet1[i + 1];
			cout <<i<<" "<< nodet1[i] << endl;
		}
		//ofstream myfile;
		//myfile.open("LaasonenResultFile.txt");
		//for (int i = 1; i < 622; i++) {

		//	nodet1[i] = (nodet0[i]-ai*nodet1[i-1]) / bi;
		//	//cout << nodet1[i] << endl;
		//}
		//nodet1[1] = (nodet0[1] - ai * nodet1[0]) / bi;
		//ci_[1] = ci / bi;
		//di_[1] = (nodet0[1] - ai * nodet1[0]) / bi;
		//nodet1[1] = (di_[1] - nodet1[0]) / ci;
		//cout << nodet1[1] << endl;
		//for (int i = 2; i < 621; i++) {
		//	ci_[1] = ci / bi;
		//	ci_[i] = Ci_nL(ci, bi, ai, ci_[i - 1]);
		//	di_[i] = Di_nL(ai, bi, ci_[i], nodet0[i], di_[i - 1]);
		//	//nodet1[i] = di_[i] - ci_[i] * nodet1[i - 1];
		//	nodet1[i] = (nodet1[i-1] - ai * nodet1[0]) / bi;			
		//	cout << nodet1[i] << endl;
		//}
		//	

		//for (int n = 0; n < 621; n++) {
		//	if (n == 1) {
		//	   ci_[n]= Ci_1L(ci, bi);
		//	   di_[n] =nodet1[1];
		//	   cout << di_[n] << endl;
		//	}
		//	else if (n > 1) {
		//		ci_[n] = Ci_nL(ci, bi, ai, ci_[n - 1]);
		//		di_[n] = Di_nL(ai, bi, ci_[n-1], nodet0[n], di_[n - 1]);
		//		//cout << di_[n] << endl;
		//		nodet1[n] = di_[n] - ci_[n] * nodet1[n - 1];
		//		cout << nodet1[n] << endl;
		//	}
	
		//}
		//
		////other note temperature
		//for (int i = 0; i < 621; i++) {
		//	nodetnmins1[i] = nodet1[i];

		//}

		//for (int j = 2; j < 51; j++) {
		//	double T = 0;
		//	T = 0.01 * j;

		//	if (T == 0.1 || T==0.2 || T==0.3 || T==0.4 || T==0.5) {
		//		cout << "time is " << T << endl;
		//		//myfile << "time is" << T <<"\n";
		//	}

		//	//cout << "time is " << T << endl;

		//	for (int i = 1; i < 620; i++) {
		//		Di[i] = nodetnmins1[i ];
		//	}
		//	nodetn[1] = 149;
		//	//nodetn[620] = 149;
		//	for (int n = 1; n < 621; n++) {
		//		    ci_[1] = ci / bi;
		//			di_[1] = (nodetn[1] - ai * 149) / bi;
		//			ci_[n] = Ci_nL(ci, bi, ai, ci_[n - 1]);
		//			di_[n] = Di_nL(ai, bi, ci_[n - 1], nodetnmins1[n], di_[n - 1]);
		//			//cout << di_[n] << endl;
		//			nodetn[n] = di_[n] - ci_[n] * nodetn[n - 1];
		//			if (T == 0.1 || T==0.2 || T==0.3 || T==0.4 || T==0.5) {
		//				cout << nodetn[n] << endl;
		//				//myfile << nodetn[n] << "\n";
		//			}

		//		

		//	}
		//	for (int i = 0; i < 621; i++) {
		//		nodetnmins1[i] = nodetn[i];
		//		
		//	}
		//	//nodetn[1] = (nodetnm[1] - ai * nodet1[0]) / bi;
		//
		//}
		//
		//return 0;

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