#include "Node.h"

Node::Node( int _nodeId, const vector<int> &_visited, int _depth, double _cumConf, double _furtherConf ) {
	nodeId = _nodeId;
	depth = _depth;
	cumConf = _cumConf;
	visited = _visited;
	furtherConf = _furtherConf;
}

bool cmpNodesEvalConf( const Node &node0, const Node &node1 ) {
	return node0.evalConf > node1.evalConf;
}