#include <iostream>

using namespace std;

class House{
	private:
		int area;
		int room_no;
	public:
		House(int a, int b): area(a), room_no(b){}
		friend ostream& operator <<(ostream &o, House &h);
		friend istream& operator >>(istream &i, House &h);
		friend int compare (House &one, House &two);
};

ostream& operator <<(ostream &o, House &h)
{
	o<<"Area: "<<h.area<<"   "<<"Room no: "<<h.room_no<<endl;
	return o;
}

istream& operator >>(istream &i, House &h)
{
	i>>h.area>>h.room_no;
}

int compare (House &one, House &two)
{
	if((one.area==two.area)&&(one.room_no==two.room_no))
	return 0;
	
	if((one.area>two.area)&&(one.room_no>two.room_no))
	return 1;
	
	if((one.area<two.area)&&(one.room_no<<two.room_no))
	return 2;
	
	else return -1;
}

main()
{
	House one(), two();
	cin>>one;
	cin>>two;
	
	cout<<compare(one, two)<<endl;
}
