#include <iostream>

using namespace std;

class Account{
	private:
		const int account_no=1234567890;
		string name;
		float balance;
	public:
		void read();
		const void print_details();
		void deposit (float dep);
};

void Account::read()
{
	cout<<"Please input customer name: ";
	cin>>name;
	cout<<endl<<endl;
	
	cout<<"Please input balance: $ ";
	cin>>balance;
	cout<<endl<<endl;
}

void Account::deposit(float dep)
{
	balance+=dep;
}

const void Account::print_details()
{
	cout<<"The account no is: "<<account_no<<endl;
	cout<<"The customer name: "<<name<<endl;
	cout<<"Your new balance is $ "<<balance;
}

main()
{
	Account a;
	a.read();
	a.deposit(3000);
	a.print_details();
}
