/*--------------------------------------- MALOTH DILEEP -------------------------------------------
-----------------------------------------   19MA20024   -------------------------------------------*/



#include<iostream>
#include<fstream>
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
    	void add_front(char a);
        void add_end(char a);
    	void display();
        void display_reverse();
};

void list::add_front(char a){ // added a new node in front of the list
	node *newnode = new node;
	newnode-> data = a;
	newnode-> prev = NULL;
	newnode->next = head;
	if(head!=NULL){
		head->prev = newnode;
	}
	head = newnode;
	if (newnode->next!=NULL && (newnode->next)->next==NULL){  // the first instance where the head and tail separate out
		tail=newnode->next;
	}
}

void list::add_end(char a){
	node* newnode = new node;
	newnode->data = a;
	if(tail!=NULL){
		tail->next = newnode;
	}
	newnode->prev=tail;         // initially attaches new node after tail
	tail = newnode;         // tail becomes the last node again
	tail->next = NULL;
	if (newnode->prev!=NULL and (newnode->prev)->prev==NULL){  // the first instance where the head and tail separate out
		head=newnode->prev;
	}
}

void list::display(){
	node* current = head;
	while(current != NULL){
		cout << current->data;
		current = current->next;
	}
}

void list::display_reverse() {
    if (head->next==NULL) {
        cout << head->data;
        return;
    }
    node* current = tail;
    while (current != NULL) {
        cout << current->data;
        current = current->prev;
    }
}

char com(char ch1, char ch2) {
    if ((ch1=='0' && ch2=='1') || (ch1=='0' && ch2=='2') || (ch1=='0' && ch2=='3') || (ch1=='0' && ch2=='4') || (ch1=='0' && ch2=='5') || (ch1=='0' && ch2=='6') || (ch1=='0' && ch2=='7') || (ch1=='0' && ch2=='8') || (ch1=='0' && ch2=='9') || (ch1=='1' && ch2=='2') || (ch1=='1' && ch2=='3') || (ch1=='1' && ch2=='4') || (ch1=='1' && ch2=='5') || (ch1=='1' && ch2=='6') || (ch1=='1' && ch2=='7') || (ch1=='1' && ch2=='8') || (ch1=='1' && ch2=='9') || (ch1=='2' && ch2=='3') || (ch1=='2' && ch2=='4') || (ch1=='2' && ch2=='5') || (ch1=='2' && ch2=='6') || (ch1=='2' && ch2=='7') || (ch1=='2' && ch2=='8') || (ch1=='2' && ch2=='9') || (ch1=='3' && ch2=='4') || (ch1=='3' && ch2=='5') || (ch1=='3' && ch2=='6') || (ch1=='3' && ch2=='7') || (ch1=='3' && ch2=='8') || (ch1=='3' && ch2=='9') || (ch1=='4' && ch2=='5') || (ch1=='4' && ch2=='6') || (ch1=='4' && ch2=='7') || (ch1=='4' && ch2=='8') || (ch1=='4' && ch2=='9') || (ch1=='5' && ch2=='6') || (ch1=='5' && ch2=='7') || (ch1=='5' && ch2=='8') || (ch1=='5' && ch2=='9') || (ch1=='6' && ch2=='7') || (ch1=='6' && ch2=='8') || (ch1=='6' && ch2=='9') || (ch1=='7' && ch2=='8') || (ch1=='7' && ch2=='9') || (ch1=='8' && ch2=='9')) {
        return '<';
    }
    if ((ch1=='1' && ch2=='0') || (ch1=='2' && ch2=='0') || (ch1=='3' && ch2=='0') || (ch1=='4' && ch2=='0') || (ch1=='5' && ch2=='0') || (ch1=='6' && ch2=='0') || (ch1=='7' && ch2=='0') || (ch1=='8' && ch2=='0') || (ch1=='9' && ch2=='0') || (ch1=='2' && ch2=='1') || (ch1=='3' && ch2=='1') || (ch1=='4' && ch2=='1') || (ch1=='5' && ch2=='1') || (ch1=='6' && ch2=='1') || (ch1=='7' && ch2=='1') || (ch1=='8' && ch2=='1') || (ch1=='9' && ch2=='1') || (ch1=='3' && ch2=='2') || (ch1=='4' && ch2=='2') || (ch1=='5' && ch2=='2') || (ch1=='6' && ch2=='2') || (ch1=='7' && ch2=='2') || (ch1=='8' && ch2=='2') || (ch1=='9' && ch2=='2') || (ch1=='4' && ch2=='3') || (ch1=='5' && ch2=='3') || (ch1=='6' && ch2=='3') || (ch1=='7' && ch2=='3') || (ch1=='8' && ch2=='3') || (ch1=='9' && ch2=='3') || (ch1=='5' && ch2=='4') || (ch1=='6' && ch2=='4') || (ch1=='7' && ch2=='4') || (ch1=='8' && ch2=='4') || (ch1=='9' && ch2=='4') || (ch1=='6' && ch2=='5') || (ch1=='7' && ch2=='5') || (ch1=='8' && ch2=='5') || (ch1=='9' && ch2=='5') || (ch1=='7' && ch2=='6') || (ch1=='8' && ch2=='6') || (ch1=='9' && ch2=='6') || (ch1=='8' && ch2=='7') || (ch1=='9' && ch2=='7') || (ch1=='9' && ch2=='8')) {
        return '>';
    }
    return '=';
}

char compare_int(list a, list b) {
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
    return ans;
}

char compare_dec(list a, list b) {
    char ans='=';
    node *temp1=a.head, *temp2=b.head;
    while (temp1 && temp2) {
        ans=com(temp1->data, temp2->data);
        if (ans!='=') {
            return ans;
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
    return '=';
}

int main () {
	fstream myfile;
	char c,ans;
	list int_x, int_y, deci_x, deci_y, int_ans, deci_ans;
	myfile.open("b.txt");

	//  to change 002 to 2 for integer parts
	// we are adding decimals in backward direction

	while(myfile.get(c)) {
		if(c == '.' || c == '\n') {
            break;
        }
		if (int_x.head==NULL) {
			if (c=='0') {
				continue;
			}
		}
		int_x.add_front(c);
	}
    if (c == '.') {
        while(myfile.get(c)) {
		    if(c == '\n') {
                break;
            }
		    deci_x.add_end(c);
	    }
    }
	while(myfile.get(c)) {
		if(c == '.' || c == '\n') {
            break;
        }
		if (int_y.head==NULL) {
			if (c=='0') {
				continue;
			}
		}
		int_y.add_front(c);
	}
    if (c == '.') {
        while(myfile.get(c)) {
		    if(c == '\n') {
                break;
            }
		    deci_y.add_end(c);
	    }
    }
    ans=compare_int(int_x,int_y);
    if (ans=='=') {
        ans=compare_dec(deci_x,deci_y);
    }
    int_x.display_reverse();
	// checking if decimal point (.) is required
    if (deci_x.head) {
		// checking if we must add zero before decimal
		if (int_x.head==NULL) {
			cout << "0";
		}
        cout << ".";
        deci_x.display();
    }
    cout << " " << ans << " ";
    int_y.display_reverse();
	// checking if decimal point (.) is required
    if (deci_y.head) {
		// checking if we must add zero before decimal
		if (int_y.head==NULL) {
			cout << "0";
		}
        cout << ".";
        deci_y.display();
    }
	myfile.close();
	return 0;
}
