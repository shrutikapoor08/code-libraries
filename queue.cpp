/****************************************************************
 
Queue implementation
Author: Shruti Kapoor
 
****************************************************************/


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

bool Queue::isEmpty() {
	return (front==NULL);
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

