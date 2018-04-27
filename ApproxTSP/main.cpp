#include <iostream>
#include <vector>
#include "src/utils.h"
#include "src/AlphaBetaPruning.h"
#include "src/GreedySearch.h"

using namespace std;

int main(int argc, char** argv) {

	const int N[4] = { 7, 10, 12, 18 };
	int dataId = 1;
	int alpha = 100;
	int beta = 2;

	readArgs( argc, argv, dataId, alpha, beta );
	// debug
	// cout << dataId << " " << alpha << " " << beta << endl;

	vector< vector<double> > adjMat;
	readMatrix( N[dataId-1], dataId, adjMat );

	cout << "Greedy Search: " << endl;
	GreedySearch greedySearch = GreedySearch( adjMat, N[dataId - 1], alpha, beta );
	greedySearch.search();
	printRoute( adjMat, greedySearch.bestRoute );

	cout << "Alpha-Beta Pruning: " << endl;
	AlphaBetaPruning alphaBetaPruning = AlphaBetaPruning( adjMat, N[dataId - 1], alpha, beta );
	alphaBetaPruning.search();
	printRoute( adjMat, alphaBetaPruning.bestRoute );

	system( "pause" );

	return 0;

}