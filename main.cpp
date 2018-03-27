#include <iostream>
#include "list1.h"
using namespace std;

int main(){
	list1 liczby;
	liczby.createnode(1);
	liczby.createnode(2);
	liczby.createnode(3);
	liczby.createnode(33);
	liczby.createnode(4);
	liczby.createnode(5);
	cout << endl << "dlugosc = " << liczby.length() << endl;
	liczby.display();
	liczby.displayrev();
	cout << endl;
	list1 liczby1;
	liczby1.createnode(4);
	liczby1.createnode(5);
	liczby1.createnode(6);
	liczby1.createnode(7);
	cout << endl << "dlugosc = " << liczby1.length() << endl;
	liczby1.display();
	liczby1.displayrev();

	cout << endl << endl;
	liczby.insert_position(3,11);
	liczby1.insert_start(10);

	liczby.display();
	cout << endl;
	liczby1.display();

	liczby.delete_last();
	liczby.delete_position(2);
	liczby1.delete_first();
	liczby1.delete_betweenvalues(2, 6);
	liczby.delete_value(4);

	cout << endl << endl;
	liczby.display();
	cout << endl;
	liczby1.display();
	cout << endl << endl << endl;

	liczby1.createnode(5);
	liczby1.createnode(6);
	liczby1.createnode(7);
	liczby.createnode(2);
	liczby.createnode(3);
	liczby.createnode(33);
	liczby.createnode(4);

	liczby.display();
	cout << endl;
	liczby1.display();
	cout << endl;

	liczby.length();
	cout << endl;
	liczby1.length();
	cout << endl;


	list1 liczby2;

	liczby2 = liczby + liczby1;
	liczby2.display();
	cout << endl << endl;

	liczby.createnode(5);
	liczby.createnode(6);
	liczby.createnode(7);
	liczby1.createnode(15);
	liczby1.createnode(16);
	liczby1.createnode(17);
	
	list1 liczby3;
	cout << endl << endl << endl;
	liczby.display();
	cout << endl;
	liczby1.display();
	cout << endl;
	liczby3 = liczby1 - liczby;

	cout << endl << "wynik:\t";
	liczby3.display();
	cout << endl;
	liczby.delete_value(6);
	liczby.delete_value(7);
	liczby.display();
	cout << endl << endl;

	
}
