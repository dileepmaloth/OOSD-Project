/*----------------   QUESTION - 2              ----------
  ----------------   MALOTH DILEEP _ 19MA20024    -------   */


#include <iostream>
#include <fstream>
char car='0'; // for storing carry value from decimal to integer part
using namespace std;

// structure to store values
struct node{
 	char data;
 	node* next;
 	node* prev;
};

// class to store nodes
class list{
    public:
        node * head;
	    node * tail;
        // constructor function
    	list() {
    		head=NULL;
    		tail = NULL;
    		head = tail;
    	}
    	void additem(char d);  // adds data to the linked list (in front)
        void addend(char d);  // adds node with data d to the end of the list
		void deltop();   // deletes the first data item
    	void display(); // displays the whole linked list
};

void list::additem(char d){ // added a new node in front of the list
	node *newnode = new node;
	newnode->data = d;
    newnode->prev=NULL;
	if (head==NULL) {
        newnode->next=NULL;
        head=newnode;
        tail=newnode;
        return;
    }
    newnode->next=head;
    head->prev=newnode;
    head=newnode;
}

void list::addend(char d){
	node *newnode = new node;
	newnode->data = d;
    newnode->next=NULL;
	if (head==NULL) {
        newnode->prev=NULL;
        head=newnode;
		tail=newnode;
        return;
    }
    if (head->next==NULL) {
        newnode->prev=head;
        head->next=newnode;
        tail=newnode;
        return;
    }
    newnode->prev=tail;
    tail->next=newnode;
    tail=newnode;
}

void list::deltop() {
	if (head!=NULL) {
		if (head->next==NULL) {
			head=NULL;
			tail=NULL;
		}
		else {
			head=head->next;
			head->prev=NULL;
		}
	}
}

void list::display(){
	node* current = head;
	while(current != NULL){
		cout << current->data;
		current = current->next;
	}
}

