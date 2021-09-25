#include <iostream>
#include "List.h"
using namespace std;

int main() {
	List list;

	list.add(10);
	list.add(12);

	list.view();
	cout << endl;

	list.remove(12);

	list.view();
	cout << endl;

	return 0;
}
