#include <iostream>
#include <vector>
#include "src/utils.h"
#include "src/AlphaBetaPruning.h"
#include "src/GreedySearch.h"

using namespace std;

int main(int argc, char** argv) {

	const int N[4] = { 7, 10, 12, 18 };
	int dataId = 1;
	int alpha = 50;
	int beta = 2;

	readArgs( argc, argv, dataId, alpha, beta );

	vector< vector<double> > adjMat;
	readMatrix( N[dataId-1], dataId, adjMat );

	GreedySearch greedySearch = GreedySearch( adjMat, N[dataId - 1], alpha, beta );
	greedySearch.search();
	printRoute( adjMat, greedySearch.bestRoute );

	AlphaBetaPruning alphaBetaPruning = AlphaBetaPruning( adjMat, N[dataId - 1], alpha, beta );
	alphaBetaPruning.search();
	printRoute( adjMat, alphaBetaPruning.bestRoute );

	if ( dataId < 4 ) {
		showSolution( N[dataId - 1], dataId );
	} else {
		cout << "Standard Solution: Unknown" << endl << endl;
	}

	system( "pause" );

	return 0;

}