// function for adding without using '+' sign
char add(char a, char b, char* carry) {
    if (a=='0' && b=='0') {
		if (*carry=='0') {
			*carry='0';
			return '0';
		}
		else {
			*carry='0';
			return '1';
		}
	}
	if ((a=='0' && b=='1') || (a=='1' && b=='0')) {
		if (*carry=='0') {
			*carry='0';
			return '1';
		}
		else {
			*carry='0';
            return '2';
		}
	}
	if ((a=='0' && b=='2') || (a=='2' && b=='0')) {
		if (*carry=='0') {
			*carry='0';
			return '2';
		}
		else {
			*carry='0';
			return '3';
		}
	}
	if ((a=='0' && b=='3') || (a=='3' && b=='0')) {
		if (*carry=='0') {
			*carry='0';
			return '3';
		}
		else {
			*carry='0';
			return '4';
		}
	}
	if ((a=='0' && b=='4') || (a=='4' && b=='0')) {
		if (*carry=='0') {
			*carry='0';
			return '4';
		}
		else {
			*carry='0';
			return '5';
		}
	}
	if ((a=='0' && b=='5') || (a=='5' && b=='0')) {
		if (*carry=='0') {
			*carry='0';
			return '5';
		}
		else {
			*carry='0';
			return '6';
		}
	}
	if ((a=='0' && b=='6') || (a=='6' && b=='0')) {
		if (*carry=='0') {
			*carry='0';
			return '6';
		}
		else {
			*carry='0';
			return '7';
		}
	}
	if ((a=='0' && b=='7') || (a=='7' && b=='0')) {
		if (*carry=='0') {
			*carry='0';
			return '7';
		}
		else {
			*carry='0';
			return '8';
        }
    }
	if ((a=='0' && b=='8') || (a=='8' && b=='0')) {
		if (*carry=='0') {
			*carry='0';
			return '8';
		}
		else {
			*carry='0';
			return '9';
		}
	}
	if ((a=='0' && b=='9') || (a=='9' && b=='0')) {
		if (*carry=='0') {
			*carry='0';
			return '9';
		}
		else {
			*carry='1';
			return '0';
		}
	}
	if (a=='1' && b=='1') {
		if (*carry=='0') {
			*carry='0';
			return '2';
		}
		else {
			*carry='0';
			return '3';
		}
	}
	if ((a=='1' && b=='2') || (a=='2' && b=='1')) {
		if (*carry=='0') {
			*carry='0';
			return '3';
		}
		else {
			*carry='0';
			return '4';
		}
	}
	if ((a=='1' && b=='3') || (a=='3' && b=='1')) {
		if (*carry=='0') {
			*carry='0';
			return '4';
		}
		else {
			*carry='0';
			return '5';
		}
	}
	if ((a=='1' && b=='4') || (a=='4' && b=='1')) {
		if (*carry=='0') {
			*carry='0';
			return '5';
		}
		else {
			*carry='0';
			return '6';
		}
	}
	if ((a=='1' && b=='5') || (a=='5' && b=='1')) {
		if (*carry=='0') {
			*carry='0';
			return '6';
		}
		else {
			*carry='0';
			return '7';
		}
	}
	if ((a=='1' && b=='6') || (a=='6' && b=='1')) {
		if (*carry=='0') {
			*carry='0';
			return '7';
		}
		else {
			*carry='0';
			return '8';
		}
	}
	if ((a=='1' && b=='7') || (a=='7' && b=='1')) {
		if (*carry=='0') {
			*carry='0';
			return '8';
		}
		else {
			*carry='0';
			return '9';
		}
	}
	if ((a=='1' && b=='8') || (a=='8' && b=='1')) {
		if (*carry=='0') {
			*carry='0';
			return '9';
		}
		else {
			*carry='1';
			return '0';
		}
	}
	if ((a=='1' && b=='9') || (a=='9' && b=='1')) {
		if (*carry=='0') {
			*carry='1';
			return '0';
		}
		else {
			*carry='1';
			return '1';
		}
	}
	if (a=='2' && b=='2') {
		if (*carry=='0') {
			*carry='0';
            return '4';
		}
		else {
			*carry='0';
			return '5';
		}
	}
	if ((a=='2' && b=='3') || (a=='3' && b=='2')) {
		if (*carry=='0') {
			*carry='0';
			return '5';
		}
		else {
			*carry='0';
			return '6';
		}
	}
	if ((a=='2' && b=='4') || (a=='4' && b=='2')) {
		if (*carry=='0') {
			*carry='0';
			return '6';
		}
		else {
			*carry='0';
			return '7';
		}
	}
	if ((a=='2' && b=='5') || (a=='5' && b=='2')) {
		if (*carry=='0') {
			*carry='0';
			return '7';
		}
		else {
			*carry='0';
			return '8';
		}
	}
	if ((a=='2' && b=='6') || (a=='6' && b=='2')) {
		if (*carry=='0') {
			*carry='0';
			return '8';
		}
		else {
			*carry='0';
			return '9';
		}
	}
	if ((a=='2' && b=='7') || (a=='7' && b=='2')) {
		if (*carry=='0') {
			*carry='0';
			return '9';
		}
		else {
			*carry='1';
			return '0';
		}
	}
	if ((a=='2' && b=='8') || (a=='8' && b=='2')) {
		if (*carry=='0') {
			*carry='1';
			return '0';
		}
		else {
			*carry='1';
			return '1';
		}
	}
	if ((a=='2' && b=='9') || (a=='9' && b=='2')) {
		if (*carry=='0') {
			*carry='1';
			return '1';
		}
		else {
			*carry='1';
			return '2';
		}
	}
	if (a=='3' && b=='3') {
		if (*carry=='0') {
			*carry='0';
			return '6';
		}
		else {
			*carry='0';
			return '7';
		}
	}
	if ((a=='3' && b=='4') || (a=='4' && b=='3')) {
		if (*carry=='0') {
			*carry='0';
			return '7';
		}
		else {
			*carry='0';
			return '8';
		}
	}
	if ((a=='3' && b=='5') || (a=='5' && b=='3')) {
		if (*carry=='0') {
			*carry='0';
			return '8';
		}
		else {
			*carry='0';
			return '9';
		}
	}
	if ((a=='3' && b=='6') || (a=='6' && b=='3')) {
		if (*carry=='0') {
			*carry='0';
			return '9';
		}
		else {
			*carry='1';
			return '0';
		}
	}
	if ((a=='3' && b=='7') || (a=='7' && b=='3')) {
		if (*carry=='0') {
			*carry='1';
			return '0';
		}
		else {
			*carry='1';
			return '1';
		}
	}
	if ((a=='3' && b=='8') || (a=='8' && b=='3')) {
		if (*carry=='0') {
			*carry='1';
			return '1';
		}
		else {
			*carry='1';
			return '2';
		}
	}
	if ((a=='3' && b=='9') || (a=='9' && b=='3')) {
		if (*carry=='0') {
			*carry='1';
			return '2';
		}
		else {
			*carry='1';
			return '3';
		}
	}
	if (a=='4' && b=='4') {
		if (*carry=='0') {
			*carry='0';
			return '8';
		}
		else {
			*carry='0';
			return '9';
		}
	}
	if ((a=='4' && b=='5') || (a=='5' && b=='4')) {
		if (*carry=='0') {
			*carry='0';
			return '9';
		}
		else {
			*carry='1';
			return '0';
		}
	}
	if ((a=='4' && b=='6') || (a=='6' && b=='4')) {
		if (*carry=='0') {
            *carry='1';
			return '0';
		}
		else {
			*carry='1';
			return '1';
		}
	}
	if ((a=='4' && b=='7') || (a=='7' && b=='4')) {
		if (*carry=='0') {
			*carry='1';
			return '1';
		}
		else {
			*carry='1';
			return '2';
		}
	}
	if ((a=='4' && b=='8') || (a=='8' && b=='4')) {
		if (*carry=='0') {
			*carry='1';
			return '2';
		}
		else {
			*carry='1';
			return '3';
		}
	}
	if ((a=='4' && b=='9') || (a=='9' && b=='4')) {
		if (*carry=='0') {
			*carry='1';
			return '3';
		}
		else {
			*carry='1';
			return '4';
		}
	}
	if (a=='5' && b=='5') {
		if (*carry=='0') {
			*carry='1';
			return '0';
		}
		else {
			*carry='1';
			return '1';
		}
	}
	if ((a=='5' && b=='6') || (a=='6' && b=='5')) {
		if (*carry=='0') {
			*carry='1';
			return '1';
		}
		else {
			*carry='1';
			return '2';
		}
	}
	if ((a=='5' && b=='7') || (a=='7' && b=='5')) {
		if (*carry=='0') {
			*carry='1';
			return '2';
		}
		else {
			*carry='1';
			return '3';
		}
	}
	if ((a=='5' && b=='8') || (a=='8' && b=='5')) {
		if (*carry=='0') {
		*carry='1';
			return '3';
		}
		else {
			*carry='1';
			return '4';
		}
	}
	if ((a=='5' && b=='9') || (a=='9' && b=='5')) {
		if (*carry=='0') {
			*carry='1';
			return '4';
		}
		else {
			*carry='1';
			return '5';
		}
	}
	if (a=='6' && b=='6') {
		if (*carry=='0') {
			*carry='1';
			return '2';
		}
		else {
			*carry='1';
			return '3';
		}
	}
	if ((a=='6' && b=='7') || (a=='7' && b=='6')) {
		if (*carry=='0') {
			*carry='1';
			return '3';
		}
		else {
			*carry='1';
			return '4';
		}
	}
	if ((a=='6' && b=='8') || (a=='8' && b=='6')) {
		if (*carry=='0') {
			*carry='1';
			return '4';
		}
		else {
			*carry='1';
			return '5';
		}
	}
	if ((a=='6' && b=='9') || (a=='9' && b=='6')) {
		if (*carry=='0') {
			*carry='1';
			return '5';
		}
		else {
			*carry='1';
			return '6';
		}
	}
	if (a=='7' && b=='7') {
		if (*carry=='0') {
			*carry='1';
			return '4';
		}
		else {
			*carry='1';
			return '5';
		}
	}
	if ((a=='7' && b=='8') || (a=='8' && b=='7')) {
		if (*carry=='0') {
			*carry='1';
            return '5';
		}
		else {
			*carry='1';
			return '6';
		}
	}
	if ((a=='7' && b=='9') || (a=='9' && b=='7')) {
		if (*carry=='0') {
			*carry='1';
			return '6';
		}
		else {
			*carry='1';
			return '7';
		}
	}
	if (a=='8' && b=='8') {
		if (*carry=='0') {
			*carry='1';
			return '6';
		}
		else {
			*carry='1';
			return '7';
		}
	}
	if ((a=='8' && b=='9') || (a=='9' && b=='8')) {
		if (*carry=='0') {
			*carry='1';
			return '7';
		}
		else {
			*carry='1';
			return '8';
		}
	}
	if (a=='9' && b=='9') {
		if (*carry=='0') {
			*carry='1';
			return '8';
		}
		else {
			*carry='1';
			return '9';
		}
	}
    return '?';
}

