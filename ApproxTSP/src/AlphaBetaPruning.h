#ifndef ALPHABETAPRUNING_H
#define ALPHABETAPRUNING_H

#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <ctime>
#include "Node.h"
#include "utils.h"

using namespace std;

class AlphaBetaPruning {

private:
	vector< vector<double> > adjMat;
	int N;
	int alpha, beta;

	double evalNode( Node curNode );

public:
	vector<int> bestRoute;

	AlphaBetaPruning( const vector< vector<double> > &_adjMat, int _N, int _alpha, int _beta );
	void search();
	void printBestRoute();

};

#endif