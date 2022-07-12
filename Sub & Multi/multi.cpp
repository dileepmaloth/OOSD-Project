/*-------------------   MALOTH DILEEP _ 19MA20024    -------   */


#include <iostream>
#include <fstream>
using namespace std;

// structure to store values
struct node
{
	char data;
	node *next;
	node *prev;
};

// class to store nodes
class list
{
public:
	node *head;
	node *tail;
	// constructor function
	list()
	{
		head = NULL;
		tail = NULL;
		head = tail;
	}
	void additem(char d);	// adds data to the linked list (in front)
	void addend(char d);	// adds node with data d to the end of the list
	void display();			// displays the whole linked list
	void display_reverse(); // displays the whole linked list in reverse order
};

void list::additem(char d)
{ // added a new node in front of the list
	node *newnode = new node;
	newnode->data = d;
	newnode->prev = NULL;
	if (head == NULL)
	{
		newnode->next = NULL;
		head = newnode;
		tail = newnode;
		return;
	}
	newnode->next = head;
	head->prev = newnode;
	head = newnode;
}

void list::addend(char d)
{
	node *newnode = new node;
	newnode->data = d;
	newnode->next = NULL;
	if (head == NULL)
	{
		newnode->prev = NULL;
		head = newnode;
		tail = newnode;
		return;
	}
	if (head->next == NULL)
	{
		newnode->prev = head;
		head->next = newnode;
		tail = newnode;
		return;
	}
	newnode->prev = tail;
	tail->next = newnode;
	tail = newnode;
}

void list::display()
{
	node *current = head;
	while (current != NULL)
	{
		cout << current->data;
		current = current->next;
	}
}

void list::display_reverse()
{
	node *current = tail;
	while (current != NULL)
	{
		cout << current->data;
		current = current->prev;
	}
}