// function for subtracting without using '-' sign
char sub(char a, char b, char* carry) {
	if (a=='0' && b=='0') {
		if (*carry=='0') {
			*carry='0';
			return '0';
		}
		else {
			*carry='1';
			return '9';
		}
	}
	if (a=='0' && b=='1') {
		if (*carry=='0') {
			*carry='1';
			return '9';
		}
		else {
			*carry='1';
			return '8';
		}
	}
	if (a=='0' && b=='2') {
		if (*carry=='0') {
			*carry='1';
			return '8';
	}
		else {
			*carry='1';
			return '7';
		}
	}
	if (a=='0' && b=='3') {
		if (*carry=='0') {
			*carry='1';
			return '7';
		}
		else {
			*carry='1';
			return '6';
		}
	}
	if (a=='0' && b=='4') {
		if (*carry=='0') {
			*carry='1';
			return '6';
		}
		else {
			*carry='1';
			return '5';
		}
	}
	if (a=='0' && b=='5') {
		if (*carry=='0') {
			*carry='1';
			return '5';
		}
		else {
			*carry='1';
			return '4';
		}
	}
	if (a=='0' && b=='6') {
		if (*carry=='0') {
			*carry='1';
			return '4';
		}
		else {
			*carry='1';
			return '3';
		}
	}
	if (a=='0' && b=='7') {
		if (*carry=='0') {
			*carry='1';
			return '3';
		}
		else {
			*carry='1';
			return '2';
		}
	}
	if (a=='0' && b=='8') {
		if (*carry=='0') {
			*carry='1';
			return '2';
		}
		else {
			*carry='1';
			return '1';
		}
	}
	if (a=='0' && b=='9') {
		if (*carry=='0') {
			*carry='1';
			return '1';
		}
		else {
			*carry='1';
			return '0';
		}
	}
	if (a=='1' && b=='0') {
		if (*carry=='0') {
			*carry='0';
			return '1';
		}
		else {
			*carry='0';
			return '0';
		}
	}
	if (a=='1' && b=='1') {
		if (*carry=='0') {
			*carry='0';
			return '0';
		}
		else {
			*carry='1';
			return '9';
		}
	}
	if (a=='1' && b=='2') {
		if (*carry=='0') {
			*carry='1';
			return '9';
		}
		else {
			*carry='1';
			return '8';
		}
	}
	if (a=='1' && b=='3') {
		if (*carry=='0') {
			*carry='1';
			return '8';
		}
		else {
			*carry='1';
			return '7';
		}
	}
	if (a=='1' && b=='4') {
		if (*carry=='0') {
			*carry='1';
			return '7';
		}
		else {
			*carry='1';
			return '6';
		}
	}
	if (a=='1' && b=='5') {
		if (*carry=='0') {
			*carry='1';
			return '6';
		}
		else {
			*carry='1';
			return '5';
		}
	}
	if (a=='1' && b=='6') {
		if (*carry=='0') {
			*carry='1';
			return '5';
		}
		else {
			*carry='1';
			return '4';
		}
	}
	if (a=='1' && b=='7') {
		if (*carry=='0') {
			*carry='1';
			return '4';
		}
		else {
			*carry='1';
			return '3';
		}
	}
	if (a=='1' && b=='8') {
		if (*carry=='0') {
			*carry='1';
			return '3';
		}
		else {
			*carry='1';
			return '2';
		}
	}
	if (a=='1' && b=='9') {
		if (*carry=='0') {
			*carry='1';
			return '2';
		}
		else {
			*carry='1';
			return '1';
		}
	}
	if (a=='2' && b=='0') {
		if (*carry=='0') {
			*carry='0';
			return '2';
		}
		else {
			*carry='0';
			return '1';
		}
	}
	if (a=='2' && b=='1') {
		if (*carry=='0') {
			*carry='0';
			return '1';
		}
		else {
			*carry='0';
			return '0';
		}
	}
	if (a=='2' && b=='2') {
		if (*carry=='0') {
			*carry='0';
			return '0';
		}
		else {
			*carry='1';
			return '9';
		}
	}
	if (a=='2' && b=='3') {
		if (*carry=='0') {
			*carry='1';
			return '9';
		}
		else {
			*carry='1';
			return '8';
		}
	}
	if (a=='2' && b=='4') {
		if (*carry=='0') {
			*carry='1';
			return '8';
		}
		else {
			*carry='1';
			return '7';
		}
	}
	if (a=='2' && b=='5') {
		if (*carry=='0') {
			*carry='1';
			return '7';
		}
		else {
			*carry='1';
			return '6';
		}
	}
	if (a=='2' && b=='6') {
		if (*carry=='0') {
			*carry='1';
			return '6';
		}
		else {
			*carry='1';
			return '5';
		}
	}
	if (a=='2' && b=='7') {
		if (*carry=='0') {
			*carry='1';
			return '5';
		}
		else {
			*carry='1';
			return '4';
		}
	}
	if (a=='2' && b=='8') {
		if (*carry=='0') {
			*carry='1';
			return '4';
		}
		else {
			*carry='1';
			return '3';
		}
	}
	if (a=='2' && b=='9') {
		if (*carry=='0') {
			*carry='1';
			return '3';
		}
		else {
			*carry='1';
			return '2';
		}
	}
	if (a=='3' && b=='0') {
		if (*carry=='0') {
			*carry='0';
			return '3';
		}
		else {
			*carry='0';
			return '2';
		}
	}
	if (a=='3' && b=='1') {
		if (*carry=='0') {
			*carry='0';
			return '2';
		}
		else {
			*carry='0';
			return '1';
		}
	}
	if (a=='3' && b=='2') {
		if (*carry=='0') {
			*carry='0';
			return '1';
		}
		else {
			*carry='0';
			return '0';
		}
	}
	if (a=='3' && b=='3') {
		if (*carry=='0') {
			*carry='0';
			return '0';
		}
		else {
			*carry='1';
			return '9';
		}
	}
	if (a=='3' && b=='4') {
		if (*carry=='0') {
			*carry='1';
			return '9';
		}
		else {
			*carry='1';
			return '8';
		}
	}
	if (a=='3' && b=='5') {
		if (*carry=='0') {
			*carry='1';
			return '8';
		}
		else {
			*carry='1';
			return '7';
		}
	}
	if (a=='3' && b=='6') {
		if (*carry=='0') {
			*carry='1';
			return '7';
		}
		else {
			*carry='1';
			return '6';
		}
	}
	if (a=='3' && b=='7') {
		if (*carry=='0') {
			*carry='1';
			return '6';
		}
		else {
			*carry='1';
			return '5';
		}
	}
	if (a=='3' && b=='8') {
		if (*carry=='0') {
			*carry='1';
			return '5';
		}
		else {
			*carry='1';
			return '4';
		}
	}
	if (a=='3' && b=='9') {
		if (*carry=='0') {
			*carry='1';
			return '4';
		}
		else {
			*carry='1';
			return '3';
		}
	}
	if (a=='4' && b=='0') {
		if (*carry=='0') {
			*carry='0';
			return '4';
		}
		else {
			*carry='0';
			return '3';
		}
	}
	if (a=='4' && b=='1') {
		if (*carry=='0') {
			*carry='0';
			return '3';
		}
		else {
			*carry='0';
			return '2';
		}
	}
	if (a=='4' && b=='2') {
		if (*carry=='0') {
			*carry='0';
			return '2';
		}
		else {
			*carry='0';
			return '1';
		}
	}
	if (a=='4' && b=='3') {
		if (*carry=='0') {
			*carry='0';
			return '1';
		}
		else {
			*carry='0';
			return '0';
		}
	}
	if (a=='4' && b=='4') {
		if (*carry=='0') {
			*carry='0';
			return '0';
		}
		else {
			*carry='1';
			return '9';
		}
	}
	if (a=='4' && b=='5') {
		if (*carry=='0') {
			*carry='1';
			return '9';
		}
		else {
			*carry='1';
			return '8';
		}
	}
	if (a=='4' && b=='6') {
		if (*carry=='0') {
			*carry='1';
			return '8';
		}
		else {
			*carry='1';
			return '7';
		}
	}
	if (a=='4' && b=='7') {
		if (*carry=='0') {
			*carry='1';
			return '7';
		}
		else {
			*carry='1';
			return '6';
		}
	}
	if (a=='4' && b=='8') {
		if (*carry=='0') {
			*carry='1';
			return '6';
		}
		else {
			*carry='1';
			return '5';
		}
	}
	if (a=='4' && b=='9') {
		if (*carry=='0') {
			*carry='1';
			return '5';
		}
		else {
			*carry='1';
			return '4';
		}
	}
	if (a=='5' && b=='0') {
		if (*carry=='0') {
			*carry='0';
			return '5';
		}
		else {
			*carry='0';
			return '4';
		}
	}
	if (a=='5' && b=='1') {
		if (*carry=='0') {
			*carry='0';
			return '4';
		}
		else {
			*carry='0';
			return '3';
		}
	}
	if (a=='5' && b=='2') {
		if (*carry=='0') {
			*carry='0';
			return '3';
		}
		else {
			*carry='0';
			return '2';
		}
	}
	if (a=='5' && b=='3') {
		if (*carry=='0') {
			*carry='0';
			return '2';
		}
		else {
			*carry='0';
			return '1';
		}
	}
	if (a=='5' && b=='4') {
		if (*carry=='0') {
			*carry='0';
			return '1';
		}
		else {
			*carry='0';
			return '0';
		}
	}
	if (a=='5' && b=='5') {
		if (*carry=='0') {
			*carry='0';
			return '0';
		}
		else {
			*carry='1';
			return '9';
		}
	}
	if (a=='5' && b=='6') {
		if (*carry=='0') {
			*carry='1';
			return '9';
		}
		else {
			*carry='1';
			return '8';
		}
	}
	if (a=='5' && b=='7') {
		if (*carry=='0') {
			*carry='1';
			return '8';
		}
		else {
			*carry='1';
			return '7';
		}
	}
	if (a=='5'&& b=='8') {
		if (*carry=='0') {
			*carry='1';
			return '7';
		}
		else {
			*carry='1';
			return '6';
		}
	}
	if (a=='5' && b=='9') {
		if (*carry=='0') {
			*carry='1';
			return '6';
		}
		else {
			*carry='1';
			return '5';
		}
	}
	if (a=='6' && b=='0') {
		if (*carry=='0') {
			*carry='0';
			return '6';
		}
		else {
			*carry='0';
			return '5';
		}
	}
	if (a=='6' && b=='1') {
		if (*carry=='0') {
			*carry='0';
			return '5';
		}
		else {
			*carry='0';
			return '4';
		}
	}
	if (a=='6' && b=='2') {
		if (*carry=='0') {
			*carry='0';
			return '4';
		}
		else {
			*carry='0';
			return '3';
		}
	}
	if (a=='6' && b=='3') {
		if (*carry=='0') {
			*carry='0';
			return '3';
		}
		else {
			*carry='0';
			return '2';
		}
	}
	if (a=='6' && b=='4') {
		if (*carry=='0') {
			*carry='0';
			return '2';
		}
		else {
			*carry='0';
			return '1';
		}
	}
	if (a=='6' && b=='5') {
		if (*carry=='0') {
			*carry='0';
			return '1';
		}
		else {
			*carry='0';
			return '0';
		}
	}
	if (a=='6' && b=='6') {
		if (*carry=='0') {
			*carry='0';
			return '0';
		}
		else {
			*carry='1';
			return '9';
		}
	}
	if (a=='6' && b=='7') {
		if (*carry=='0') {
			*carry='1';
			return '9';
		}
		else {
			*carry='1';
			return '8';
		}
	}
	if (a=='6' && b=='8') {
		if (*carry=='0') {
			*carry='1';
			return '8';
		}
		else {
			*carry='1';
			return '7';
		}
	}
	if (a=='6' && b=='9') {
		if (*carry=='0') {
			*carry='1';
			return '7';
		}
		else {
			*carry='1';
			return '6';
		}
	}
	if (a=='7' && b=='0') {
		if (*carry=='0') {
			*carry='0';
			return '7';
		}
		else {
			*carry='0';
			return '6';
		}
	}
	if (a=='7' && b=='1') {
		if (*carry=='0') {
			*carry='0';
			return '6';
		}
		else {
			*carry='0';
			return '5';
		}
	}
	if (a=='7' && b=='2') {
		if (*carry=='0') {
			*carry='0';
			return '5';
		}
		else {
			*carry='0';
			return '4';
		}
	}
	if (a=='7' && b=='3') {
		if (*carry=='0') {
			*carry='0';
			return '4';
		}
		else {
			*carry='0';
			return '3';
		}
	}
	if (a=='7' && b=='4') {
		if (*carry=='0') {
			*carry='0';
			return '3';
		}
		else {
			*carry='0';
			return '2';
		}
	}
	if (a=='7' && b=='5') {
		if (*carry=='0') {
			*carry='0';
			return '2';
		}
		else {
			*carry='0';
			return '1';
		}
	}
	if (a=='7' && b=='6') {
		if (*carry=='0') {
			*carry='0';
			return '1';
		}
		else {
			*carry='0';
			return '0';
		}
	}
	if (a=='7' && b=='7') {
		if (*carry=='0') {
			*carry='0';
			return '0';
		}
		else {
			*carry='1';
			return '9';
		}
	}
	if (a=='7' && b=='8') {
		if (*carry=='0') {
			*carry='1';
			return '9';
		}
		else {
			*carry='1';
			return '8';
		}
	}
	if (a=='7' && b=='9') {
		if (*carry=='0') {
			*carry='1';
			return '8';
		}
		else {
			*carry='1';
			return '7';
		}
	}
	if (a=='8' && b=='0') {
		if (*carry=='0') {
			*carry='0';
			return '8';
		}
		else {
			*carry='0';
			return '7';
		}
	}
	if (a=='8' && b=='1') {
		if (*carry=='0') {
			*carry='0';
			return '7';
		}
		else {
			*carry='0';
			return '6';
		}
	}
	if (a=='8' && b=='2') {
		if (*carry=='0') {
			*carry='0';
			return '6';
		}
		else {
			*carry='0';
			return '5';
		}
	}
	if (a=='8' && b=='3') {
		if (*carry=='0') {
			*carry='0';
			return '5';
		}
		else {
			*carry='0';
			return '4';
		}
	}
	if (a=='8' && b=='4') {
		if (*carry=='0') {
			*carry='0';
			return '4';
		}
		else {
			*carry='0';
			return '3';
		}
	}
	if (a=='8' && b=='5') {
		if (*carry=='0') {
			*carry='0';
			return '3';
		}
		else {
			*carry='0';
			return '2';
		}
	}
	if (a=='8' && b=='6') {
		if (*carry=='0') {
			*carry='0';
			return '2';
		}
		else {
			*carry='0';
			return '1';
		}
	}
	if (a=='8' && b=='7') {
		if (*carry=='0') {
			*carry='0';
			return '1';
		}
		else {
			*carry='0';
			return '0';
		}
	}
	if (a=='8' && b=='8') {
		if (*carry=='0') {
			*carry='0';
			return '0';
		}
		else {
			*carry='1';
			return '9';
		}
	}
	if (a=='8' && b=='9') {
		if (*carry=='0') {
			*carry='1';
			return '9';
		}
		else {
			*carry='1';
			return '8';
		}
	}
	if (a=='9' && b=='0') {
		if (*carry=='0') {
			*carry='0';
			return '9';
		}
		else {
			*carry='0';
			return '8';
		}
	}
	if (a=='9' && b=='1') {
		if (*carry=='0') {
			*carry='0';
			return '8';
		}
		else {
			*carry='0';
			return '7';
		}
	}
	if (a=='9' && b=='2') {
		if (*carry=='0') {
			*carry='0';
			return '7';
		}
		else {
			*carry='0';
			return '6';
		}
	}
	if (a=='9' && b=='3') {
		if (*carry=='0') {
			*carry='0';
			return '6';
		}
		else {
			*carry='0';
			return '5';
		}
	}
	if (a=='9' && b=='4') {
		if (*carry=='0') {
			*carry='0';
			return '5';
		}
		else {
			*carry='0';
			return '4';
		}
	}
	if (a=='9' && b=='5') {
		if (*carry=='0') {
			*carry='0';
			return '4';
		}
		else {
			*carry='0';
			return '3';
		}
	}
	if (a=='9' && b=='6') {
		if (*carry=='0') {
			*carry='0';
			return '3';
		}
		else {
			*carry='0';
			return '2';
		}
	}
	if (a=='9' && b=='7') {
		if (*carry=='0') {
			*carry='0';
			return '2';
		}
		else {
			*carry='0';
			return '1';
		}
	}
	if (a=='9' && b=='8') {
		if (*carry=='0') {
			*carry='0';
			return '1';
		}
		else {
			*carry='0';
			return '0';
		}
	}
	if (a=='9' && b=='9') {
		if (*carry=='0') {
			*carry='0';
			return '0';
		}
		else {
			*carry='1';
			return '9';
		}
	}
	return '?';
}

