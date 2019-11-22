#include <stdio.h>
#include <iostream>

#define D 93// diffusivity of D = 93 cm2/hr.

double secondNode(double Tn, double Tnplus1, double DistanceT, double DistanceX);
double ComputeNode(double DistanceT, double DistanceX, double Tinplus1, double Tin, double Timins1nplus1);


double Lassonen(double DistanceT, double DistanceX) {

	double nodet0[311], nodet1[311], nodet2[311], nodet3[311], nodet4[311], nodet5[311];

	//nodet0 temperature

	for (int i = 0; i < 311; i++) {
		nodet0[i] = 38;
	}

	//nodet1 temperature
	nodet1[0] = 149;
	nodet1[1] = secondNode(nodet0[0], nodet1[0], DistanceT, DistanceX);
	for (int n = 2; n < 311; n++) {
		nodet1[n] = ComputeNode(DistanceT, DistanceX, nodet1[n - 1], nodet0[n - 1], nodet1[n - 2]);
	}

	//nodet2 temperature
	nodet2[0] = 149;
	nodet2[1] = secondNode(nodet1[0], nodet2[0], DistanceT, DistanceX);
	for (int n = 2; n < 311; n++) {
		nodet2[n] = ComputeNode(DistanceT, DistanceX, nodet2[n - 1], nodet1[n - 1], nodet2[n - 2]);
	}

	//nodet3 temperature
	nodet3[0] = 149;
	nodet3[1] = secondNode(nodet2[0], nodet3[0], DistanceT, DistanceX);
	for (int n = 2; n < 311; n++) {
		nodet3[n] = ComputeNode(DistanceT, DistanceX, nodet3[n - 1], nodet2[n - 1], nodet3[n - 2]);
	}

	//nodet4 temperature
	nodet4[0] = 149;
	nodet4[1] = secondNode(nodet3[0], nodet4[0], DistanceT, DistanceX);
	for (int n = 2; n < 311; n++) {
		nodet4[n] = ComputeNode(DistanceT, DistanceX, nodet4[n - 1], nodet3[n - 1], nodet4[n - 2]);
	}

	//nodet5 temperature
	nodet5[0] = 149;
	nodet5[1] = secondNode(nodet4[0], nodet5[0], DistanceT, DistanceX);
	for (int n = 2; n < 311; n++) {
		nodet5[n] = ComputeNode(DistanceT, DistanceX, nodet5[n - 1], nodet4[n - 1], nodet5[n - 2]);
	}


	//return type is array
	//return nodet0, nodet1, nodet2, nodet3, nodet4, nodet5; 

}
double secondNode(double Tn, double Tnplus1, double DistanceT, double DistanceX) {
	double Tiplus1;
	Tiplus1 = ((Tnplus1 - Tn) * (DistanceX * DistanceX) / (DistanceT * -D) + (2 * Tnplus1)) / 2;
	return Tiplus1;
}

double ComputeNode(double DistanceT, double DistanceX, double Tinplus1, double Tin, double Timins1nplus1) {

	double Tiplus1nplus1;
	Tiplus1nplus1 = ((Tinplus1 - Tin) * (DistanceX * DistanceX) / DistanceT * -D) + 2 * Tinplus1 - Timins1nplus1;

	return Tiplus1nplus1;



}