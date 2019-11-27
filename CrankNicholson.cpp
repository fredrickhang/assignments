#include <stdio.h>
#include <iostream>
#include<fstream>
#include<ostream>

using namespace std;
#define D 93// diffusivity of D = 93 cm2/hr.

double Ci_1(double ci, double bi);
double Ci_n(double ci, double bi, double ai, double ci_0);
double Di_1(double di, double bi);
double Di_n(double ai, double bi, double ci_, double di, double di_0);
double Di(double Ti, double Tiplus1, double Timins1, double DistanceX, double DistanceT);

void CrankNicholson(double DistanceT, double DistanceX) {

	double nodet0[622];
	double nodet1[622];
	double nodetnmins1[622];
	double nodetn[622];
	 
	
	double ci_[622];
	double di_[622];

	//double DistanceT, DistanceX;
	DistanceT = 0.01;
	DistanceX = 0.05;

	double ai, bi, ci;

	ai = -1;
	bi = 2 + (2 * (DistanceX * DistanceX)) / (DistanceT * D);
	ci = -1;
	cout << ai << "  " << bi << "   " << ci << endl;


	double Di[620];
	for (int i = 0; i < 621; i++) {
		nodet0[i] = 38;

	}
	nodet1[0] = 149;
	//nodet1 temperature
	
	for (int i = 1; i < 621; i++) {
		Di[i] = (nodet0[i + 1] - 2 * nodet0[i] + nodet0[i - 1]) + 2 * (DistanceX * DistanceX) * nodet0[i] / (D * DistanceT);
		//cout << "Di  "<<i << "  " << Di[i] << endl;

	}
	
	ofstream myfile;
	myfile.open("CrankresultFile.txt");
	//calculate ci_  
	ci_[1] = ci / bi;
	for (int i = 2; i < 621; i++) {
		ci_[i] = ci / (bi - ai * ci_[i - 1]);
	}

	//calculate di_
	di_[1] = (Di[1] - ai * 149) / bi;
	//di_[618] = ((38 - ai * 149) - ai * Di_[620]) / (bi - ai * ci_[620]);
	//cout << di_[1];
	for (int i = 2; i < 621; i++) {
		di_[i] = (Di[i] - ai * di_[i - 1]) / (bi - ai * ci_[i - 1]);
		//cout << Di_[i] << endl;
	}
	di_[619] = ((Di[619] - ai * 149) - ai * di_[618]) / (bi - ai * ci_[618]);
	//cout << Di_[621];
	nodet1[619] = di_[619];
	cout << nodet1[619] << endl;
	for (int i = 618; i > 0; i--) {
		nodet1[i] = di_[i] - ci_[i] * nodet1[i + 1];
		cout << i << " " << nodet1[i] << endl;
	}


	//t=0.02 temperature
	nodet1[620] = 149;
	for (int i = 0; i < 621; i++) {
		nodetnmins1[i] = nodet1[i];
	}

	//nodet1[0] = 149;
	
		
		


		for (int i = 0; i < 621; i++) {
			nodetnmins1[i] = nodet1[i];
		}
		for (int i = 1; i < 620; i++) {
			Di[i] = (nodetnmins1[i + 1] - 2 * nodetnmins1[i] + nodetnmins1[i - 1]) + 2 * (DistanceX * DistanceX) * nodetnmins1[i] / (D * DistanceT);
			//cout << i << "  " << Di[i] << endl;
		}
		ci_[1] = ci / bi;
		for (int i = 2; i < 621; i++) {
			ci_[i] = ci / (bi - ai * ci_[i - 1]);
		}

		//calculate di_
		di_[1] = (Di[1] - ai * 149) / bi;
		//di_[618] = ((38 - ai * 149) - ai * Di_[620]) / (bi - ai * ci_[620]);
		//cout << di_[1];
		for (int i = 2; i < 620; i++) {
			di_[i] = (Di[i] - ai * di_[i - 1]) / (bi - ai * ci_[i - 1]);
			//cout << Di_[i] << endl;
		}
		di_[619] = ((Di[619] - ai * 149) - ai * di_[618]) / (bi - ai * ci_[618]);
		//cout << Di_[621];
		nodetn[619] = di_[619];
		
			cout << " " << nodetn[619] << endl;
			//myfile << nodetn[i] << "\n";
		
		//cout << nodetn[619] << endl;
		for (int i = 618; i > 0; i--) {
			nodetn[i] = di_[i] - ci_[i] * nodetn[i + 1];

				
						cout << i << " " << nodetn[i] << endl;
						//myfile << nodetn[i] << "\n";
				
		}
		
	
	//t=0.03 temperature
		for (int j = 3; j < 51; j++) {
				double T = 0;
	         T = 0.01 * j;
	      if (T == 0.1 || T == 0.2 || T == 0.3 || T == 0.4 || T == 0.5) {
		    cout << "time is " << T << endl;
		//myfile << "time is" << T << "\n";

	      }
			
			
			nodetn[0] = 149;
			nodetn[620] = 149;
			for (int i = 0; i < 621; i++) {
				nodetnmins1[i] = nodetn[i];
			}

			//nodet1[0] = 149;


			for (int i = 1; i < 620; i++) {
				Di[i] = (nodetnmins1[i + 1] - 2 * nodetnmins1[i] + nodetnmins1[i - 1]) + 2 * (DistanceX * DistanceX) * nodetnmins1[i] / (D * DistanceT);
				//cout << i << "  " << Di[i] << endl;
			}
			ci_[1] = ci / bi;
			for (int i = 2; i < 621; i++) {
				ci_[i] = ci / (bi - ai * ci_[i - 1]);
			}

			//calculate di_
			di_[1] = (Di[1] - ai * 149) / bi;
			//di_[618] = ((38 - ai * 149) - ai * Di_[620]) / (bi - ai * ci_[620]);
			//cout << di_[1];
			for (int i = 2; i < 620; i++) {
				di_[i] = (Di[i] - ai * di_[i - 1]) / (bi - ai * ci_[i - 1]);
				//cout << Di_[i] << endl;
			}
			di_[619] = ((Di[619] - ai * 149) - ai * di_[618]) / (bi - ai * ci_[618]);
			//cout << Di_[621];
			nodetn[619] = di_[619];
			if (T == 0.1 || T == 0.2 || T == 0.3 || T == 0.4 || T == 0.5) {
				cout << " " << nodetn[619] << endl;
				//myfile << nodetn[i] << "\n";
			}
			//cout << " " << nodetn[619] << endl;
			//myfile << nodetn[i] << "\n";

		//cout << nodetn[619] << endl;
			for (int i = 618; i > 0; i--) {
				nodetn[i] = di_[i] - ci_[i] * nodetn[i + 1];

				if (T == 0.1 || T == 0.2 || T == 0.3 || T == 0.4 || T == 0.5) {
					cout << i << " " << nodetn[i] << endl;
					//myfile << nodetn[i] << "\n";
				}
			}

		}



	//other temperature
	//for (int i = 0; i < 621; i++) {
	//	nodetnmins1[i] = nodet1[i];

	//}


	//for (int i = 1; i < 622; i++) {
	//	Di[i] = (nodetnmins1[i + 1] - 2 * nodetnmins1[i] + nodetnmins1[i - 1]) + 2 * (DistanceX * DistanceX) * nodetnmins1[i] / (D * DistanceT);
	//}

	//for (int j = 2; j < 51; j++) {
	//	double T = 0;
	//	T = 0.01 * j;
	//	if (T == 0.1 || T == 0.2 || T == 0.3 || T == 0.4 || T == 0.5) {
	//		//cout << "time is " << T << endl;
	//		//myfile << "time is" << T << "\n";

	//	}

	//	di_[1] = (Di[1] - ai * 149) / bi;

	//	//cout << Di_[621];
	//	for (int i = 2; i < 621; i++) {
	//		di_[i] = (Di[i] - ai * di_[i - 1]) / (bi - ai * ci_[i - 1]);
	//		//cout << Di_[i] << endl;
	//	}
	//	di_[619] = ((Di[619] - ai * 149) - ai * di_[618]) / (bi - ai * ci_[618]);

	//	nodetn[619] = di_[619];
	//	//cout << nodetn[619] << endl;

	//	if (T == 0.1 || T == 0.2 || T == 0.3 || T == 0.4 || T == 0.5) {
	//		cout << 619 << " " << nodetn[619] << endl;
	//		//myfile << nodetn[619] << "\n";
	//	}

	//	for (int i = 618; i > 0; i--) {
	//		nodetn[i] = di_[i] - ci_[i] * nodetn[i + 1];

	//		if (T == 0.1 || T == 0.2 || T == 0.3 || T == 0.4 || T == 0.5) {
	//			cout << i << " " << nodetn[i] << endl;
	//			//myfile << nodetn[i] << "\n";
	//		}

	//	}

	//	for (int i = 1; i < 622; i++) {
	//		nodetnmins1[i] = nodetn[i];
	//	}
	//	for (int i = 2; i < 622; i++) {
	//		Di[i] = (nodetnmins1[i + 1] - 2 * nodetnmins1[i] + nodetnmins1[i - 1]) + 2 * (DistanceX * DistanceX) * nodetnmins1[i] / (D * DistanceT);
	//	}
	//}

	//nodet0[1] = 149;
	//nodet1[1] = 149;

	//
	//
	////cout << ai << "  " << bi << "   " << ci << endl;



	//for (int n = 0; n < 621; n++) {
	//	if (n == 1) {
	//		ci_[n] = Ci_1(ci, bi);
	//		di_[n] = 149;
	//		cout << di_[n] << endl;
	//	}
	//	else if (n > 1) {
	//		ci_[n] = Ci_n(ci, bi, ai, ci_[n - 1]);
	//		di_[n] = Di_n(ai, bi, ci_[n - 1], Di[n], di_[n - 1]);
	//		nodet1[n] = di_[n] - ci_[n] * nodet1[n - 1];
	//		cout << nodet1[n] << endl;
	//	}

	//}

	////other note temperature
	//for (int i = 0; i < 621; i++) {
	//	nodetnmins1[i] = nodet1[i];
	//	
	//}

	//for (int j = 2; j < 51; j++) {
	//	double T=0;
	//	T = 0.01 * j;
	//	if (T == 0.1 || T == 0.2 || T == 0.3 || T == 0.4 || T == 0.5) {
	//		cout << "time is " << T << endl;
	//		myfile << "time is" << T << "\n";
	//	}
	//	
	//	for (int i = 1; i < 621; i++) {
	//		Di[i] = (nodetnmins1[i + 1] - 2 * nodetnmins1[i] + nodetnmins1[i - 1]) + 2 * (DistanceX * DistanceX) * nodetnmins1[i] / (D * DistanceT);
	//	}
	//	nodetn[1] = 149;

	//	for (int n = 0; n < 621; n++) {
	//		
	//		if (n == 1) {
	//			ci_[n] = Ci_1(ci, bi);
	//			di_[n] = 149;
	//			if (T == 0.1 || T == 0.2 || T == 0.3 || T == 0.4 || T == 0.5) {
	//				cout << di_[n] << endl;
	//				myfile << di_[n] << "\n";
	//			}
	//			//cout << di_[n] << endl;
	//		}
	//		else if (n > 1) {
	//			ci_[n] = Ci_n(ci, bi, ai, ci_[n - 1]);
	//			di_[n] = Di_n(ai, bi, ci_[n - 1], Di[n], di_[n - 1]);
	//			nodetn[n] = di_[n] - ci_[n] * nodet1[n - 1];
	//			T = 0.01 * j;
	//			
	//			if (T == 0.1 || T == 0.2 || T == 0.3 || T == 0.4 || T == 0.5) {
	//				cout << nodetn[n] << endl;
	//				myfile << nodetn[n] << "\n";
	//			}
	//		}

	//	}
	//	for (int i = 0; i < 621; i++) {
	//		nodetnmins1[i] = nodetn[i];
	//	}
	//}




	//return 0;
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

double Di_n(double ai, double bi, double ci_, double di, double di_0) {


	double di_ = (di - ai * di_0) / (bi - ai * ci_);
	return di_;
}
double Di(double Ti, double Tiplus1, double Timins1, double DistanceX, double DistanceT) {
	double di = (-Ti / (DistanceT)* D) - (Tiplus1 - 2 * Ti + Timins1) / (DistanceX * DistanceX);
	return di;
}