// comparing 2 characters without using >,< sign
char com(char ch1, char ch2) {
    if ((ch1=='0' && ch2=='1') || (ch1=='0' && ch2=='2') || (ch1=='0' && ch2=='3') || (ch1=='0' && ch2=='4') || (ch1=='0' && ch2=='5') || (ch1=='0' && ch2=='6') || (ch1=='0' && ch2=='7') || (ch1=='0' && ch2=='8') || (ch1=='0' && ch2=='9') || (ch1=='1' && ch2=='2') || (ch1=='1' && ch2=='3') || (ch1=='1' && ch2=='4') || (ch1=='1' && ch2=='5') || (ch1=='1' && ch2=='6') || (ch1=='1' && ch2=='7') || (ch1=='1' && ch2=='8') || (ch1=='1' && ch2=='9') || (ch1=='2' && ch2=='3') || (ch1=='2' && ch2=='4') || (ch1=='2' && ch2=='5') || (ch1=='2' && ch2=='6') || (ch1=='2' && ch2=='7') || (ch1=='2' && ch2=='8') || (ch1=='2' && ch2=='9') || (ch1=='3' && ch2=='4') || (ch1=='3' && ch2=='5') || (ch1=='3' && ch2=='6') || (ch1=='3' && ch2=='7') || (ch1=='3' && ch2=='8') || (ch1=='3' && ch2=='9') || (ch1=='4' && ch2=='5') || (ch1=='4' && ch2=='6') || (ch1=='4' && ch2=='7') || (ch1=='4' && ch2=='8') || (ch1=='4' && ch2=='9') || (ch1=='5' && ch2=='6') || (ch1=='5' && ch2=='7') || (ch1=='5' && ch2=='8') || (ch1=='5' && ch2=='9') || (ch1=='6' && ch2=='7') || (ch1=='6' && ch2=='8') || (ch1=='6' && ch2=='9') || (ch1=='7' && ch2=='8') || (ch1=='7' && ch2=='9') || (ch1=='8' && ch2=='9')) {
        return '<';
    }
    if ((ch1=='1' && ch2=='0') || (ch1=='2' && ch2=='0') || (ch1=='3' && ch2=='0') || (ch1=='4' && ch2=='0') || (ch1=='5' && ch2=='0') || (ch1=='6' && ch2=='0') || (ch1=='7' && ch2=='0') || (ch1=='8' && ch2=='0') || (ch1=='9' && ch2=='0') || (ch1=='2' && ch2=='1') || (ch1=='3' && ch2=='1') || (ch1=='4' && ch2=='1') || (ch1=='5' && ch2=='1') || (ch1=='6' && ch2=='1') || (ch1=='7' && ch2=='1') || (ch1=='8' && ch2=='1') || (ch1=='9' && ch2=='1') || (ch1=='3' && ch2=='2') || (ch1=='4' && ch2=='2') || (ch1=='5' && ch2=='2') || (ch1=='6' && ch2=='2') || (ch1=='7' && ch2=='2') || (ch1=='8' && ch2=='2') || (ch1=='9' && ch2=='2') || (ch1=='4' && ch2=='3') || (ch1=='5' && ch2=='3') || (ch1=='6' && ch2=='3') || (ch1=='7' && ch2=='3') || (ch1=='8' && ch2=='3') || (ch1=='9' && ch2=='3') || (ch1=='5' && ch2=='4') || (ch1=='6' && ch2=='4') || (ch1=='7' && ch2=='4') || (ch1=='8' && ch2=='4') || (ch1=='9' && ch2=='4') || (ch1=='6' && ch2=='5') || (ch1=='7' && ch2=='5') || (ch1=='8' && ch2=='5') || (ch1=='9' && ch2=='5') || (ch1=='7' && ch2=='6') || (ch1=='8' && ch2=='6') || (ch1=='9' && ch2=='6') || (ch1=='8' && ch2=='7') || (ch1=='9' && ch2=='7') || (ch1=='9' && ch2=='8')) {
        return '>';
    }
    return '=';
}