// function for adding without using '+' sign
char add(char a, char b, char *carry)
{
	if (a == '0' && b == '0')
	{
		if (*carry == '0')
		{
			*carry = '0';
			return '0';
		}
		else
		{
			*carry = '0';
			return '1';
		}
	}
	if ((a == '0' && b == '1') || (a == '1' && b == '0'))
	{
		if (*carry == '0')
		{
			*carry = '0';
			return '1';
		}
		else
		{
			*carry = '0';
			return '2';
		}
	}
	if ((a == '0' && b == '2') || (a == '2' && b == '0'))
	{
		if (*carry == '0')
		{
			*carry = '0';
			return '2';
		}
		else
		{
			*carry = '0';
			return '3';
		}
	}
	if ((a == '0' && b == '3') || (a == '3' && b == '0'))
	{
		if (*carry == '0')
		{
			*carry = '0';
			return '3';
		}
		else
		{
			*carry = '0';
			return '4';
		}
	}
	if ((a == '0' && b == '4') || (a == '4' && b == '0'))
	{
		if (*carry == '0')
		{
			*carry = '0';
			return '4';
		}
		else
		{
			*carry = '0';
			return '5';
		}
	}
	if ((a == '0' && b == '5') || (a == '5' && b == '0'))
	{
		if (*carry == '0')
		{
			*carry = '0';
			return '5';
		}
		else
		{
			*carry = '0';
			return '6';
		}
	}
	if ((a == '0' && b == '6') || (a == '6' && b == '0'))
	{
		if (*carry == '0')
		{
			*carry = '0';
			return '6';
		}
		else
		{
			*carry = '0';
			return '7';
		}
	}
	if ((a == '0' && b == '7') || (a == '7' && b == '0'))
	{
		if (*carry == '0')
		{
			*carry = '0';
			return '7';
		}
		else
		{
			*carry = '0';
			return '8';
		}
	}
	if ((a == '0' && b == '8') || (a == '8' && b == '0'))
	{
		if (*carry == '0')
		{
			*carry = '0';
			return '8';
		}
		else
		{
			*carry = '0';
			return '9';
		}
	}
	if ((a == '0' && b == '9') || (a == '9' && b == '0'))
	{
		if (*carry == '0')
		{
			*carry = '0';
			return '9';
		}
		else
		{
			*carry = '1';
			return '0';
		}
	}
	if (a == '1' && b == '1')
	{
		if (*carry == '0')
		{
			*carry = '0';
			return '2';
		}
		else
		{
			*carry = '0';
			return '3';
		}
	}
	if ((a == '1' && b == '2') || (a == '2' && b == '1'))
	{
		if (*carry == '0')
		{
			*carry = '0';
			return '3';
		}
		else
		{
			*carry = '0';
			return '4';
		}
	}
	if ((a == '1' && b == '3') || (a == '3' && b == '1'))
	{
		if (*carry == '0')
		{
			*carry = '0';
			return '4';
		}
		else
		{
			*carry = '0';
			return '5';
		}
	}
	if ((a == '1' && b == '4') || (a == '4' && b == '1'))
	{
		if (*carry == '0')
		{
			*carry = '0';
			return '5';
		}
		else
		{
			*carry = '0';
			return '6';
		}
	}
	if ((a == '1' && b == '5') || (a == '5' && b == '1'))
	{
		if (*carry == '0')
		{
			*carry = '0';
			return '6';
		}
		else
		{
			*carry = '0';
			return '7';
		}
	}
	if ((a == '1' && b == '6') || (a == '6' && b == '1'))
	{
		if (*carry == '0')
		{
			*carry = '0';
			return '7';
		}
		else
		{
			*carry = '0';
			return '8';
		}
	}
	if ((a == '1' && b == '7') || (a == '7' && b == '1'))
	{
		if (*carry == '0')
		{
			*carry = '0';
			return '8';
		}
		else
		{
			*carry = '0';
			return '9';
		}
	}
	if ((a == '1' && b == '8') || (a == '8' && b == '1'))
	{
		if (*carry == '0')
		{
			*carry = '0';
			return '9';
		}
		else
		{
			*carry = '1';
			return '0';
		}
	}
	if ((a == '1' && b == '9') || (a == '9' && b == '1'))
	{
		if (*carry == '0')
		{
			*carry = '1';
			return '0';
		}
		else
		{
			*carry = '1';
			return '1';
		}
	}
	if (a == '2' && b == '2')
	{
		if (*carry == '0')
		{
			*carry = '0';
			return '4';
		}
		else
		{
			*carry = '0';
			return '5';
		}
	}
	if ((a == '2' && b == '3') || (a == '3' && b == '2'))
	{
		if (*carry == '0')
		{
			*carry = '0';
			return '5';
		}
		else
		{
			*carry = '0';
			return '6';
		}
	}
	if ((a == '2' && b == '4') || (a == '4' && b == '2'))
	{
		if (*carry == '0')
		{
			*carry = '0';
			return '6';
		}
		else
		{
			*carry = '0';
			return '7';
		}
	}
	if ((a == '2' && b == '5') || (a == '5' && b == '2'))
	{
		if (*carry == '0')
		{
			*carry = '0';
			return '7';
		}
		else
		{
			*carry = '0';
			return '8';
		}
	}
	if ((a == '2' && b == '6') || (a == '6' && b == '2'))
	{
		if (*carry == '0')
		{
			*carry = '0';
			return '8';
		}
		else
		{
			*carry = '0';
			return '9';
		}
	}
	if ((a == '2' && b == '7') || (a == '7' && b == '2'))
	{
		if (*carry == '0')
		{
			*carry = '0';
			return '9';
		}
		else
		{
			*carry = '1';
			return '0';
		}
	}
	if ((a == '2' && b == '8') || (a == '8' && b == '2'))
	{
		if (*carry == '0')
		{
			*carry = '1';
			return '0';
		}
		else
		{
			*carry = '1';
			return '1';
		}
	}
	if ((a == '2' && b == '9') || (a == '9' && b == '2'))
	{
		if (*carry == '0')
		{
			*carry = '1';
			return '1';
		}
		else
		{
			*carry = '1';
			return '2';
		}
	}
	if (a == '3' && b == '3')
	{
		if (*carry == '0')
		{
			*carry = '0';
			return '6';
		}
		else
		{
			*carry = '0';
			return '7';
		}
	}
	if ((a == '3' && b == '4') || (a == '4' && b == '3'))
	{
		if (*carry == '0')
		{
			*carry = '0';
			return '7';
		}
		else
		{
			*carry = '0';
			return '8';
		}
	}
	if ((a == '3' && b == '5') || (a == '5' && b == '3'))
	{
		if (*carry == '0')
		{
			*carry = '0';
			return '8';
		}
		else
		{
			*carry = '0';
			return '9';
		}
	}
	if ((a == '3' && b == '6') || (a == '6' && b == '3'))
	{
		if (*carry == '0')
		{
			*carry = '0';
			return '9';
		}
		else
		{
			*carry = '1';
			return '0';
		}
	}
	if ((a == '3' && b == '7') || (a == '7' && b == '3'))
	{
		if (*carry == '0')
		{
			*carry = '1';
			return '0';
		}
		else
		{
			*carry = '1';
			return '1';
		}
	}
	if ((a == '3' && b == '8') || (a == '8' && b == '3'))
	{
		if (*carry == '0')
		{
			*carry = '1';
			return '1';
		}
		else
		{
			*carry = '1';
			return '2';
		}
	}
	if ((a == '3' && b == '9') || (a == '9' && b == '3'))
	{
		if (*carry == '0')
		{
			*carry = '1';
			return '2';
		}
		else
		{
			*carry = '1';
			return '3';
		}
	}
	if (a == '4' && b == '4')
	{
		if (*carry == '0')
		{
			*carry = '0';
			return '8';
		}
		else
		{
			*carry = '0';
			return '9';
		}
	}
	if ((a == '4' && b == '5') || (a == '5' && b == '4'))
	{
		if (*carry == '0')
		{
			*carry = '0';
			return '9';
		}
		else
		{
			*carry = '1';
			return '0';
		}
	}
	if ((a == '4' && b == '6') || (a == '6' && b == '4'))
	{
		if (*carry == '0')
		{
			*carry = '1';
			return '0';
		}
		else
		{
			*carry = '1';
			return '1';
		}
	}
	if ((a == '4' && b == '7') || (a == '7' && b == '4'))
	{
		if (*carry == '0')
		{
			*carry = '1';
			return '1';
		}
		else
		{
			*carry = '1';
			return '2';
		}
	}
	if ((a == '4' && b == '8') || (a == '8' && b == '4'))
	{
		if (*carry == '0')
		{
			*carry = '1';
			return '2';
		}
		else
		{
			*carry = '1';
			return '3';
		}
	}
	if ((a == '4' && b == '9') || (a == '9' && b == '4'))
	{
		if (*carry == '0')
		{
			*carry = '1';
			return '3';
		}
		else
		{
			*carry = '1';
			return '4';
		}
	}
	if (a == '5' && b == '5')
	{
		if (*carry == '0')
		{
			*carry = '1';
			return '0';
		}
		else
		{
			*carry = '1';
			return '1';
		}
	}
	if ((a == '5' && b == '6') || (a == '6' && b == '5'))
	{
		if (*carry == '0')
		{
			*carry = '1';
			return '1';
		}
		else
		{
			*carry = '1';
			return '2';
		}
	}
	if ((a == '5' && b == '7') || (a == '7' && b == '5'))
	{
		if (*carry == '0')
		{
			*carry = '1';
			return '2';
		}
		else
		{
			*carry = '1';
			return '3';
		}
	}
	if ((a == '5' && b == '8') || (a == '8' && b == '5'))
	{
		if (*carry == '0')
		{
			*carry = '1';
			return '3';
		}
		else
		{
			*carry = '1';
			return '4';
		}
	}
	if ((a == '5' && b == '9') || (a == '9' && b == '5'))
	{
		if (*carry == '0')
		{
			*carry = '1';
			return '4';
		}
		else
		{
			*carry = '1';
			return '5';
		}
	}
	if (a == '6' && b == '6')
	{
		if (*carry == '0')
		{
			*carry = '1';
			return '2';
		}
		else
		{
			*carry = '1';
			return '3';
		}
	}
	if ((a == '6' && b == '7') || (a == '7' && b == '6'))
	{
		if (*carry == '0')
		{
			*carry = '1';
			return '3';
		}
		else
		{
			*carry = '1';
			return '4';
		}
	}
	if ((a == '6' && b == '8') || (a == '8' && b == '6'))
	{
		if (*carry == '0')
		{
			*carry = '1';
			return '4';
		}
		else
		{
			*carry = '1';
			return '5';
		}
	}
	if ((a == '6' && b == '9') || (a == '9' && b == '6'))
	{
		if (*carry == '0')
		{
			*carry = '1';
			return '5';
		}
		else
		{
			*carry = '1';
			return '6';
		}
	}
	if (a == '7' && b == '7')
	{
		if (*carry == '0')
		{
			*carry = '1';
			return '4';
		}
		else
		{
			*carry = '1';
			return '5';
		}
	}
	if ((a == '7' && b == '8') || (a == '8' && b == '7'))
	{
		if (*carry == '0')
		{
			*carry = '1';
			return '5';
		}
		else
		{
			*carry = '1';
			return '6';
		}
	}
	if ((a == '7' && b == '9') || (a == '9' && b == '7'))
	{
		if (*carry == '0')
		{
			*carry = '1';
			return '6';
		}
		else
		{
			*carry = '1';
			return '7';
		}
	}
	if (a == '8' && b == '8')
	{
		if (*carry == '0')
		{
			*carry = '1';
			return '6';
		}
		else
		{
			*carry = '1';
			return '7';
		}
	}
	if ((a == '8' && b == '9') || (a == '9' && b == '8'))
	{
		if (*carry == '0')
		{
			*carry = '1';
			return '7';
		}
		else
		{
			*carry = '1';
			return '8';
		}
	}
	if (a == '9' && b == '9')
	{
		if (*carry == '0')
		{
			*carry = '1';
			return '8';
		}
		else
		{
			*carry = '1';
			return '9';
		}
	}
	return '?';
}

