#ifndef HeapSort_h
#define HeapSort_h

#include <iostream>

using namespace std;
class event{
	public:
		
		int event_id;
		int time;
		int player_id;
		int location[3];
		
	friend istream &operator>>( istream  &input, event &E ) { 
        input >> E.event_id >> E.time >> E.player_id >> E.location[0] >> E.location[1] >> E.location[2];
        return input;            
    }
    
    friend ostream &operator<<( ostream  &output, event &E ) { 
        output << E.event_id << " " << E.time << " " << E.player_id << " " << E.location[0] << " " << E.location[1] << " " << E.location[2];
		return output;           
    }
};

event heapify(event arr[])
{
	int i;
	for(i = 0; i < sizeof(arr); i++)
	{
		if(arr[i].time < arr[(2*i) + 1].time)
		{
			T temp = arr[0];
			arr[0]= arr[(2 * i)+1];
			arr[(2*i) + 1] = temp;
		}
		
		if(arr[i].time < arr[(2*i) + 2].time)
		{
			T temp = arr[0];
			arr[0]= arr[(2 * i)+2];
			arr[(2*i) + 2] = temp;
		}
	}
	
	return arr;	
}

#endif