// comparing 2 lists by taking their integral,decimal part
char compare (list a, list b, list a1, list b1) {
    char ans='=';
    node *temp1=a.head, *temp2=b.head;
    while (temp1 && temp2) {
        if (com(temp1->data, temp2->data)=='>') {
            ans='>';
        }
        else {
            if (com(temp1->data, temp2->data)=='<') {
                ans='<';
            }
        }
        temp1=temp1->next;
        temp2=temp2->next;
    }
    if (temp1) {
        return '>';
    }
    if (temp2) {
        return '<';
    }
    if (ans!='=') {
        return ans;
    }
    node *temp3=a1.head, *temp4=b1.head;
    while (temp3 && temp4) {
        ans=com(temp3->data, temp4->data);
        if (ans!='=') {
            return ans;
        }
        temp3=temp3->next;
        temp4=temp4->next;
    }
    if (temp3) {
        while (temp3) {
            if (temp3->data!='0') {
                return '>';
            }
            temp3=temp3->next;
        }
    }
    if (temp4) {
        while (temp4) {
            if (temp4->data!='0') {
                return '<';
            }
            temp4=temp4->next;
        }
    }
    return '=';
}

// funtion for adding integral part of number
list addTwoLists(node* first, node* second)
{
    list res;
    char ch,carry=car;
    while (first != NULL || second != NULL) {
        if (first==NULL) {
            ch=add('0',second->data,&carry);
        }
        if (second==NULL) {
            ch=add(first->data,'0',&carry);
        }
        if (first && second) {
            ch=add(first->data,second->data,&carry);
        }
        res.additem(ch);
        if (first) {
            first = first->next;
        }
        if (second) {
            second = second->next;
        }
    }

    if (carry=='1') {
        res.additem('1');
    }
    return res;
}

