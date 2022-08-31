//Halil Mert CEYLAN - 18243510049
//Arda ERTANHAN - 18243510007
//CMPE323 - HW2
#include <iostream>
#include <fstream>
using namespace std;

class event{
	public:
		
		int event_id;
		int time;
		int player_id;
		int location[3];
		
		event()
		{
			event_id = -1; //Set default as -1, since event_id must be a positive int we wrote the program in a manner that will ignore events with id -1
			time = -1;
			player_id = -1;
		}
		
	friend istream &operator>>( istream  &input, event &E ) { 
        input >> E.event_id >> E.time >> E.player_id >> E.location[0] >> E.location[1] >> E.location[2];
        return input;            
    }
    
    friend ostream &operator<<( ostream  &output, event &E ) { 
        output << E.event_id << " " << E.time << " " << E.player_id << " " << E.location[0] << " " << E.location[1] << " " << E.location[2];
		return output;           
    }
    
    event &operator=(event &e1)
    {
    	e1.event_id = event_id;
    	e1.time = time;
    	e1.player_id = player_id;
    	e1.location[0] = location[0];
    	e1.location[1] = location[1];
    	e1.location[2] = location[2];
	}
};

void heapify(event arr[], int t, int i)
{
    int largest = i;
    int left = (2*i) + 1;
    int right = (2*i) + 2; 
 
    if ((left < t) && (arr[left].time < arr[largest].time))
        largest = left;
 
    if ((right < t) && (arr[right].time < arr[largest].time))
        largest = right;
 
    if (largest != i) {
        event temp = arr [i];
        arr [i] = arr [largest];
        arr[largest] = temp;
 
        heapify(arr, t, largest);
    }
}
 
void heapSort(event arr[], int t)
{
    for (int i = (t / 2) - 1; i >= 0; i--)
        heapify(arr, t, i);
 
    for (int i = t - 1 ; i > 0; i--) {

        event temp = arr[i];
        arr[i] = arr[0];
 		arr[0] = temp;

        heapify(arr, i, 0);
    }
}


int main()
{
	char ch;
	event arr [100];
	int i=0;
	int size = 0;
	
	fstream myfile;
	myfile.open("event.txt", fstream::in);

		myfile>>ch;			
		while(ch == 'I')
		{
			myfile>>arr[i++];
			size++;
			myfile>>ch;
		}
		
		heapSort (arr, size);
		
		while(ch == 'G')
		{	
			int k = 0;
			while(k < size)
			{
				if(arr[k+1].event_id > 0)
				{
					arr[k+1] = arr[k];
					k++;
				}
				
				else
					break;
			}
			
			arr[k].event_id = -1;
			size--;
			myfile>>ch;
		}
		
		while(ch == 'L')
		{
			int m = 0;
			while(m < size)
			{
				if(arr[m].event_id > 0)
				{
					cout<<arr[m++]<<endl;
				}
			}
			myfile>>ch;
		}
		
	
			
	myfile.close();
	return 0;
}
