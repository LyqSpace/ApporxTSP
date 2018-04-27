#include "utils.h"

void readArgs( int argc, char** argv, int &dataId, int &alpha, int &beta ) {

	if ( argc >= 2 ) {
		dataId = atoi( argv[1] );
		if ( dataId <= 0 || dataId > 4 ) {
			cerr << "DataId must be in [1, 4]" << endl;
			exit( 1 );
		}
	}

	if ( argc >= 3 ) {
		alpha = atoi( argv[2] );
	}

	if ( argc >= 4 ) {
		beta = atoi( argv[3] );
	}

}

void readMatrix( int n, int dataId, vector< vector<double> > &mat ) {

	string fileName = "data/real/" + to_string( dataId ) + "/output" + to_string( dataId ) + ".txt";
	FILE *file = fopen( fileName.c_str(), "r" );

	mat = vector< vector<double> >( n );
	for ( int r = 0; r < n; r++ ) {
		mat[r] = vector<double>( n );
		for ( int c = 0; c < n; c++ ) {
			fscanf( file, "%lf", &mat[r][c] );
		}
	}

	fclose( file );

}

void findRoute( const vector<int> &visited, vector<int> &route ) {

	route.clear();
	int N = visited.size();

	for ( int i = 0; i < N; i++ ) {
		for ( int j = 0; j < N; j++ ) {
			if ( visited[j] == i ) route.push_back( j );
		}
	}

}

void printRoute( const vector< vector<double> > &adjMat, const vector<int> &route ) {

	double cumConf = 0;

	cout << "Route: " << route[0];
	for ( size_t i = 1; i < route.size(); i++ ) {
		cumConf += adjMat[i - 1][i];
		cout << " " << route[i];
	}
	cout << endl;
	printf( "Confidence: %.10lf\n\n", cumConf );

}