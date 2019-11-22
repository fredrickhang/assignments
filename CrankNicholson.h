#pragma once
void CrankNicholson(double DistanceT, double DistanceX);
double secondNode(double DistanceT, double DistanceX, double Tin, double Tinplus1, double Tiplus1n);
double ComputeNode(double DistanceT, double DistanceX, double Tin, double Tinplus1, double Tiplus1n, double Timins1n, double Timins1nplus1);