char sub_1(char ch)
{
	if (ch == '1')
	{
		return '0';
	}
	if (ch == '2')
	{
		return '1';
	}
	if (ch == '3')
	{
		return '2';
	}
	if (ch == '4')
	{
		return '3';
	}
	if (ch == '5')
	{
		return '4';
	}
	if (ch == '6')
	{
		return '5';
	}
	if (ch == '7')
	{
		return '6';
	}
	if (ch == '8')
	{
		return '7';
	}
	if (ch == '9')
	{
		return '8';
	}
	return '?';
}

// funtion for adding integral part of number
list addTwoLists(node *a, node *b)
{
	list res;
	node *first = a, *second = b;
	char ch, carry = '0';
	while (first != NULL || second != NULL)
	{
		if (first == NULL)
		{
			ch = add('0', second->data, &carry);
		}
		if (second == NULL)
		{
			ch = add(first->data, '0', &carry);
		}
		if (first && second)
		{
			ch = add(first->data, second->data, &carry);
		}
		res.addend(ch);
		if (first)
		{
			first = first->next;
		}
		if (second)
		{
			second = second->next;
		}
	}

	if (carry == '1')
	{
		res.addend('1');
	}
	return res;
}

// adding a node with data ch after node a
void add_node_next(node *a, char ch)
{
	node *temp = new node;
	temp->data = ch;
	temp->next = a->next;
	temp->prev = a;
	a->next = temp;
}