// function for adding decimal part of number
list addTwoLists_dec(list a, list b)
{
    node *temp1=a.head,*temp2=b.head;
    while (temp1 && temp2) {
        temp1=temp1->next;
        temp2=temp2->next;
    }
	// making both same length
    while (temp1) {
        b.additem('0');
        temp1=temp1->next;
    }
    while (temp2) {
        a.additem('0');
        temp2=temp2->next;
    }
    list res;
    node *first=a.head, *second=b.head;
    char ch,carry='0';
    while (first != NULL || second != NULL) {
        if (first==NULL) {
            ch=add('0',second->data,&carry);
        }
        if (second==NULL) {
            ch=add(first->data,'0',&carry);
        }
        if (first && second) {
            ch=add(first->data,second->data,&carry);
        }
		if (res.head==NULL) {
			if (ch!='0') {
				res.additem(ch);
			}
		}
		else {
			res.additem(ch);
		}
        if (first) {
            first = first->next;
        }
        if (second) {
            second = second->next;
        }
    }
	car=carry;
    return res;
}

// funtion for subtracting integral part of number
list subTwoLists(node* first, node* second)
{
    list res;
    char ch,carry=car;
    while (first != NULL || second != NULL) {
        if (first==NULL) {
            ch=sub('0',second->data,&carry);
        }
        if (second==NULL) {
            ch=sub(first->data,'0',&carry);
        }
        if (first && second) {
            ch=sub(first->data,second->data,&carry);
        }
        res.additem(ch);
        if (first) {
            first = first->next;
        }
        if (second) {
            second = second->next;
        }
    }
	node *temp=res.head;
	while (temp!=NULL) {
		if (temp->data=='0') {
			temp=temp->next;
			res.deltop();
		}
		else {
			break;
		}
	}
    return res;
}

