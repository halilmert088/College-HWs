#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

class Parent{
	protected:
		int a;
		int b;
	public:
		Parent()
		{
			cout<<"Parent created"<<endl;
		}
		
		virtual void print()
		{
			cout<<"Parent printed"<<endl;
		}
		
		~Parent()
		{
			cout<<"Parent destroyed"<<endl;
		}
};

class Child : public Parent{
	public:
		Child()
		{
			cout<<"Child created"<<endl;
		}
		
		virtual void print()
		{
			cout<<"Child printed"<<endl;
		}
		
		~Child()
		{
			cout<<"Child destroyed"<<endl;
		}
};

class Child1 : public Child{
	public:
		Child1()
		{
			cout<<"Child1 created"<<endl;
		}
		
		void print()
		{
			cout<<"Child1 printed"<<endl;
		}
		
		~Child1()
		{
			cout<<"Child1 destroyed"<<endl;
		}
};

main()
{
	Child1 *ptr;
	ptr = new Child1;
	ptr->print();
	delete ptr; 
}