// adding a node with data ch before node a
void add_node_before(node *a, char ch)
{
	node *temp = new node;
	temp->data = ch;
	temp->next = a;
	temp->prev = a->prev;
	a->prev = temp;
}

// adding decimal point (.) in the answer
void add_decimal(list a, list b, list &ans)
{
	if (a.head == NULL && b.head == NULL)
	{
		return;
	}
	node *temp, *temp1;
	temp = a.head;
	temp1 = ans.head;
	while (temp != NULL)
	{
		if (temp1->next == NULL)
		{
			add_node_next(temp1, '0');
			ans.tail = temp1->next;
		}
		temp1 = temp1->next;
		temp = temp->next;
	}
	temp = b.head;
	while (temp != NULL)
	{
		if (temp1->next == NULL)
		{
			add_node_next(temp1, '0');
			ans.tail = temp1->next;
		}
		temp1 = temp1->next;
		temp = temp->next;
	}
	add_node_before(temp1, '.');
}

// removing trailing 0 in the answer
void remove_zero(list &ans)
{
	node *temp;
	temp = ans.head;
	while (temp->next != NULL)
	{
		if (temp->data == '0')
		{
			temp = temp->next;
		}
		else
		{
			break;
		}
	}
	if (temp->data == '.')
	{
		temp = temp->next;
	}
	temp->prev = NULL;
	ans.head = temp;
}

