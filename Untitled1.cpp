#include <iostream>

using namespace std;
void test (int a, int b, int c)
{
	cout<<a<<" "<<b<<" "<<c;
}

int main()
{
	int k = 5;
	test(k, ++k, k++);
}
