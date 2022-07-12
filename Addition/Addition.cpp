/*----------------------   MALOTH DILEEP _ 19MA20024     ------------------------*/



#include <iostream>
#include <fstream>
using namespace std;

struct node                    // single node or link of the list
 {
 	char data;
 	node* next;
 	node* prev;
 };
 class list                    // a list of links
{
	private:
	    node * head;           // pointer to the head link
	    node * tail;           // pointer to the tail link
    public:
    	list()                 // zero argument constructor
    	{
    	    head=NULL;
    	    tail = NULL;
    	    head = tail;
    	}
    	void add_front(char d);
    	void add_end(char d);
    	void deltop();
    	void delend();
    	void display();
    	node* head_deci();
    	node* Tail()
    	{
    	    return(tail);
    	}
    	node* Head()           // returns head of the linked list
    	{
    	    return(head);
    	}
};
node* list::head_deci()        // returns address of the link containing decimal point
{
    node *current = head;
    while(current!=NULL)
    {
        if(current->data == '.')
            break;
        current = current->next;
    }
    return(current);
}

void list::deltop()            // deletes the first data item
{
    if(head==NULL)
    {
    }
    else if (head->next==NULL)
    {
        head = NULL;
    }
    else
    {
        head=head->next;
        delete (head->prev);   // deletes the erstwhile head
        head->prev = NULL;
    }
}

void list::delend()            // deletes the last data item
{
    if (tail==NULL)
    {}
    else if (tail->prev==NULL)
    {
        tail = NULL;
    }
    else
    {
        tail = tail -> prev;
        delete (tail->next);
        tail->next = NULL;
    }
}

void list::add_front(char d)     // added a new node in front of the list
{
    node *newnode = new node;
    newnode-> data = d;
    newnode-> prev = NULL;
    newnode->next = head;
    if(head!=NULL)
    {
        head->prev = newnode;
    }
    head = newnode;
    if (newnode->next!=NULL and (newnode->next)->next==NULL)  // the first instance where the head and tail separate out
    {
        tail=newnode->next;
    }
}

void list::display()          // displays the whole linked list
{
    node* current = head;
    while(current != NULL)
    {
        cout << current->data ;
        current = current->next;
    }
    cout<<endl;
}

void list::add_end(char d)    // adds a data item to the linked list (at the back)
{
	node* newnode = new node;
	newnode->data = d;

	if(tail!=NULL)
	{
		tail->next = newnode;
	}
	newnode->prev=tail;                                       // initially attaches new node after tail
	tail = newnode;                                           // tail becomes the last node once again
	tail->next = NULL;
	if (newnode->prev!=NULL and (newnode->prev)->prev==NULL)  // the first instance where the head and tail separate out
    {
        head=newnode->prev;
    }
}


char Add_digits(char a,char b,char *carry);                // returns sum of digits and updates carry

list Remove_zeros(list l)            // removes insignificant zeros
{
    node *head1,*head2,*current,*head,*tail;
    head1 = l.head_deci();
    head2 = l.head_deci()->prev;
    head = l.Head();
    tail = l.Tail();
    current = tail;
    while(current != head1)          // removing insignificant zeros at the end
    {
        if(current->data != '0')
            break;
        current = current->prev;
        l.delend();
    }
    if(l.Tail()->data == '.')
        l.delend();
    current = head;
    while(current != head2)          // removing insignificant zeros at the front
    {
        if(current->data != '0')
            break;
        current = current->next;
        l.deltop();
    }
    return(l);
}

