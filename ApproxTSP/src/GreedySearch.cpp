#include "GreedySearch.h"

GreedySearch::GreedySearch( const vector< vector<double> > &_adjMat, int _N, int _alpha, int _beta ) {

	cout << "Greedy Search: " << endl;

	adjMat = _adjMat;
	N = _N;
	alpha = _alpha;
	beta = _beta;

}

void GreedySearch::search() {

	double bestConf = 0;
	vector<int> bestVisited;

	for ( int i = 0; i < N; i++ ) {

		vector<int> visited = vector<int>( N, -1 );
		visited[i] = 0;
		double cumConf = 0;
		int curNode = i;

		for ( int depth = 1; depth < N; depth++ ) {

			double maxConf = 0;
			int maxNode = -1;

			for ( int j = 0; j < N; j++ ) {
				if ( visited[j] != -1 ) continue;
				if ( maxConf < adjMat[curNode][j] ) {
					maxConf = adjMat[curNode][j];
					maxNode = j;
				}
			}

			visited[maxNode] = depth;
			cumConf += maxConf;
			curNode = maxNode;

		}

		if ( bestConf < cumConf ) {
			bestConf = cumConf;
			bestVisited = visited;
		}

	}

	findRoute( bestVisited, bestRoute );

}
