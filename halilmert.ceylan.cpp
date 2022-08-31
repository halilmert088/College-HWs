#include <iostream>
#include <string>
using namespace std;

class Author{
	public:
		string aut_name;
};

class Book{
	public:
		string title;
		Author *author;
		string ISBN;
		int edition;
		
		Book(int _edition, string isbn, Author _aut, string _title)
		{
			this->author=&_aut;
			this->title=_title;
			this->ISBN=isbn;
			this->edition=_edition;
		}
		
		Book()
		{
			author->aut_name="NULL";
			ISBN="INVALID";
		}
		
		bool query_isbn (const string &isbn)
		{
			if(isbn==ISBN)
			return true;
			
			else
			return false;
		}
		
		Book operator =(const Book &book);
		friend ostream &operator <<(ostream &output, const Book &book);
};

Book Book::operator =(const Book &book)
{
	this->author=book.author;
	this->ISBN=book.ISBN;
	this->title=book.title;
	this->edition=book.edition;
}

ostream &operator <<(ostream &output, const Book &book)
{	
	output<<"ISBN number: "<<book.ISBN<<" "<<book.author->aut_name<<", "<<book.title<<endl;
	
	return output;
}

class Library{
	private:
		Book *arr1;
		int *arr2;
		int book_num;
		int book_max;
	public:
		Library(int max)
		{
			book_max=max;
			book_num=0;
			arr1= new Book[book_max];
			arr2= new int [book_max];
			int i;
			
			for(i=0;i<book_max;i++)
			{
			arr2[i]=0;//Initialized the int array to zero
		    }
	    }
		~Library()
		{
			delete[] arr1;
			delete[] arr2;
		}
		
		bool add_book (Book &book)
		{
			if(book_num<book_max)
			{
				this->arr1[book_num].author=book.author;
				this->arr1[book_num].edition=book.edition;
				this->arr1[book_num].ISBN=book.ISBN;
				this->arr1[book_num].title=book.title;
				
				if((arr1[book_num].author==book.author)&&(arr1[book_num].edition==book.edition)&&(arr1[book_num].ISBN==book.ISBN)&&(arr1[book_num].title==book.title))
				{
					book_num++;
					return true;
				}
			}
			
			else
			
			return false;
		}
		
		const Book borrow_book (const string isbn)
		{
			int i;
			for(i=0; i<book_max; ++i)
			{
				if(arr1[i].query_isbn(isbn)==true)
				{
					arr2[i]++;
					return arr1[i];
				}
			}
		}
		
		bool operator +=(const Book &book);
		friend ostream &operator <<(ostream &output, Library &lib);
		void display()
		{
			int i=0;
			cout<<arr1[i];
		}
};

bool Library :: operator +=(const Book &book)
{
	if(book_num<book_max)
			{
				this->arr1[book_num].author=book.author;
				this->arr1[book_num].edition=book.edition;
				this->arr1[book_num].ISBN=book.ISBN;
				this->arr1[book_num].title=book.title;
				
				if((arr1[book_num].author==book.author)&&(arr1[book_num].edition==book.edition)&&(arr1[book_num].ISBN==book.ISBN)&&(arr1[book_num].title==book.title))
				{
					book_num++;
					return true;
				}
				
				else
				    return false;
				
			}
}

ostream &operator <<(ostream &output, Library &lib)
{
	output<<lib.arr1[lib.book_num];
	lib.book_num--;
	return output;
}

main()
{
	Author a, b, c;
	a.aut_name="Naziri";b.aut_name="Elmasri";c.aut_name="Nilsson";
	
	
	Book one(123456789, "1234-567890123", a, "T1");
	Book two(123456789, "1235-967806432", b, "T2");
	Book three(123456789 , "1346-123456789423", c, "T3");
	
	Library lib(3);
	
	lib.add_book(one);
	lib.add_book(two);
	lib.add_book(three);
	
	lib.borrow_book(one.ISBN);
	lib.borrow_book(two.ISBN);
	lib.borrow_book(three.ISBN);
	
	
	cout <<lib;
	cout <<lib;
	cout <<lib;
	
}
