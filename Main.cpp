
#include "DuFortFrankel.h"
#include "CrankNicholson.h"
#include "LaasonenSimoleImplicit.h"

int main() {
	 //DufortFrankel(93,0.01,0.05);
	//CrankNicholson(0.01, 0.05);
	Lassonen(0.01, 0.05);
	return 0;
}