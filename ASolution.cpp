#include<iostream>
#include<math.h>
using namespace std;
const double pi = 3.1415926535897;

void ASolution(double tSur,double tIn,double D,double m,double L,double deltaT,double deltaX) {
	double tNext=0;
	double x = 0;
	double t = 0;
	//double node[50];
	//double node[50];
	//int j = 1;
	double sum = 0;
	//for (int i = 0; i < m; i++) {
	//	if (j <= m) {
	//		sum = sum+(exp( (-1* D) * ((j * pi / L) * (j * pi / L)) * 0.1) * ((1 - pow(-1, j)) / (j * pi)) * (sin((j * pi *x) / L)));
	//		x = x + deltaX;
	//		t = t + deltaT;
	//		j++;
	//		tNext = tSur + (2 * (tIn - tSur) * sum);
	//		node[i] = tNext;
	//		//cout << tNext << "\n";
	//	}
	//	cout << sum << endl;
	//}
	//

	//zikun 
	double node[622];
	for (int j = 1; j < 620; j++) {
		sum = 0;
		for (int i = 1; i < m; i++) {
			//sum = 0;
			sum = sum + ((exp((-D) * ((i * pi / L) * (i * pi / L)) * 0.01) )* ((1 - pow(-1, i)) / (i * pi)) * (sin((i * pi * x) / L)));
			//cout << sum << endl;
		}
		x = x + deltaX;
	   // cout << sum << endl;
		tNext = tSur + (2 * (tIn - tSur) * sum);
		node[j] = tNext;
		cout << node[j] << endl;

	}
	//x = x + deltaX;
	//for (int i = 1; i < m; i++) {
	//	sum = sum + ((exp((-D) * ((i * pi / L) * (i * pi / L)) * 0.1)) * ((1 - pow(-1, i)) / (i * pi)) * (sin((i * pi * x) / L)));
	//	//cout << sum << endl;
	//}
	////x = x + deltaX;
	////cout << sum << endl;
	//tNext = tSur + (2 * (tIn - tSur) * sum);
	////node[j] = tNext;
	//cout << tNext << endl;
}