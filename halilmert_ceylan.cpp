#include <iostream>
#include "LinkedList.h"
#include <cassert>

using namespace std;

int main()
{
	int i=0, k;
	LinkedList <int> *list = new LinkedList<int>;
	
	list->insert_last(5);
	list->insert_last(4);
	list->insert_last(5);
	
	list->show_half();
}
