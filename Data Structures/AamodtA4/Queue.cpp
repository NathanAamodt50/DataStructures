#include <iostream>
#include <stdio.h>
#include <cstring>
#include "Queue.h"
using namespace std;
/*
Queue();
This function will create and initialize a empty queue
*/
Queue:: Queue() :front(NULL),back(NULL)
{
}
/*
    Queue(Queue & oldQ)
    This function will copy the queue into a new initalized queue
*/
Queue:: Queue(Queue & oldQ)
{
    QNodePtr QNode = NULL;
    QNode =oldQ.front;
    front = NULL;
    while(QNode)
    {
        enqueue(QNode->element);
        QNode = QNode->next;
    }
    QNode = NULL;

}
/*
    ~Queue()
    This function will delete the queue array and clear it
*/
Queue::~Queue()
{
    QNodePtr NodePtr = NULL;
    while(front)
    {
        NodePtr = front;
        front = NodePtr->next;
        NodePtr->next = NULL;
        delete NodePtr;

    }
}
/*
    enqueue(const Element e)
    This function calls the Queue into the function and inserts a new element into the back of the
    queue.
*/
void Queue::enqueue(const Element e)//adds element at back
{
	QNodePtr newNodePtr = NULL;
	newNodePtr = new (std::nothrow) QNode;

	if (!newNodePtr)
	{
		cerr << "Unable to create new node" << endl;
	}
	else if (!front)//front points at the first node of LinkedList
	{			  //back points at  the last node of Linked List
		strcpy(newNodePtr->element, e);
		newNodePtr->next = NULL;
		front = newNodePtr;
		back = newNodePtr;
	}
	else
	{
		newNodePtr->next = back;
		strcpy(newNodePtr->element, e);
		back = newNodePtr;
	}

}
/*
    dequeue(Element e)
    This function calls in the element and removes a element from the
    front of the queue
*/
void Queue::dequeue(Element e)//removes element from front
{

	QNodePtr nodePtr = NULL;

	if (!front)
	{
		cerr << "Memory not Allocated - No Delete" << endl;
	}
	else
	{
		nodePtr = front;
		front = front->next;
		nodePtr->next = NULL;
		strcpy(e, nodePtr->element);
		delete nodePtr;
	}
	nodePtr = NULL;


}
/*
    view()
    This function prints out whats in the queue
*/
void Queue::view()
{
    QNodePtr nodePtr = NULL;
    nodePtr = front;
    cout << "Front->";
    while(nodePtr)
    {
        cout << "->"<<nodePtr->element << endl;
        nodePtr = nodePtr->next;

    }
    cout << "Back" << endl;
    nodePtr = NULL;
}



