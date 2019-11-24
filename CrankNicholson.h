#pragma once
void CrankNicholson(double DistanceT, double DistanceX);
//double secondNode(double DistanceT, double DistanceX, double Tin, double Tinplus1, double Tiplus1n);
//double ComputeNode(double DistanceT, double DistanceX, double Tin, double Tinplus1, double Tiplus1n, double Timins1n, double Timins1nplus1);
double Ci_1(double ci, double bi);
double Ci_n(double ci, double bi, double ai, double ci_0);
double Di_1(double di, double bi);
double Di_n(double ai, double bi, double ci_, double di, double di_0);
double Di(double Ti, double Tiplus1, double Timins1, double DistanceX, double DistanceT);