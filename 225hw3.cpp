//HALÝL MERT CEYLAN, CMPE, 18243510049
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class InsufficentDeposit{
};

class BankAccount{
	private:
		int account_id;
		string name;
		float deposit;
	protected:
		float interest_rate;
	public:
		BankAccount(int a=0, string b=" ", float c=0, float d=0)
		{
			account_id=a;
			name=b;
			deposit=c;
			interest_rate=d;
		}
		
		virtual void save()
		{
			ofstream myfile;
			myfile.open(name.c_str(), ios::binary);
			
			struct data
			{
				int a;
				string b;
				float c;
				float d;
			};
			data dummy;
			
			dummy.a=account_id;
			dummy.b=name;
			dummy.c=deposit;
			dummy.d=interest_rate;
			
			myfile.write((const char*) &dummy, sizeof(dummy));
			myfile.close();
		}
		
		void load(string file_name)
		{
			ifstream myfile;
			myfile.open(file_name.c_str(), ios::binary);
			
			struct data
			{
				int a;
				string b;
				float c;
				float d;
			};
			data dummy;			
			
			myfile.read((char*) &dummy, sizeof(dummy));
			myfile.close();
			
			account_id=dummy.a;
			name=dummy.b;
			deposit=dummy.c;
			interest_rate=dummy.d;
		}
        
		float draw (float amount)
        {
        	try
        	{
        		if(amount < deposit)
        		{
        			deposit -= amount;
				}
				
				else
				{
					InsufficentDeposit *k = new InsufficentDeposit;
					throw k;
				}
			}
			
			catch(InsufficentDeposit *k)
			{
				cerr<<"InsufficentDeposit exception caught"<<endl<<endl;
			}
			return 0;
		}
		
		void apply_interest()
		{
			deposit += ((deposit * interest_rate)/100);
		}
		
		virtual const void report ()
		{
			cout<<"Account ID: "<<account_id<<endl;
			cout<<"Account name: "<<name<<endl;
			cout<<"Deposit: "<<deposit<<endl;
			cout<<"Interest rate: %"<<interest_rate<<endl;
		}
};

class PersonalBankAccount : public BankAccount{
	private:
		int account_id;
		string name;
		float deposit;
	protected:
		float interest_rate;
	public:
	    PersonalBankAccount(int a=0, string b=" ", float c=0, float d=18)
		{
			account_id=a;
			name=b;
			deposit=c;
			interest_rate=d;
		}
		
		void save()
		{
			ofstream myfile;
			myfile.open(name.c_str(), ios::binary);
			
			struct data
			{
				int a;
				string b;
				float c;
				float d;
			};
			data dummy;
			
			dummy.a=account_id;
			dummy.b=name;
			dummy.c=deposit;
			dummy.d=interest_rate;
			
			myfile.write((const char*) &dummy, sizeof(dummy));
			myfile.close();
		}
		
		void load(string file_name)
		{
			ifstream myfile;
			myfile.open(file_name.c_str(), ios::binary);
			
			struct data
			{
				int a;
				string b;
				float c;
				float d;
			};
			data dummy;			
			
			myfile.read((char*) &dummy, sizeof(dummy));
			myfile.close();
			
			account_id=dummy.a;
			name=dummy.b;
			deposit=dummy.c;
			interest_rate=dummy.d;
		}
		
        float draw (float amount)
        {
        	try
        	{
        		if(amount < deposit)
        		{
        			deposit -= amount;
				}
				
				else
				{
					InsufficentDeposit *k = new InsufficentDeposit;
					throw k;
				}
			}
			
			catch(InsufficentDeposit *k)
			{
				cerr<<"InsufficentDeposit exception caught"<<endl<<endl;
			}
			return 0;
		}
		
		void apply_interest()
		{
			deposit += ((deposit * interest_rate)/100);
		}
		
		const void report ()
		{
			cout<<"TYPE: PERSONAL"<<endl;
			cout<<"=============="<<endl;
			cout<<"Account ID: "<<account_id<<endl;
			cout<<"Account name: "<<name<<endl;
			cout<<"Deposit: "<<deposit<<endl;
			cout<<"Interest rate: %"<<interest_rate<<endl;
		}
};

class BusinessBankAccount : public BankAccount{
	private:
		int account_id;
		string name;
		float deposit;
	protected:
		float interest_rate;
	public:
		BusinessBankAccount(int a=0, string b=" ", float c=0, float d=6.50)
		{
			account_id=a;
			name=b;
			deposit=c;
			interest_rate=d;
		}
		
		void save()
		{
			ofstream myfile;
			myfile.open(name.c_str(), ios::binary);
			
			struct data
			{
				int a;
				string b;
				float c;
				float d;
			};
			data dummy;
			
			dummy.a=account_id;
			dummy.b=name;
			dummy.c=deposit;
			dummy.d=interest_rate;
			
			myfile.write((const char*) &dummy, sizeof(dummy));
			myfile.close();
		}
		
		void load(string file_name)
		{
			ifstream myfile;
			myfile.open(file_name.c_str(), ios::binary);
			
			struct data
			{
				int a;
				string b;
				float c;
				float d;
			};
			data dummy;
			
			myfile.read((char*) &dummy, sizeof(dummy));
			myfile.close();
			
			account_id=dummy.a;
			name=dummy.b;
			deposit=dummy.c;
			interest_rate=dummy.d;
		}
		
        float draw (float amount)
        {
        	try
        	{
        		if(amount < deposit)
        		{
        			deposit -= amount;
				}
				
				else
				{
					InsufficentDeposit *k = new InsufficentDeposit;
					throw k;
				}
			}
			
			catch(InsufficentDeposit *k)
			{
				cerr<<"InsufficentDeposit exception caught"<<endl<<endl;
			}
			return 0;
		}
		
		void apply_interest()
		{
			deposit += ((deposit * interest_rate)/100);
		}
		
		const void report ()
		{
			cout<<"TYPE: BUSINESS"<<endl;
			cout<<"=============="<<endl;
			cout<<"Account ID: "<<account_id<<endl;
			cout<<"Account name: "<<name<<endl;
			cout<<"Deposit: "<<deposit<<endl;
			cout<<"Interest rate: %"<<interest_rate<<endl;
		}
};

main()
{
	PersonalBankAccount obj1 (5421, "PersonalAcc1", 2000);
	PersonalBankAccount obj2 (1234, "PersonalAcc2", 3000);
	BusinessBankAccount obj3 (5678, "BusinessAcc", 4000);
	
	obj1.apply_interest();
	obj2.apply_interest();
	obj3.apply_interest();
	
	obj1.save();
	obj2.save();
	obj3.save();
	
    cout<<"======Before swapping accounts======"<<endl;
	
	obj1.report();
	cout<<endl;
	
	obj2.report();
	cout<<endl;
	
	obj3.report();
	cout<<endl;
	
	obj2.load("PersonalAcc1");
	obj1.load("PersonalAcc2");
	
	cout<<"======After swapping accounts======"<<endl;
	
	obj1.report();
	cout<<endl;
	
	obj2.report();
	cout<<endl;
	
	obj3.draw(4300);
	
	obj3.report();
	cout<<endl;
}
