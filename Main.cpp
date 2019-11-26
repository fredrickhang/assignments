
#include "DuFortFrankel.h"
#include "CrankNicholson.h"
#include "LaasonenSimoleImplicit.h"
#include "Richardson.h"
#include "ASolution.cpp"
#include<iostream>


int main() {
	DufortFrankel( 93,0.01,0.05); 
	//Richardson(0.0093, 0.01, 0.05);
	CrankNicholson(0.01, 0.05);
	//Lassonen(0.01, 0.05);
	
	//a = nextNode(149, 38, 38, 0.0093, 0.01, 0.05);

	//std::cout<<a;
	//ASolution(149,38,93,5000,31,0.01,0.05);
	//const int pi = 3.1415926;
	//int a = 0;
	//a = pow(-1, 3);
	//std::cout << a;
	return 0;
}