void Add(node* curr_1,node* curr_2,list Sum,char carry)    // Adds digits in current node and stores the sum in linked list Sum and call the function recursively
{
    if(curr_1 == NULL && curr_2 == NULL)       // the numbers are completly traveled so the sum is printed out using display
    {
        if(carry == '1')
            Sum.add_front('1');
        Sum = Remove_zeros(Sum);
        cout<<"\n Sum of the numbers is : ";
        Sum.display();
    }
    else if(curr_1->data == '.' && curr_2->data == '.')  // if current link contains decimal point we skip this link
    {
        Sum.add_front('.');
        Add(curr_1->prev,curr_2->prev,Sum,carry);
    }
    else          // Adds digits in current node and stores the sum in linked list Sum and call the function recursively
    {
        char c = Add_digits(curr_1->data,curr_2->data,&carry);
        Sum.add_front(c);
        Add(curr_1->prev,curr_2->prev,Sum,carry);
    }
}
list check_decimal(list l)       // converts ur number into nice form eg:- if number is .23 converts into 0.23
{
    if(l.Head()->data == '.')
        l.add_front('0');
    if(l.Tail()->data == '.')
        l.add_end('0');
    char c = '0';
    node *current = l.Head();
    while(current != NULL)
    {
        if(current->data == '.')
        {
            c = '1'; break;
        }
        current = current->next;
    }
    if(c == '0')
    {
        l.add_end('.');
        l.add_end('0');
    }
    return(l);
}
int main()
{
    fstream myfile;
    myfile.open("input.txt");          // to open my text file
    char c;
    list Li1,Li2;                          // Li1,Li2 are two numbers
    if(myfile.is_open())
    {
        while(myfile.get(c) && c != '\n')  // while loop to read number 1
        {
            Li1.add_end(c);                 // To add char at end of Li1
        }
        while(myfile.get(c) && c != '\n')  // while loop to read number 1
        {
            Li2.add_end(c);                 // To add char at end of Li2
        }
        myfile.close();
    }
    else
        cout<<"\n Couldn't open the file\n";

    Li1 = check_decimal(Li1);             // to convert our numbers into nice form foe eg :- .23 to 0.23
    Li2 = check_decimal(Li2);

    cout<<"\nNumbers in the text file are:\n";
    Li1.display();
    Li2.display();

    node *decimal_Li1,*decimal_Li2;       // To store the heads of the link containing decimal point
    decimal_Li1 = Li1.head_deci();
    decimal_Li2 = Li2.head_deci();

    node *current_Li1 = decimal_Li1;      // stores head of the link ontaining decimal point
    node *current_Li2 = decimal_Li2;

    while(current_Li1->next != NULL || current_Li2->next != NULL)  // To add zeros at the end such that both numbers have same fractional part length
    {
        if(current_Li1->next == NULL)
        {
            Li1.add_end('0');
        }
        if(current_Li2->next == NULL)
        {
            Li2.add_end('0');
        }
        current_Li1 = current_Li1->next;
        current_Li2 = current_Li2->next;
    }

    while(current_Li1->prev != NULL || current_Li2->prev != NULL)  // To add zeros at the front such that both numbers have same length
    {
        if(current_Li1->prev == NULL)
        {
            Li1.add_front('0');
        }
        if(current_Li2->prev == NULL)
        {
            Li2.add_front('0');
        }
        current_Li1 = current_Li1->prev;
        current_Li2 = current_Li2->prev;
    }
    // Displaying numbers after adding zero's
    cout<<"\nNumbers after adding zeros:\n";
    Li1.display();
    Li2.display();

    list Sum;
    char carry= '0';
    Add(Li1.Tail(),Li2.Tail(),Sum,carry);  // Function to find sum of numbers

    return 0;
}

