#include <iostream>
#include <string>
using namespace std;

bool search (int arr1[], int arr2[])
{
	int size1 = sizeof(arr1)/sizeof(arr1[0]);
	int size2 = sizeof(arr2)/sizeof(arr2[0]);
	bool found = false;
	
	cout << sizeof(arr1)/sizeof(arr1[0]) << " " << sizeof(arr2)/sizeof (arr2[0]) << endl;
	
	for(int a=0; a<size1; a++)
	{
		if(a != 0)
		{
			if (found == false)
				break;
		}	
		
		for(int b=0; b<size2; b++)
		{
			if(arr1[a] == arr2[b])
			{
				found = true;
				break;
			}
			
			if(found == true)
			{
				break;
			}
		}
		
		if(found == false)
		{
			break;
		}
	}
	
	return found; 
}



int main(void)
{
	int arr1 [4] = {5, 7, 9, 10};
	int arr2 [11] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
	
	cout << sizeof(arr1)/sizeof(arr1[0]) << " " << sizeof(arr2) / sizeof (arr2[0]) << endl;
	
	bool test = search(arr1, arr2);
	
	if(test == true)
		cout <<"arr1 is in arr2";
	if(test == false)
		cout <<"arr1 is not in arr2";
		
	return 0;
}
