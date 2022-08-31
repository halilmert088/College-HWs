#include <iostream>
#include "LinkedList.h"
#include <cassert>

using namespace std;

void altiBol(int n)
{
	if(n > 0)
	{	
		if(n%6 == 0)
		{
			cout<<n<<" ";
		}
		
		altiBol(n-1);
	}
}

int main()
{
	altiBol(37);
}
