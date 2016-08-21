

#include <iostream>
using namespace std;

struct Node {
	int value;
	Node *next;
};

/* 
 * Queue 
 * 
 */ 

class Queue {
private:
	Node *front;
	Node *rear;

public:
	Queue();
	~Queue();
	void enqueue(int);
	int dequeue();
	bool isEmpty();
};

Queue::Queue() {
	front = NULL;
	rear = NULL;
}

Queue::~Queue(){
	delete front;
}

void Queue::enqueue(int value) {
	Node *temp = new Node();
	temp->value = value;
	
	//if queue is empty
	if(front == NULL) front = temp;
	else {
		//add at the end of the queue
		rear->next = temp;
	}
	rear = temp;
	delete temp;
}

int Queue::dequeue(){
	int value;
	if ( this->isEmpty() ) cout <<"Nothing to dequeue." ;
	else {
		Node *temp = new Node();
		temp = front;
		value = temp->value;
		front = front->next;
		delete front;
	}
	return value;
}

bool Queue::isEmpty() {
	return (front == NULL);
}


/* 
 * Graph [V,E]
 * vertices V, edges E 
 *
 */

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


//@param s: start vertex
void Graph::BFS(int s) {
	Queue Q;
	bool visited = new bool [];

	//initialize all vertices unvisited
	for (int i = 0; i<size; i++ ) {
		visited[i] = false;
	}

	//Visit the first vertex, add to queue. 
	cout << s.value << " " ;
	Q.enqueue(s);
	visited[s] = true;


	while( !(Q.isEmpty) ) {

		// pop, visit, mark
		int v = Q.dequeue();
		cout << v.value << " "  ;
		visited[v] = true; 

		for (int w = 0; w < n; w++ ) {
			if (isConnected(v,w) && !visited[w] ) {
				// queue all children. mark. 
				Q.enqueue(w);
				visited[w] = true;
			}
		}

	}
}






























