#pragma once
double computeNodeR(double iBackwordn, double inBackword, double iForwardn, double D, double deltaT, double deltaX);
double nextNodeR(double in, double iForwardn, double iBackwardn, double D, double deltaT, double deltaX);

void Richardson(double D, double deltaT, double deltaX);