// function for subtracting decimal part of number
list subTwoLists_dec(list a, list b)
{
    node *temp1=a.head,*temp2=b.head;
    while (temp1 && temp2) {
        temp1=temp1->next;
        temp2=temp2->next;
    }
	// making both same length
    while (temp1) {
        b.additem('0');
        temp1=temp1->next;
    }
    while (temp2) {
        a.additem('0');
        temp2=temp2->next;
    }
    list res;
    node *first=a.head, *second=b.head;
    char ch,carry='0';
    while (first != NULL || second != NULL) {
        if (first==NULL) {
            ch=sub('0',second->data,&carry);
        }
        if (second==NULL) {
            ch=sub(first->data,'0',&carry);
        }
        if (first && second) {
            ch=sub(first->data,second->data,&carry);
        }
		if (res.head==NULL) {
			if (ch!='0') {
				res.additem(ch);
			}
		}
		else {
			res.additem(ch);
		}
        if (first) {
            first = first->next;
        }
        if (second) {
            second = second->next;
        }
    }
	car=carry;
    return res;
}

int main () {
	fstream file;
	char c,ans;
	list a, b, a_int, b_int, a_dec, b_dec, a_neg, b_neg, ans_int, ans_dec;
	file.open("input.txt");

	    if(!file.is_open()){
        cout<<"It is failed to open"<<endl;
        return 0;
    }
	// we are taking care to change 002 to 2 for integer parts
	// we are adding decimals in backward direction
	while(file.get(c)) {
        if (c=='-') {
            a_neg.addend(c);
            a.addend(c);
            continue;
        }
		if(c == '.' || c == '\n') {
            break;
        }
		if (a_int.head==NULL) {
			if (c=='0') {
				continue;
			}
		}
        a.addend(c);
		a_int.additem(c);
	}
    if (c == '.') {
        a.addend(c);
        while(file.get(c)) {
		    if(c == '\n') {
                break;
            }
            a.addend(c);
		    a_dec.additem(c);
	    }
    }
	while(file.get(c)) {
        if (c=='-') {
            b.addend(c);
            b_neg.addend(c);
            continue;
        }
		if (b_int.head==NULL) {
			if (c=='0') {
				continue;
			}
		}
		if(c == '.' || c == '\n') {
            break;
        }
        b.addend(c);
		b_int.additem(c);
	}
    if (c == '.') {
        b.addend(c);
        while(file.get(c)) {
		    if(c == '\n') {
                break;
            }
            b.addend(c);
		    b_dec.additem(c);
	    }
    }
	ans=compare(a_int,b_int,a_dec,b_dec);
	// storing integral,decimal parts of answer in ans_int,ans_dec respectively
	if (a_neg.head==NULL && b_neg.head==NULL) {
		if (ans!='<') {
			ans_dec=subTwoLists_dec(a_dec,b_dec);
			ans_int=subTwoLists(a_int.head,b_int.head);
			ans='+';
		}
		else {
			ans_dec=subTwoLists_dec(b_dec,a_dec);
			ans_int=subTwoLists(b_int.head,a_int.head);
			ans='-';
		}
	}
	if (a_neg.head && b_neg.head==NULL) {
		ans_dec=addTwoLists_dec(a_dec,b_dec);
		ans_int=addTwoLists(a_int.head,b_int.head);
		ans='-';
	}
	if (a_neg.head==NULL && b_neg.head) {
		ans_dec=addTwoLists_dec(a_dec,b_dec);
		ans_int=addTwoLists(a_int.head,b_int.head);
		ans='+';
	}
	if (a_neg.head && b_neg.head) {
		if (ans!='<') {
			ans_dec=subTwoLists_dec(a_dec,b_dec);
			ans_int=subTwoLists(a_int.head,b_int.head);
			ans='-';
		}
		else {
			ans_dec=subTwoLists_dec(b_dec,a_dec);
			ans_int=subTwoLists(b_int.head,a_int.head);
			ans='+';
		}
	}
	cout << "(";
	a.display();
	cout << ") - (";
	b.display();
	cout << ") = " << ans;
    ans_int.display();
	// checking if decimal point (.) is required
    if (ans_dec.head) {
		// checking if we must add zero before decimal
		if (ans_int.head==NULL) {
			cout << "0";
		}
        cout << ".";
        ans_dec.display();
    }
	if (ans_dec.head==NULL && ans_int.head==NULL) {
		cout << "0";
	}
	file.close();
	return 0;
}
