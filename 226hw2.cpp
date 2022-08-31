#include <iostream>
#include <cassert>
#include <fstream>
#include "Stack.h"
#include "LinkedQueue.h"

using namespace std;

class Passengers{
public:
	string name;
	string surname;
	string destination;
	
	friend ostream &operator << (ostream &o, const Passengers &p);
	friend istream &operator >> ( istream  &i, Passengers &p );
};


istream &operator >> (istream &i, Passengers &p)
{ 
   	i >> p.name >> p.surname >> p.destination;
    return i;            
}

ostream &operator << (ostream &o, const Passengers &p)
{
	o << p.name << " " << p.surname << " " << p.destination;
	return o; 
}


int main()
{
	LinkedQueue <Passengers> p_list;
	int size_an, size_ist, size_ad;
	
	//Gets the train sizes from the user and creates stacks of that size
	
	cout<<"Enter the capacity of the Ankara train: ";
	cin>>size_an;
	Stack <Passengers> ankara (size_an);
	
	cout<<"Enter the capacity of the Istanbul train: ";
	cin>>size_ist;
	Stack <Passengers> istanbul (size_ist);
	
	cout<<"Enter the capacity of the Adana train: ";
	cin>>size_ad;
	Stack <Passengers> adana (size_ad);
	
	//Gets the list of passengers from file and adds it to a the queue
	
	ifstream myFile;
	myFile.open("file.txt", ios::binary);
	while(!myFile.eof())
	{
		Passengers *pass = new Passengers;
		myFile >> *pass;
		p_list.insertQueue(*pass);
		delete pass;
	}
	myFile.close();
	
	//Separates the passengers in the queue by destination and places them in the appropriate stack
	
	Passengers temp;//needed for the sorting
	
	while(!p_list.isEmpty())
	{
		if(p_list.showFront().destination == "Ankara")
		{
			if(!ankara.isFull())
			{
				temp = p_list.showFront();
				ankara.push(temp);
			}
			else
			{
				cerr<<"Ankara train is full!"<<endl;
			}
			
		}
		
		if(p_list.showFront().destination == "Istanbul")
		{
			if(!istanbul.isFull())
			{
				temp = p_list.showFront();
				istanbul.push(temp);
			}
			else
			{
				cerr<<"Istanbul train is full!"<<endl;
			}
			
		}
		
		if(p_list.showFront().destination == "Adana")
		{
			if(!adana.isFull())
			{
				temp = p_list.showFront();
				adana.push(temp);
			}
			else
			{
				cerr<<"Adana train is full!"<<endl;
			}
			
		}
		
		p_list.deleteQueue();
	}
	
	//Creates the text files for passenger lists and sorts the passengers accordingly
	
	ofstream train1, train2, train3;
	train1.open("ankara.txt", ios::binary);
	train2.open("istanbul.txt", ios::binary);
	train3.open("adana.txt", ios::binary);
	
	while(!ankara.isEmpty())
	{
		train1 << ankara.pop() << endl;
	}
	
	while(!istanbul.isEmpty())
	{
		train2 << istanbul.pop() << endl;
	}
	
	while(!adana.isEmpty())
	{
		train3 << adana.pop() << endl;
	}
	
	train1.close();
	train2.close();
	train3.close();
}
