#pragma once
double computeNodeR(double iBackwardn, double in, double iForwardn, double nBackwardi, double D, double deltaT, double deltaX);
double nextNodeR(double in, double iForwardn, double iBackwardn, double D, double deltaT, double deltaX);

void Richardson(double D, double deltaT, double deltaX);