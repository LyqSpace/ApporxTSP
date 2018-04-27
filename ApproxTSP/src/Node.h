#ifndef NODE_H
#define NODE_H

#include <vector>

using namespace std;

class Node {

public:
	int nodeId;
	int depth;
	double cumConf, furtherConf, evalConf;
	vector<int> visited;

	Node::Node( int _nodeId, const vector<int> &_visited, int _depth = 0, double _cumConf = 0, double _furtherConf = 0 );

};

bool cmpNodesEvalConf( const Node &node0, const Node &node1 );

#endif