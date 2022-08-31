#include <iostream>

using namespace std;

class calculator
{
	public:
		int a, b;
		add(){return a+b;};
		sub(){return a-b};
		div(){if(a!=0 && b!=0)
		return a/b;};
		mult(){return a*b;};
};

main()
{
	calculator calc;
	char op;
	
	cout<<"Enter the numbers: ";
	cin>>calculator.a>>calculator.b;
	
	cout<<"Enter the operator: ";
	cin>>op;
	
	cout<<"The result is ";
	if(op=='+')
	{
		cout<<add()<<endl;
	}
	
	if(op=='-')
	{
		cout<<sub()<<endl;
	}
	
	if(op=='/')
	{
		cout<<div()<<endl;
	}
	
	if(op=='*')
	{
		cout<<mult()<<endl;
	}
}