char Add_digits(char a,char b,char *carry)  // returns sum of digits and updates carry
{
 if(a == '0' && b == '0')
   {
       if(*carry == '0')
       {
           *carry = '0';
           return('0');
       }
       if(*carry == '1')
       {
           *carry = '0';
            return('1');
       }
   }
   if(a == '0' && b == '1')
   {
       if(*carry == '0')
       {
           *carry = '0';
           return('1');
       }
       if(*carry == '1')
       {
           *carry = '0';
            return('2');
       }
   }
   if(a == '0' && b == '2')
   {
       if(*carry == '0')
       {
           *carry = '0';
           return('2');
       }
       if(*carry == '1')
       {
           *carry = '0';
            return('3');
       }
   }
   if(a == '0' && b == '3')
   {
       if(*carry == '0')
       {
           *carry = '0';
           return('3');
       }
       if(*carry == '1')
       {
           *carry = '0';
            return('4');
       }
   }
   if(a == '0' && b == '4')
   {
       if(*carry == '0')
       {
           *carry = '0';
           return('4');
       }
       if(*carry == '1')
       {
           *carry = '0';
            return('5');
       }
   }
   if(a == '0' && b == '5')
   {
       if(*carry == '0')
       {
           *carry = '0';
           return('5');
       }
       if(*carry == '1')
       {
           *carry = '0';
            return('6');
       }
   }
   if(a == '0' && b == '6')
   {
       if(*carry == '0')
       {
           *carry = '0';
           return('6');
       }
       if(*carry == '1')
       {
           *carry = '0';
            return('7');
       }
   }
   if(a == '0' && b == '7')
   {
       if(*carry == '0')
       {
           *carry = '0';
           return('7');
       }
       if(*carry == '1')
       {
           *carry = '0';
            return('8');
       }
   }
   if(a == '0' && b == '8')
   {
       if(*carry == '0')
       {
           *carry = '0';
           return('8');
       }
       if(*carry == '1')
       {
           *carry = '0';
            return('9');
       }
   }
   if(a == '0' && b == '9')
   {
       if(*carry == '0')
       {
           *carry = '0';
           return('9');
       }
       if(*carry == '1')
       {
           *carry = '1';
            return('0');
       }
   }
   if(a == '1' && b == '0')
   {
       if(*carry == '0')
       {
           *carry = '0';
           return('1');
       }
       if(*carry == '1')
       {
           *carry = '0';
            return('2');
       }
   }
   if(a == '1' && b == '1')
   {
       if(*carry == '0')
       {
           *carry = '0';
           return('2');
       }
       if(*carry == '1')
       {
           *carry = '0';
            return('3');
       }
   }
   if(a == '1' && b == '2')
   {
       if(*carry == '0')
       {
           *carry = '0';
           return('3');
       }
       if(*carry == '1')
       {
           *carry = '0';
            return('4');
       }
   }
   if(a == '1' && b == '3')
   {
       if(*carry == '0')
       {
           *carry = '0';
           return('4');
       }
       if(*carry == '1')
       {
           *carry = '0';
            return('5');
       }
   }
   if(a == '1' && b == '4')
   {
       if(*carry == '0')
       {
           *carry = '0';
           return('5');
       }
       if(*carry == '1')
       {
           *carry = '0';
            return('6');
       }
   }
   if(a == '1' && b == '5')
   {
       if(*carry == '0')
       {
           *carry = '0';
           return('6');
       }
       if(*carry == '1')
       {
           *carry = '0';
            return('7');
       }
   }
   if(a == '1' && b == '6')
   {
       if(*carry == '0')
       {
           *carry = '0';
           return('7');
       }
       if(*carry == '1')
       {
           *carry = '0';
            return('8');
       }
   }
   if(a == '1' && b == '7')
   {
       if(*carry == '0')
       {
           *carry = '0';
           return('8');
       }
       if(*carry == '1')
       {
           *carry = '0';
            return('9');
       }
   }
   if(a == '1' && b == '8')
   {
       if(*carry == '0')
       {
           *carry = '0';
           return('9');
       }
       if(*carry == '1')
       {
           *carry = '1';
            return('0');
       }
   }
   if(a == '1' && b == '9')
   {
       if(*carry == '0')
       {
           *carry = '1';
           return('0');
       }
       if(*carry == '1')
       {
           *carry = '1';
            return('1');
       }
   }
   if(a == '2' && b == '0')
   {
       if(*carry == '0')
       {
           *carry = '0';
           return('2');
       }
       if(*carry == '1')
       {
           *carry = '0';
            return('3');
       }
   }
   if(a == '2' && b == '1')
   {
       if(*carry == '0')
       {
           *carry = '0';
           return('3');
       }
       if(*carry == '1')
       {
           *carry = '0';
            return('4');
       }
   }
   if(a == '2' && b == '2')
   {
       if(*carry == '0')
       {
           *carry = '0';
           return('4');
       }
       if(*carry == '1')
       {
           *carry = '0';
            return('5');
       }
   }
   if(a == '2' && b == '3')
   {
       if(*carry == '0')
       {
           *carry = '0';
           return('5');
       }
       if(*carry == '1')
       {
           *carry = '0';
            return('6');
       }
   }
   if(a == '2' && b == '4')
   {
       if(*carry == '0')
       {
           *carry = '0';
           return('6');
       }
       if(*carry == '1')
       {
           *carry = '0';
            return('7');
       }
   }
   if(a == '2' && b == '5')
   {
       if(*carry == '0')
       {
           *carry = '0';
           return('7');
       }
       if(*carry == '1')
       {
           *carry = '0';
            return('8');
       }
   }
   if(a == '2' && b == '6')
   {
       if(*carry == '0')
       {
           *carry = '0';
           return('8');
       }
       if(*carry == '1')
       {
           *carry = '0';
            return('9');
       }
   }
   if(a == '2' && b == '7')
   {
       if(*carry == '0')
       {
           *carry = '0';
           return('9');
       }
       if(*carry == '1')
       {
           *carry = '1';
            return('0');
       }
   }
   if(a == '2' && b == '8')
   {
       if(*carry == '0')
       {
           *carry = '1';
           return('0');
       }
       if(*carry == '1')
       {
           *carry = '1';
            return('1');
       }
   }
   if(a == '2' && b == '9')
   {
       if(*carry == '0')
       {
           *carry = '1';
           return('1');
       }
       if(*carry == '1')
       {
           *carry = '1';
            return('2');
       }
   }
   if(a == '3' && b == '0')
   {
       if(*carry == '0')
       {
           *carry = '0';
           return('3');
       }
       if(*carry == '1')
       {
           *carry = '0';
            return('4');
       }
   }
   if(a == '3' && b == '1')
   {
       if(*carry == '0')
       {
           *carry = '0';
           return('4');
       }
       if(*carry == '1')
       {
           *carry = '0';
            return('5');
       }
   }
   if(a == '3' && b == '2')
   {
       if(*carry == '0')
       {
           *carry = '0';
           return('5');
       }
       if(*carry == '1')
       {
           *carry = '0';
            return('6');
       }
   }
   if(a == '3' && b == '3')
   {
       if(*carry == '0')
       {
           *carry = '0';
           return('6');
       }
       if(*carry == '1')
       {
           *carry = '0';
            return('7');
       }
   }
   if(a == '3' && b == '4')
   {
       if(*carry == '0')
       {
           *carry = '0';
           return('7');
       }
       if(*carry == '1')
       {
           *carry = '0';
            return('8');
       }
   }
   if(a == '3' && b == '5')
   {
       if(*carry == '0')
       {
           *carry = '0';
           return('8');
       }
       if(*carry == '1')
       {
           *carry = '0';
            return('9');
       }
   }
   if(a == '3' && b == '6')
   {
       if(*carry == '0')
       {
           *carry = '0';
           return('9');
       }
       if(*carry == '1')
       {
           *carry = '1';
            return('0');
       }
   }
   if(a == '3' && b == '7')
   {
       if(*carry == '0')
       {
           *carry = '1';
           return('0');
       }
       if(*carry == '1')
       {
           *carry = '1';
            return('1');
       }
   }
   if(a == '3' && b == '8')
   {
       if(*carry == '0')
       {
           *carry = '1';
           return('1');
       }
       if(*carry == '1')
       {
           *carry = '1';
            return('2');
       }
   }
   if(a == '3' && b == '9')
   {
       if(*carry == '0')
       {
           *carry = '1';
           return('2');
       }
       if(*carry == '1')
       {
           *carry = '1';
            return('3');
       }
   }
   if(a == '4' && b == '0')
   {
       if(*carry == '0')
       {
           *carry = '0';
           return('4');
       }
       if(*carry == '1')
       {
           *carry = '0';
            return('5');
       }
   }
   if(a == '4' && b == '1')
   {
       if(*carry == '0')
       {
           *carry = '0';
           return('5');
       }
       if(*carry == '1')
       {
           *carry = '0';
            return('6');
       }
   }
   if(a == '4' && b == '2')
   {
       if(*carry == '0')
       {
           *carry = '0';
           return('6');
       }
       if(*carry == '1')
       {
           *carry = '0';
            return('7');
       }
   }
   if(a == '4' && b == '3')
   {
       if(*carry == '0')
       {
           *carry = '0';
           return('7');
       }
       if(*carry == '1')
       {
           *carry = '0';
            return('8');
       }
   }
   if(a == '4' && b == '4')
   {
       if(*carry == '0')
       {
           *carry = '0';
           return('8');
       }
       if(*carry == '1')
       {
           *carry = '0';
            return('9');
       }
   }
   if(a == '4' && b == '5')
   {
       if(*carry == '0')
       {
           *carry = '0';
           return('9');
       }
       if(*carry == '1')
       {
           *carry = '1';
            return('0');
       }
   }
   if(a == '4' && b == '6')
   {
       if(*carry == '0')
       {
           *carry = '1';
           return('0');
       }
       if(*carry == '1')
       {
           *carry = '1';
            return('1');
       }
   }
   if(a == '4' && b == '7')
   {
       if(*carry == '0')
       {
           *carry = '1';
           return('1');
       }
       if(*carry == '1')
       {
           *carry = '1';
            return('2');
       }
   }
   if(a == '4' && b == '8')
   {
       if(*carry == '0')
       {
           *carry = '1';
           return('2');
       }
       if(*carry == '1')
       {
           *carry = '1';
            return('3');
       }
   }
   if(a == '4' && b == '9')
   {
       if(*carry == '0')
       {
           *carry = '1';
           return('3');
       }
       if(*carry == '1')
       {
           *carry = '1';
            return('4');
       }
   }
   if(a == '5' && b == '0')
   {
       if(*carry == '0')
       {
           *carry = '0';
           return('5');
       }
       if(*carry == '1')
       {
           *carry = '0';
            return('6');
       }
   }
   if(a == '5' && b == '1')
   {
       if(*carry == '0')
       {
           *carry = '0';
           return('6');
       }
       if(*carry == '1')
       {
           *carry = '0';
            return('7');
       }
   }
   if(a == '5' && b == '2')
   {
       if(*carry == '0')
       {
           *carry = '0';
           return('7');
       }
       if(*carry == '1')
       {
           *carry = '0';
            return('8');
       }
   }
   if(a == '5' && b == '3')
   {
       if(*carry == '0')
       {
           *carry = '0';
           return('8');
       }
       if(*carry == '1')
       {
           *carry = '0';
            return('9');
       }
   }
   if(a == '5' && b == '4')
   {
       if(*carry == '0')
       {
           *carry = '0';
           return('9');
       }
       if(*carry == '1')
       {
           *carry = '1';
            return('0');
       }
   }
   if(a == '5' && b == '5')
   {
       if(*carry == '0')
       {
           *carry = '1';
           return('0');
       }
       if(*carry == '1')
       {
           *carry = '1';
            return('1');
       }
   }
   if(a == '5' && b == '6')
   {
       if(*carry == '0')
       {
           *carry = '1';
           return('1');
       }
       if(*carry == '1')
       {
           *carry = '1';
            return('2');
       }
   }
   if(a == '5' && b == '7')
   {
       if(*carry == '0')
       {
           *carry = '1';
           return('2');
       }
       if(*carry == '1')
       {
           *carry = '1';
            return('3');
       }
   }
   if(a == '5' && b == '8')
   {
       if(*carry == '0')
       {
           *carry = '1';
           return('3');
       }
       if(*carry == '1')
       {
           *carry = '1';
            return('4');
       }
   }
   if(a == '5' && b == '9')
   {
       if(*carry == '0')
       {
           *carry = '1';
           return('4');
       }
       if(*carry == '1')
       {
           *carry = '1';
            return('5');
       }
   }
   if(a == '6' && b == '0')
   {
       if(*carry == '0')
       {
           *carry = '0';
           return('6');
       }
       if(*carry == '1')
       {
           *carry = '0';
            return('7');
       }
   }
   if(a == '6' && b == '1')
   {
       if(*carry == '0')
       {
           *carry = '0';
           return('7');
       }
       if(*carry == '1')
       {
           *carry = '0';
            return('8');
       }
   }
   if(a == '6' && b == '2')
   {
       if(*carry == '0')
       {
           *carry = '0';
           return('8');
       }
       if(*carry == '1')
       {
           *carry = '0';
            return('9');
       }
   }
   if(a == '6' && b == '3')
   {
       if(*carry == '0')
       {
           *carry = '0';
           return('9');
       }
       if(*carry == '1')
       {
           *carry = '1';
            return('0');
       }
   }
   if(a == '6' && b == '4')
   {
       if(*carry == '0')
       {
           *carry = '1';
           return('0');
       }
       if(*carry == '1')
       {
           *carry = '1';
            return('1');
       }
   }
   if(a == '6' && b == '5')
   {
       if(*carry == '0')
       {
           *carry = '1';
           return('1');
       }
       if(*carry == '1')
       {
           *carry = '1';
            return('2');
       }
   }
   if(a == '6' && b == '6')
   {
       if(*carry == '0')
       {
           *carry = '1';
           return('2');
       }
       if(*carry == '1')
       {
           *carry = '1';
            return('3');
       }
   }
   if(a == '6' && b == '7')
   {
       if(*carry == '0')
       {
           *carry = '1';
           return('3');
       }
       if(*carry == '1')
       {
           *carry = '1';
            return('4');
       }
   }
   if(a == '6' && b == '8')
   {
       if(*carry == '0')
       {
           *carry = '1';
           return('4');
       }
       if(*carry == '1')
       {
           *carry = '1';
            return('5');
       }
   }
   if(a == '6' && b == '9')
   {
       if(*carry == '0')
       {
           *carry = '1';
           return('5');
       }
       if(*carry == '1')
       {
           *carry = '1';
            return('6');
       }
   }
   if(a == '7' && b == '0')
   {
       if(*carry == '0')
       {
           *carry = '0';
           return('7');
       }
       if(*carry == '1')
       {
           *carry = '0';
            return('8');
       }
   }
   if(a == '7' && b == '1')
   {
       if(*carry == '0')
       {
           *carry = '0';
           return('8');
       }
       if(*carry == '1')
       {
           *carry = '0';
            return('9');
       }
   }
   if(a == '7' && b == '2')
   {
       if(*carry == '0')
       {
           *carry = '0';
           return('9');
       }
       if(*carry == '1')
       {
           *carry = '1';
            return('0');
       }
   }
   if(a == '7' && b == '3')
   {
       if(*carry == '0')
       {
           *carry = '1';
           return('0');
       }
       if(*carry == '1')
       {
           *carry = '1';
            return('1');
       }
   }
   if(a == '7' && b == '4')
   {
       if(*carry == '0')
       {
           *carry = '1';
           return('1');
       }
       if(*carry == '1')
       {
           *carry = '1';
            return('2');
       }
   }
   if(a == '7' && b == '5')
   {
       if(*carry == '0')
       {
           *carry = '1';
           return('2');
       }
       if(*carry == '1')
       {
           *carry = '1';
            return('3');
       }
   }
   if(a == '7' && b == '6')
   {
       if(*carry == '0')
       {
           *carry = '1';
           return('3');
       }
       if(*carry == '1')
       {
           *carry = '1';
            return('4');
       }
   }
   if(a == '7' && b == '7')
   {
       if(*carry == '0')
       {
           *carry = '1';
           return('4');
       }
       if(*carry == '1')
       {
           *carry = '1';
            return('5');
       }
   }
   if(a == '7' && b == '8')
   {
       if(*carry == '0')
       {
           *carry = '1';
           return('5');
       }
       if(*carry == '1')
       {
           *carry = '1';
            return('6');
       }
   }
   if(a == '7' && b == '9')
   {
       if(*carry == '0')
       {
           *carry = '1';
           return('6');
       }
       if(*carry == '1')
       {
           *carry = '1';
            return('7');
       }
   }
   if(a == '8' && b == '0')
   {
       if(*carry == '0')
       {
           *carry = '0';
           return('8');
       }
       if(*carry == '1')
       {
           *carry = '0';
            return('9');
       }
   }
   if(a == '8' && b == '1')
   {
       if(*carry == '0')
       {
           *carry = '0';
           return('9');
       }
       if(*carry == '1')
       {
           *carry = '1';
            return('0');
       }
   }
   if(a == '8' && b == '2')
   {
       if(*carry == '0')
       {
           *carry = '1';
           return('0');
       }
       if(*carry == '1')
       {
           *carry = '1';
            return('1');
       }
   }
   if(a == '8' && b == '3')
   {
       if(*carry == '0')
       {
           *carry = '1';
           return('1');
       }
       if(*carry == '1')
       {
           *carry = '1';
            return('2');
       }
   }
   if(a == '8' && b == '4')
   {
       if(*carry == '0')
       {
           *carry = '1';
           return('2');
       }
       if(*carry == '1')
       {
           *carry = '1';
            return('3');
       }
   }
   if(a == '8' && b == '5')
   {
       if(*carry == '0')
       {
           *carry = '1';
           return('3');
       }
       if(*carry == '1')
       {
           *carry = '1';
            return('4');
       }
   }
   if(a == '8' && b == '6')
   {
       if(*carry == '0')
       {
           *carry = '1';
           return('4');
       }
       if(*carry == '1')
       {
           *carry = '1';
            return('5');
       }
   }
   if(a == '8' && b == '7')
   {
       if(*carry == '0')
       {
           *carry = '1';
           return('5');
       }
       if(*carry == '1')
       {
           *carry = '1';
            return('6');
       }
   }
   if(a == '8' && b == '8')
   {
       if(*carry == '0')
       {
           *carry = '1';
           return('6');
       }
       if(*carry == '1')
       {
           *carry = '1';
            return('7');
       }
   }
   if(a == '8' && b == '9')
   {
       if(*carry == '0')
       {
           *carry = '1';
           return('7');
       }
       if(*carry == '1')
       {
           *carry = '1';
            return('8');
       }
   }
   if(a == '9' && b == '0')
   {
       if(*carry == '0')
       {
           *carry = '0';
           return('9');
       }
       if(*carry == '1')
       {
           *carry = '1';
            return('0');
       }
   }
   if(a == '9' && b == '1')
   {
       if(*carry == '0')
       {
           *carry = '1';
           return('0');
       }
       if(*carry == '1')
       {
           *carry = '1';
            return('1');
       }
   }
   if(a == '9' && b == '2')
   {
       if(*carry == '0')
       {
           *carry = '1';
           return('1');
       }
       if(*carry == '1')
       {
           *carry = '1';
            return('2');
       }
   }
   if(a == '9' && b == '3')
   {
       if(*carry == '0')
       {
           *carry = '1';
           return('2');
       }
       if(*carry == '1')
       {
           *carry = '1';
            return('3');
       }
   }
   if(a == '9' && b == '4')
   {
       if(*carry == '0')
       {
           *carry = '1';
           return('3');
       }
       if(*carry == '1')
       {
           *carry = '1';
            return('4');
       }
   }
   if(a == '9' && b == '5')
   {
       if(*carry == '0')
       {
           *carry = '1';
           return('4');
       }
       if(*carry == '1')
       {
           *carry = '1';
            return('5');
       }
   }
   if(a == '9' && b == '6')
   {
       if(*carry == '0')
       {
           *carry = '1';
           return('5');
       }
       if(*carry == '1')
       {
           *carry = '1';
            return('6');
       }
   }
   if(a == '9' && b == '7')
   {
       if(*carry == '0')
       {
           *carry = '1';
           return('6');
       }
       if(*carry == '1')
       {
           *carry = '1';
            return('7');
       }
   }
   if(a == '9' && b == '8')
   {
       if(*carry == '0')
       {
           *carry = '1';
           return('7');
       }
       if(*carry == '1')
       {
           *carry = '1';
            return('8');
       }
   }
   if(a == '9' && b == '9')
   {
       if(*carry == '0')
       {
           *carry = '1';
           return('8');
       }
       if(*carry == '1')
       {
           *carry = '1';
            return('9');
       }
   }

}
