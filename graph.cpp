/****************************************************************
 
Graph implementation
Author: Shruti Kapoor
 
****************************************************************/



#include <iostream>
using namespace std;


class Graph {
	public:
		Graph(int size = 2);
		~Graph();
		addEdge(int u, int v);
		bool isConnected(int u, int v);
		void BFS(int u);

	private:
		int n; // number of vertices. 
		int **A; //adjacency matrix. 
};

Graph::Graph(int size) {
	int i,j;

	if(size < 2 ) {
		//graph with less than two vertices not possible
		n = 2;	
	} 
	else n = size;

	A = new int *[n];

	for (int i = 0; i< n ; i++ ){
		 A[i] = new int[n];
		for (int j=0; j< i; j++) {
			A[i][j] = 0;
		}
	}
}

Graph::~Graph() {
	for(int i=0; i< n ; i++ ){
		delete [] A[i];
		delete [] A;
	}
}

void Graph::addEdge(int u, int v) {
	A[u][v] = A[v][u] = 1;
}

bool Graph::isConnected(int u, int v) {
	return (A[u][v] == 1);
}



