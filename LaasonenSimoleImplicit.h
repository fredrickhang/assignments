#pragma once
//double secondNode(double Tn, double Tnplus1, double DistanceT, double DistanceX);
//double ComputeNode(double DistanceT, double DistanceX, double Tinplus1, double Tin, double Timins1nplus1);
void Lassonen(double DistanceT, double DistanceX,double nodet1[622]);
double Ci_1L(double ci, double bi);
double Ci_nL(double ci, double bi, double ai, double ci_0);
double Di_1L(double di, double bi);
double Di_nL(double ai, double bi, double ci_, double di, double di_0);