#include <iostream>
#include "list.h"
using namespace std;

int main()
{
	List LL;

	LL.createList(8);

	cout << "forwards: "; LL.display(false);
	cout << "backwards: "; LL.display(true);
}