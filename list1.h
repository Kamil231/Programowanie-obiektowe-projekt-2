#include <iostream>
using namespace std;

struct node
{
	int data;
	node *next;
	node *prev;
};


class list1{
private:
	node *head, *tail;
public:
	list1();
	void createnode(int value);								//dodaje elementy na koniec
	void insert_position(int pos, int value);				//dodaje elementy w wybrane miejsce miedzy pierwszym a ostatnim elementem
	void insert_start(int value);							//dodaje element na poczatek listy
	void delete_last();										//usuwa ostatni element
	void delete_position(int pos);							//usuwa element na wybranej pozycji
	void delete_first();									//usuwa pierwszy element
	void display();											//wyswietla liste
	void displayrev();										//wyswietla listeb w odwrotnej kolejnoœci
	int length();											//wyswietla dlugosc listy
	const list1 list1::operator+(list1 & rhs) const;		//dodawanie list
	const list1 list1::operator-(list1 & rhs) const;		//odejmowanie list
	const list1 list1::operator=(const list1 & rhs);		//kopiowanie list
	void deleteduplicate();									//usuwa powtarzajace sie elementy
	const list1 list1::operator+=(list1 & rhs);				//dodaje do listy
	const list1 list1::operator-=(const list1 & list3);		//odejmuje od listy
	int valuebyindex(int i);								//zwraca wartosc elemtnu w danym miejscu listy
	const bool list1::operator<(list1 & rhs);				
	const bool list1::operator<=(list1 & rhs);
	const bool list1::operator>(list1 & rhs);
	const bool list1::operator>=(list1 & rhs);
	const bool list1::operator==(list1 & rhs);
	const bool list1::operator!=(list1 & rhs);
	void delete_value(int value);							//usuwa element o zadanej wartosci
	void delete_betweenvalues(int od, int doo);				//usuwa element ktorego wartosc miesci sie w zadanym przedziale
	node* list1::operator[](int n);							//zwraca wskaznik na element na danym miejscu
	node* accessbyvalue(int x);								//zwraca wskaznik na element o danej wartosci
};