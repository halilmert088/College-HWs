#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <math.h>

using namespace std;

class MathProblem{
	protected:
		bool ans;
	public:
		virtual void isanswercorrect (bool answer)
		{
			ans=true or false;
		};
		
		virtual void setproblem ()=0;
		virtual void askuseranswer()=0;
		virtual void displayproblem()=0;
};

class IntegerProblem: public MathProblem{
	protected:
		int num1, num2, correctanswer, useranswer;
		bool ans;
	public:
		void setproblem()
		{
		    srand(time(0));
			
			int a= rand()%100+1;
			num1=a;
			
			int b= rand()%100+1;
			num2=b;
			
			correctanswer=num1+num2;
		}
		
		void displayproblem()
		{
			std::cout<<"What is "<<num1<<" + "<<num2<<"?"<<std::endl;
		}
		
		void askuseranswer()
		{
		    cout<<"Answer: ";
		    cin>>useranswer;
		    
			if(useranswer==correctanswer)
		    {
		    	cout<<"Good job!"<<endl<<endl;
			}
		    else
		    {
		    	cout<<"Sorry! The answer is "<<correctanswer<<endl<<endl;
			}
		}
		
		void isanswercorrect(bool answer)
		{
			if(useranswer==correctanswer)
			answer=true;
			
			else
			answer=false;
		}
};

class FractionProblem : public MathProblem{
	protected:
		int n1, d1;
		int n2, d2;
		int corrn, corrd;
		int usern, userd;
	public:
		void setproblem()
		{
			srand(time(0));
			n1=rand()%100+1;
			n2=rand()%100+1;
			d1=rand()%100+1;
			d2=rand()%100+1;
			
			corrn=n1+n2;
			corrd=d1+d2;
		}
		
		void displayproblem()
		{
			cout<<"What is "<<n1<<"/"<<d1<<" + "<<n2<<"/"<<d2<<" ?"<<endl;
		}
		
		void askuseranswer()
		{
			char slash;
			cout<<"Enter numerator:  ";
			cin>>usern;
			cin>>slash;
			cin>>userd;
			
			if((corrn==usern || corrn % usern == 0) && (corrd==userd || corrd % userd == 0))
			{
				cout<<"Good job!"<<endl<<endl;
			}
			else
			{
				cout<<"Sorry! The answer is "<<corrd<<"/"<<corrn<<endl<<endl;
			}
		}
		
		void isanswercorrect (bool answer)
		{
			if(usern==corrn && userd==corrd)
			answer=true;
			
			else
			answer = false;
		}		
};

main()
{
	int k;
	bool ans;
	MathProblem *a;
	a=new IntegerProblem;
	
	do{
		cout<<"Please choose type of addition problem: "<<endl;
		cout<<" 1. Fraction"<<endl;
		cout<<" 2. Integer"<<endl;
		cout<<" 3. Quit"<<endl;
		cout<<"Choice: ";
		cin>>k;
		
		if(k==1)
		{
			a=new FractionProblem;
			a->setproblem();
			a->displayproblem();
			a->askuseranswer();
			a->isanswercorrect(ans);
		}
		
				if(k==2)
		{
			a=new IntegerProblem;
			a->setproblem();
			a->displayproblem();
			a->askuseranswer();
			a->isanswercorrect(ans);
		}
	}while(k!=3);
	
	delete a;
}


