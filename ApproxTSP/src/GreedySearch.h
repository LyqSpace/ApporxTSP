#ifndef GREEDYSEARCH_H
#define GREEDYSEARCH_H

#include <vector>
#include <iostream>
#include "utils.h"

using namespace std;

class GreedySearch {

private:
	vector< vector<double> > adjMat;
	int N;
	int alpha, beta;

public:
	vector<int> bestRoute;

	GreedySearch( const vector< vector<double> > &_adjMat, int _N, int _alpha, int _beta );
	void search();

};

#endif