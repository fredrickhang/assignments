
#include "DuFortFrankel.h"
#include "CrankNicholson.h"
#include "LaasonenSimoleImplicit.h"
#include "Richardson.h"
#include<iostream>


int main() {
	//DufortFrankel( 0.0093,0.01,0.05);
	Richardson(0.0093, 0.01, 0.05);
	//CrankNicholson(0.01, 0.05);
	//Lassonen(0.01, 0.05);
	
	//a = nextNode(149, 38, 38, 0.0093, 0.01, 0.05);
	//std::cout<<a;
	return 0;
}