#include "AlphaBetaPruning.h"

AlphaBetaPruning::AlphaBetaPruning( const vector< vector<double> > &_adjMat, int _N, int _alpha, int _beta ) {

	cout << "Alpha-Beta Pruning: " << endl;

	adjMat = _adjMat;
	N = _N;
	alpha = _alpha;
	beta = _beta;
}

double AlphaBetaPruning::evalNode( Node rootNode ) {

	double maxConf = 0;
	queue<Node> que;
	rootNode.cumConf = 0;
	que.push( rootNode );

	while ( !que.empty() ) {
		Node curNode = que.front();
		que.pop();

		for ( int i = 0; i < N; i++ ) {
			if ( curNode.visited[i] != -1 ) continue;
			
			double cumConf = curNode.cumConf + adjMat[curNode.nodeId][i];

			// debug
			// cout << curNode.depth << " " << cumConf << " " << curNode.nodeId << " -> " << i << endl;

			if ( curNode.depth + 1 == N || curNode.depth + 1 - rootNode.depth == beta ) {
				maxConf = max( maxConf, cumConf );
			} else {
				vector<int> nextVisited = curNode.visited;
				nextVisited[i] = curNode.depth + 1;
				Node nextNode = Node( i, nextVisited, curNode.depth + 1, cumConf );
				que.push( nextNode );
			}
		}

	}

	return maxConf;

}

void AlphaBetaPruning::search() {

	double maxConf = 0;
	vector<int> bestVisited;
	queue<Node> que;

	for ( int i = 0; i < N; i++ ) {
		vector<int> visited = vector<int>( N, -1 );
		visited[i] = 0;
		Node node = Node( i, visited );
		que.push( node );
	}

	vector<Node> nextNodes;

	for ( int depth = 1; depth < N; depth++ ) {

		nextNodes.clear();

		while ( !que.empty() ) {
			Node curNode = que.front();
			que.pop();

			if ( curNode.depth == N ) {
				if ( maxConf < curNode.cumConf ) {
					maxConf = curNode.cumConf;
					bestVisited = curNode.visited;
				}
				continue;
			}

			for ( int i = 0; i < N; i++ ) {
				if ( curNode.visited[i] != -1 ) continue;

				double cumConf = curNode.cumConf + adjMat[curNode.nodeId][i];
				vector<int> nextVisited = curNode.visited;
				nextVisited[i] = curNode.depth + 1;

				Node nextNode = Node( i, nextVisited, curNode.depth + 1, cumConf );
				nextNode.furtherConf = evalNode( nextNode );
				nextNode.evalConf = nextNode.cumConf + nextNode.furtherConf;

				nextNodes.push_back( nextNode );

			}

		}

		sort( nextNodes.begin(), nextNodes.end(), cmpNodesEvalConf );

		for ( int i = 0; i < min(alpha, (int)nextNodes.size()); i++ ) {
			que.push( nextNodes[i] );
		}

	}

	findRoute( que.front().visited, bestRoute );

}
