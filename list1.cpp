#include "list1.h"

list1::list1(){
	head = NULL;
	tail = NULL;
}
void list1::createnode(int value){
	node *temp = new node;
	temp->data = value;
	if (head == NULL){
		head = tail = temp;
		temp->next = temp->prev = temp;
		head = temp;
		return;
	}

	temp->next = head;
	head->prev = temp;
	temp->prev = tail;
	tail->next = temp;
	tail = temp;

}
void list1::insert_position(int pos, int value)
{
	node *pre;
	node *cur;
	node *temp = new node;
	cur = head;
	temp->data = value;
	for (int i = 1; i<pos; i++)
	{
		pre = cur;
		cur = cur->next;
	}
	pre->next = temp;
	temp->prev = pre;
	temp->next = cur;
	cur->prev = temp;
}
void list1::insert_start(int value)
{
	node *temp = new node;
	node *temp1;
	temp->data = value;
	temp->next = head;
	head = temp;
	temp->prev = tail;
	temp1 = temp->next;
	temp1->prev = temp;
}
void list1::delete_last()
{
	node *current;
	node *previous;
	current = head;
	while (current->next != tail)
	{
		previous = current;
		current = current->next;
	}
	previous = current;
	current = current->next;
	tail = previous;
	previous->next = head;
	free(current);
	head->prev = previous;
}
void list1::delete_position(int pos)
{
	node *current;
	node *previous;
	node *del;
	current = head;
	for (int i = 1; i<pos; i++)
	{
		previous = current;
		current = current->next;
	}
	previous->next = current->next;
	del = current;
	current = current->next;
	current->prev = previous;
	if (pos == length() - 1){
		tail = current;
	}
	free(del);
}
void list1::delete_first()
{
	if (length() > 2){
		node *temp;
		temp = head;
		head = head->next;
		free(temp);
		head->prev = tail;
	}
	else if(length() == 2){
		node *temp;
		temp = head;
		head = head->next;
		free(temp);
	}
}
void list1::display()
{
	node *temp;
	temp = head;
	cout << "\t\t" << temp->data << "\t";
	do{
		temp = temp->next;
		cout << temp->data << "\t";
	} while (temp != tail);
}
void list1::displayrev()
{
	cout << "\n" << "reverse: " << "\t";
	node *temp;
	temp = tail;
	cout << temp->data << "\t";
	do{
		temp = temp->prev;
		cout << temp->data << "\t";
	} while (temp != head);
	cout << endl;
}
int list1::length(){
	int dlugosc = 1;
	node *temp;
	temp = tail;
	do{
		temp = temp->prev;
		dlugosc++;
	} while (temp != head);
	return dlugosc;
}
const list1 list1::operator+(list1 & rhs) const {
	node *addition1 = head;
	node *addition2 = rhs.head;
	int l = rhs.length();
	node *t = tail;
	list1 list3;
	while (addition1 != t){
		list3.createnode(addition1->data);
		addition1 = addition1->next;
	}
	list3.createnode(addition1->data);
	addition1 = addition1->next;
	t = rhs.tail;
	while (addition2 != t){
		list3.createnode(addition2->data);
		addition2 = addition2->next;
	}
	list3.createnode(addition2->data);
	addition2 = addition2->next;
	return list3;
}
const list1 list1::operator-(list1 & rhs) const{
	list1 list3, list4;
	list4 = rhs;
	node *subtraction1 = head;
	node *subtraction2 = list4.head;
	node *temp;
	node *t = tail;
	int x = 0;
	while (subtraction1 != t){
		x = 0;
		subtraction2 = list4.head;
		while (subtraction2 != list4.tail){
			if (subtraction1->data == subtraction2->data){
				x = 1;
				temp = subtraction2->prev;
				list4.delete_value(subtraction2->data);
				subtraction2 = temp;
			}
			subtraction2 = subtraction2->next;
		}
		if (subtraction1->data == subtraction2->data){
			x = 1;
			list4.delete_value(subtraction2->data);
		}
		subtraction2 = subtraction2->next;
		if (x == 0){
			list3.createnode(subtraction1->data);
		}
		subtraction1 = subtraction1->next;
	}
	x = 0;
	while (subtraction2 != list4.tail){
		if (subtraction1->data == subtraction2->data){
			x = 1;
			list4.delete_value(subtraction2->data);
		}
		subtraction2 = subtraction2->next;
	}
	if (x == 0){
		list3.createnode(subtraction1->data);
		subtraction1 = subtraction1->next;
	}

	return list3;
}
const list1 list1::operator=(const list1 & rhs) {
	node *temp;
	temp = rhs.head;
	int value = temp->data;
	createnode(value);
	do{
		temp = temp->next;
		value = temp->data;
		createnode(value);
	} while (temp != rhs.tail);

	return *this;
}
void list1::deleteduplicate(){
	node *temp;
	node *tempprev;
	node *temptemp;
	tempprev = head;
	temp = head;
	while (temp != tail){
		while (temp != tail){
			if (tempprev->data == temp->data){
				tempprev->next = temp->next;
				temptemp = temp->next;
				temptemp->prev = tempprev;
			}
			temp = temp->next;
		}
		temp = temp->next;
		tempprev = tempprev->next;
	}
	if (tail->prev == tail){
		delete_last();
	}
}
const list1 list1::operator+=(list1 & rhs){
	node *addition1 = head;
	node *addition2 = rhs.head;
	int l = rhs.length();
	node *t = tail;
	do{
		createnode(addition2->data);
		addition2 = addition2->next;
	} while (addition2 != rhs.tail);
	createnode(addition2->data);

	return *this;
}
const list1 list1::operator-=(const list1 & list3){
	list1 rhs;
	rhs = list3;
	node *subtraction1 = head;
	node *subtraction2 = rhs.head;
	int i = 0;
	int j = 0;
	while (subtraction1 != tail){
		i++;
		subtraction2 = rhs.head;
		j = 0;
		while (subtraction2 != rhs.tail){
			j++;
			if (subtraction1->data == subtraction2->data){
				subtraction1 = subtraction1->prev;
				if (i == 1){
					delete_first();
				}
				else{
					delete_position(i);
				}
				subtraction2 = subtraction2->prev;
				if (j != 1){
					rhs.delete_position(j);
				}
				else{
;
					rhs.delete_first();
				}
				j = j - 1;
				i = i - 1;
				break;
				
			}
			subtraction2 = subtraction2->next;

		}
		if (subtraction1->data == subtraction2->data){
			subtraction1 = subtraction1->prev;
			subtraction2 = subtraction2->prev;
			if (i == 1){
				
				delete_first();
			}
			else{
				
				delete_position(i);
			}
			j = j - 1;
			i = i - 1;
		}
		subtraction1 = subtraction1->next;
	}
	j = 0;
	subtraction2 = rhs.head;
	while (subtraction2 != rhs.tail){
		j++;
		if (tail->data == subtraction2->data){
			subtraction1 = subtraction1->prev;
	
			delete_last();
			if (j == 1){
				subtraction2 = subtraction2->next;			
				rhs.delete_first();
			}
			else{
				subtraction2 = subtraction2->prev;
				rhs.delete_position(j);

			}
		}
		subtraction2 = subtraction2->next;
	}
	if (tail->data == subtraction2->data){
		subtraction1 = subtraction1->prev;
		delete_last();
		rhs.delete_last();

	}

	return *this;

}
int list1::valuebyindex(int i) {
	node *temp;
	temp = head;
	int j = 1;
	int value;
	if (j == i){
		value = temp->data;
	}
	do{
		j++;
		temp = temp->next;
		if (j == i){
			value = temp->data;
		}
	} while (temp != tail);
	return value;
}
const bool list1::operator<(list1 & rhs) {
	int x = 0;
	int y = 0;
	cout << length() << endl;
	cout << rhs.length() << endl;
	display();
	cout << endl;
	rhs.display();
	cout << endl << "\t\t";
	if (length() != rhs.length()){
		return (length() < rhs.length());
	}
	else{
		for (int i = 1; i <= length(); i++){
			if (valuebyindex(i) < rhs.valuebyindex(i)){
				x++;
			}
			else if (valuebyindex(i) > rhs.valuebyindex(i)){
				y++;
			}

		}
		if (x > y){
			return true;
		}
		else{
			return false;
		}
	}
}
const bool list1::operator<=(list1 & rhs) {
	int x = 0;
	int y = 0;
	cout << length() << endl;
	cout << rhs.length() << endl;
	display();
	cout << endl;
	rhs.display();
	cout << endl << "\t\t";
	if (length() != rhs.length()){
		return (length() < rhs.length());
	}
	else{
		for (int i = 1; i <= length(); i++){
			if (valuebyindex(i) < rhs.valuebyindex(i)){
				x++;
			}
			else if (valuebyindex(i) > rhs.valuebyindex(i)){
				y++;
			}

		}
		if (x >= y){
			return true;
		}
		else{
			return false;
		}
	}
}
const bool list1::operator>(list1 & rhs) {
	int x = 0;
	int y = 0;
	cout << length() << endl;
	cout << rhs.length() << endl;
	display();
	cout << endl;
	rhs.display();
	cout << endl << "\t\t";
	if (length() != rhs.length()){
		return (length() > rhs.length());
	}
	else{
		for (int i = 1; i <= length(); i++){
			if (valuebyindex(i) > rhs.valuebyindex(i)){
				x++;
			}
			else if (valuebyindex(i) < rhs.valuebyindex(i)){
				y++;
			}

		}
		if (x > y){
			return true;
		}
		else{
			return false;
		}
	}
}
const bool list1::operator>=(list1 & rhs) {
	int x = 0;
	int y = 0;
	cout << length() << endl;
	cout << rhs.length() << endl;
	display();
	cout << endl;
	rhs.display();
	cout << endl << "\t\t";
	if (length() != rhs.length()){
		return (length() > rhs.length());
	}
	else{
		for (int i = 1; i <= length(); i++){
			if (valuebyindex(i) > rhs.valuebyindex(i)){
				x++;
			}
			else if (valuebyindex(i) < rhs.valuebyindex(i)){
				y++;
			}

		}
		if (x >= y){
			return true;
		}
		else{
			return false;
		}
	}
}
const bool list1::operator==(list1 & rhs){
	if (length() != rhs.length()){
		return (length() == rhs.length());
	}
	else{
		for (int i = 1; i <= length(); i++){
			if (valuebyindex(i) != rhs.valuebyindex(i)){
				return false;
			}
		}
		return true;
	}
}
const bool list1::operator!=(list1 & rhs){
	int x = 0;

	if (length() != rhs.length()){
		return (length() != rhs.length());
	}
	else{
		for (int i = 1; i <= length(); i++){
			if (valuebyindex(i) == rhs.valuebyindex(i)){
				x++;
			}
		}
		if (x != length()){
			return true;
		}
		else{
			return false;
		}
	}
}
void list1::delete_value(int value){
	node *current;
	node *previous = tail;
	node *del;
	current = head;
	if (current->data == value){
		previous->next = current->next;
		del = current;
		current = current->next;
		current->prev = previous;
		head = current;
		free(del);
	}
	for (int i = 1; i < length(); ++i)
	{
		previous = current;
		current = current->next;
		if (current->data == value){
			if (current == tail){
				delete_last();
			}
			else{
				previous->next = current->next;
				del = current;
				current = current->next;
				current->prev = previous;
				free(del);
			}
		}
	}
}
void list1::delete_betweenvalues(int od, int doo){
	node *current;
	node *previous = tail;
	node *del;
	node *temp;
	int length1 = length();
	current = head;
	for (int i = 0; i < length1; ++i)
	{
		previous = current;
		current = current->next;
		if (current->data >= od && current->data <= doo){
			if (current == tail){
				delete_last();
				break;
			}
			else if (current == head){
				tail->next = current->next;
				del = current;
				current = current->next;
				current->prev = tail;
				head = current;
				free(del);
				current = tail;
			}
			else{
				previous->next = current->next;
				del = current;
				temp = current->next;
				temp->prev = previous;
				current = current->prev;
				free(del);
			}
		}
	}
	cout << head->data;// << " " << head->next->data << endl;
}
node* list1::operator[](int n){
	node *temp;
	temp = head;

	for (int i = 0; i< length(); ++i){
		if (i == n - 1){
			return temp;
		}
		temp = temp->next;
	}
	return temp;
}
node* list1::accessbyvalue(int x){
	node *temp;
	temp = head;

	for (int i = 0; i< length(); ++i){
		if (x == temp->data){
			return temp;
		}
		temp = temp->next;
	}
	return temp;
}