#define _CRT_SECURE_NO_WARNINGS

#ifndef UTILS_H
#define UTILS_H

#include <cstdio>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

void readArgs(int argc, char** argv, int &dataId, int &alpha, int &beta );

void readMatrix( int n, int dataId, vector< vector<double> > &mat );

void findRoute( const vector<int> &visited, vector<int> &route );

void printRoute( const vector< vector<double> > &adjMat, const vector<int> &route );

#endif