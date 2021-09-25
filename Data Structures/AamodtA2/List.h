#ifndef _LIST_H
#define _LIST_H

typedef int Element;

class List {
public:
	List();
	List(const List&);
		~List();
		void add(const Element);
		void remove(const Element);
		void view() const;
		void viewR() const;
private:
	struct ListNode;
	typedef ListNode *ListNodePtr;
	struct ListNode {
		Element element;
		ListNodePtr next;

	};
	ListNodePtr head;
	void viewR(const ListNodePtr) const;
};
#endif


