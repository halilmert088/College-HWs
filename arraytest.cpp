#include <iostream>

using namespace std;

int *arr;

int main ()
{
	arr = new int [2];
	arr[0]=15;
	arr[1]=7811;
	cout<<arr[2]<<endl;
	
	int *two = new int [3];
	
	for(int i=0; i < 2; i++)
	{
		two[i] = arr[i];
	}
	
	delete arr;
	arr = two;
	
	arr[2] = 5;
	cout<<arr [2];
	
	return 0;
}
