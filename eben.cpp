#include <iostream>
using namespace std;

int main ()
{
	int array [3] = {1, 2, 3};
	cout<<sizeof(array)/sizeof(array[0]);
	return 0;
}
