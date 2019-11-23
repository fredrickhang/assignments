#include <stdio.h>
#include <iostream>

#define D 0.0093// diffusivity of D = 93 cm2/hr.

double Ci_1(double ci, double bi);
double Ci_n(double ci, double bi, double ai, double ci_0);
double Di_1(double di, double bi);
double Di_n(double ai, double bi, double ci_, double di, double di_0);

void Lassonen(double DistanceT, double DistanceX) {

	double nodet0[621];
		double nodet1[621];
		double ci_[621];
		double di_[621];
	
		double DistanceT, DistanceX;
		DistanceT = 0.01;
		DistanceX = 0.05;
		for (int i = 0; i < 621; i++) {
			nodet0[i] = 38;
		}
	
		nodet0[1] = 149;
		nodet1[1] = 149;
		double ai,bi, ci;
		ai = -(DistanceT * D) / (DistanceX * DistanceX);
		bi = 2 * (DistanceT * D) / (DistanceX * DistanceX) + 1;
		ci= -(DistanceT * D) / (DistanceX * DistanceX);
	
		cout << ai <<"  "<< bi <<"   "<< ci << endl;
		
		for (int n = 0; n < 621; n++) {
			if (n == 1) {
			   ci_[n]= Ci_1(ci, bi);
			   di_[n] =149;
			   cout << di_[n] << endl;
			}
			else if (n > 1) {
				ci_[n] = Ci_n(ci, bi, ai, ci_[n - 1]);
				di_[n] = Di_n(ai, bi, ci_[n-1], nodet0[n], di_[n - 1]);
				//cout << di_[n] << endl;
				nodet1[n] = di_[n] - ci_[n] * nodet1[n - 1];
				cout << nodet1[n] << endl;
			}
	
		}
		
		
		return 0;

}
double Ci_1(double ci, double bi) {
	double ci_;
	 ci_ = ci / bi;
	return ci_;
}

double Ci_n(double ci, double bi, double ai, double ci_0) {
	double ci_;
	ci_ = ci / (bi - (ai * ci_0));
	return ci_;
}

double Di_1(double di, double bi) {
	double di_;
	di_ = di / bi;
	return di_;
}

double Di_n(double ai, double bi, double ci_,double di, double di_0) {
	
	
    double di_ = (di - ai * di_0) / (bi - ai * ci_);
	return di_;
}