// code for multiplying 2 numbers
list mul(node *a, node *b)
{
	char count, ch = '0';
	list res;
	while (a != NULL)
	{
		count = a->data;
		while (count != '0')
		{
			res = addTwoLists(res.head, b);
			count = sub_1(count);
		}
		node *temp1 = new node;
		temp1->prev = NULL;
		temp1->data = '0';
		temp1->next = b;
		b = temp1;
		a = a->next;
	}
	return res;
}

int main()
{
	fstream file;
	char c, sign;
	list a, b, a_int, b_int, a_dec, b_dec, a_neg, b_neg, temp1, temp2, ans;
	file.open("input.txt");

    if(!file.is_open()){
        cout<<"It is failed to open"<<endl;
        return 0;
    }
	while (file.get(c))
	{
		if (c == '-')
		{
			a_neg.addend(c);
			a.addend(c);
			continue;
		}
		if (c == '.' || c == '\n')
		{
			break;
		}
		if (a_int.head == NULL)
		{
			if (c == '0')
			{
				a.addend(c);
				continue;
			}
		}
		a.addend(c);
		a_int.additem(c);
		temp1.additem(c);
	}
	if (c == '.')
	{
		a.addend(c);
		while (file.get(c))
		{
			if (c == '\n')
			{
				break;
			}
			a.addend(c);
			a_dec.additem(c);
			temp1.additem(c);
		}
	}
	while (file.get(c))
	{
		if (c == '-')
		{
			b.addend(c);
			b_neg.addend(c);
			continue;
		}
		if (c == '.' || c == '\n')
		{
			break;
		}
		if (b_int.head == NULL)
		{
			if (c == '0')
			{
				b.addend(c);
				continue;
			}
		}
		b.addend(c);
		b_int.additem(c);
		temp2.additem(c);
	}
	if (c == '.')
	{
		b.addend(c);
		while (file.get(c))
		{
			if (c == '\n')
			{
				break;
			}
			b.addend(c);
			b_dec.additem(c);
			temp2.additem(c);
		}
	}
	// checking the sign for answer
	if ((a_neg.head == NULL && b_neg.head == NULL) || (a_neg.head && b_neg.head))
	{
		sign = '+';
	}
	else
	{
		sign = '-';
	}
	ans = mul(temp1.head, temp2.head);
	if (ans.head == NULL)
	{
		node *temp = new node;
		temp->data = '0';
		temp->prev = NULL;
		temp->next = NULL;
		ans.head = temp;
		ans.tail = temp;
	}
	add_decimal(a_dec, b_dec, ans);
	remove_zero(ans);
	// displaying output
	cout << "(";
	a.display();
	cout << ") * (";
	b.display();
	cout << ") = " << sign;
	ans.display_reverse();
	file.close();
	return 0;
}
