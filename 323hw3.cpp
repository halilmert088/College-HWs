#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


struct solution{
	int soln_id;
    int fix_no;
	int *fixes;	
	
	solution ()
	{
		fixes = new int [fix_no]; 
	}
	
	friend istream &operator>>( istream  &input, solution &s ) 
	{ 
        int j;
		input >> s.soln_id >> s.fix_no;
		for(j = 0; j< s.fix_no; j++)
		{
			input >> s.fixes[j];
		}
		
		return input;         
    }
    
    friend ostream &operator<<( ostream  &output, solution &s )
	{
		int i;
		
		for (i = 0; i < s.fix_no; i++)
		{
			output << s.fixes[i] << " ";	
		}
		
		return output;
	} 
	
	solution &operator=(solution &s1)
    {    	
		soln_id = s1.soln_id;
    	fix_no = s1.fix_no;
    	fixes = s1.fixes; 
    	
    	for(int i=0; i < s1.fix_no; i++)
    	{
    		fixes[i] = s1.fixes[i];
		}
	}
   
};

vector<solution> optimal;

struct symptom
{	
	int id;
	string name;
};

void greedy (solution arr1[], int i, symptom arr2[])
{
	cout<<"This function has run "<<i + 1<<" time/s"<<endl;
	
	optimal.push_back(arr1[i]);
	cout<<optimal[i]<<" "<<optimal.size()<<endl;
	
	
	if(i == 0)
		greedy(arr1, i+1, arr2);
		
	for (int a= 0; a < i+1; a++)
	{
		int size;
		
		for(int b=0; b<optimal.size(); b++)
		{
			size += optimal[b].fix_no;	
		}
		
		cout<<size;
	}
	
	cout<<endl<<"func over"<<endl;
	return;
}



int main (void)
{
	int soln_num; 
	int symp_num;
	
	fstream myfile; 
	myfile.open ("symptoms.txt", fstream::in);
	
	myfile>>symp_num;
	symptom list_symp[symp_num];
	
	for(int i=0; i < symp_num; i++) // Gets symptom names and id's
	{
		myfile>>list_symp[i].id;
		std::getline(myfile, list_symp[i].name);
	}
	
	
	myfile >> soln_num;
	solution soln [soln_num];
	
	for (int i = 0; i < soln_num; i++)
	{
		myfile >> soln[i];
	}
		
	myfile.close();
		
	for(int i = 0; i< soln_num; i++) //Sorts the array
	{
		for(int j=i+1; j<soln_num; j++)
		{
			if(soln[i].fix_no > soln[j].fix_no)
			{	
				solution temp = soln[i];
				soln[i] = soln[j];
				soln[j] = temp;
			}
		}
	}
	
	greedy(soln, 0, list_symp);
}
