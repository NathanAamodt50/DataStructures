#include <iostream>
#include <iomanip>
#include <cstring>
#include  "List.h"
using namespace std;


void List::add(const Element number)
{
	ListNodePtr newNodePtr = NULL;
	ListNodePtr nodePtr = NULL;
	ListNodePtr previousNodeptr = NULL;

	newNodePtr = new (std::nothrow) ListNode;
	if (!newNodePtr) {
		cerr << "Unable to create New Node" << endl;
	}
	else {
		nodePtr = head;
		while ((nodePtr) && (nodePtr->element < number)) {
			previousNodeptr = nodePtr;
			nodePtr = nodePtr->next;
		}
		if (!previousNodeptr) {
			head = newNodePtr;
			newNodePtr->next = nodePtr;
		}
		else {
			previousNodeptr->next = newNodePtr;
			newNodePtr->next = nodePtr;
		}
	}

}

void List ::remove(const Element number) {
	ListNodePtr nodePtr = NULL;
	ListNodePtr previousNodePtr = NULL;

	if (!head) {
		cerr << "Memory Not Allocated- No Delete" << endl;
	}
	else {
		if (head->element == number) {
			nodePtr = head;
			head = head->next;
			nodePtr->next = NULL;
			delete nodePtr;
		}
		else {
			nodePtr = head;
			while ((nodePtr) && (nodePtr->element != number)) {
				previousNodePtr = nodePtr;
				nodePtr = nodePtr->next;
			}
			if (nodePtr) {
				previousNodePtr->next = nodePtr->next;
				nodePtr->next = NULL;
				delete nodePtr;
			}
			else {
				cerr << number << " Not Found - No Delete" << endl;
			}
		}
	}
}

List::List() : head(NULL){
}

List::List(const List & oldList){
    ListNodePtr holdPtr = NULL;
    holdPtr = oldList.head;
    head = NULL;
     while(holdPtr){
         add(holdPtr->element);
         holdPtr = holdPtr->next;
     }
    holdPtr = NULL;
}

void List::view() const{
    ListNodePtr nodePtr = NULL;
    nodePtr = head;
    cout << "HEAD->";
    while(nodePtr)
    {
        cout << nodePtr->element << "->";
        nodePtr = nodePtr->next;

    }
    cout << "NULL" << endl;
    nodePtr = NULL;
}

List::~List(){
    ListNodePtr nodePtr = NULL;
    while(head){
        nodePtr = head;
        head = nodePtr->next;
        nodePtr->next = NULL;
        delete nodePtr;
    }
    nodePtr = NULL;
}

void List::viewR() const{
    ListNodePtr nodePtr = NULL;
    nodePtr = head;
    if(!head)
        cout << "NULL";
    else
    {
        viewR(nodePtr->next);
        cout << "<-" << nodePtr->element;
    }
    cout << "<-HEAD" << endl;
    nodePtr = NULL;
}

void List::viewR(const ListNodePtr nodePtr) const{
    if(!nodePtr)
        cout << "NULL";
    else
    {
        viewR(nodePtr->next);
        cout << "<-" << nodePtr->element;
    }
}
