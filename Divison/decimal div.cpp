/*----------------   QUESTION - 1              ----------
  ----------------   MALOTH DILEEP _ 19MA20024    -------   */

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
    void additem(char d); // adds data to the linked list (in front)
    void addend(char d);  // adds node with data d to the end of the list
    void deltop();        // deletes the first data item
    void display();       // displays the whole linked list
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

void list::deltop()
{
    if (head != NULL)
    {
        if (head->next == NULL)
        {
            head = NULL;
            tail = NULL;
        }
        else
        {
            head = head->next;
            head->prev = NULL;
        }
    }
}

void list::display()
{
    node *current = head;
    while (current != NULL)
    {
        cout << current->data;
        current = current->next;
    }
    cout << endl;
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

// function for subtracting without using '-' sign
char sub(char a, char b, char *carry)
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
            *carry = '1';
            return '9';
        }
    }
    if (a == '0' && b == '1')
    {
        if (*carry == '0')
        {
            *carry = '1';
            return '9';
        }
        else
        {
            *carry = '1';
            return '8';
        }
    }
    if (a == '0' && b == '2')
    {
        if (*carry == '0')
        {
            *carry = '1';
            return '8';
        }
        else
        {
            *carry = '1';
            return '7';
        }
    }
    if (a == '0' && b == '3')
    {
        if (*carry == '0')
        {
            *carry = '1';
            return '7';
        }
        else
        {
            *carry = '1';
            return '6';
        }
    }
    if (a == '0' && b == '4')
    {
        if (*carry == '0')
        {
            *carry = '1';
            return '6';
        }
        else
        {
            *carry = '1';
            return '5';
        }
    }
    if (a == '0' && b == '5')
    {
        if (*carry == '0')
        {
            *carry = '1';
            return '5';
        }
        else
        {
            *carry = '1';
            return '4';
        }
    }
    if (a == '0' && b == '6')
    {
        if (*carry == '0')
        {
            *carry = '1';
            return '4';
        }
        else
        {
            *carry = '1';
            return '3';
        }
    }
    if (a == '0' && b == '7')
    {
        if (*carry == '0')
        {
            *carry = '1';
            return '3';
        }
        else
        {
            *carry = '1';
            return '2';
        }
    }
    if (a == '0' && b == '8')
    {
        if (*carry == '0')
        {
            *carry = '1';
            return '2';
        }
        else
        {
            *carry = '1';
            return '1';
        }
    }
    if (a == '0' && b == '9')
    {
        if (*carry == '0')
        {
            *carry = '1';
            return '1';
        }
        else
        {
            *carry = '1';
            return '0';
        }
    }
    if (a == '1' && b == '0')
    {
        if (*carry == '0')
        {
            *carry = '0';
            return '1';
        }
        else
        {
            *carry = '0';
            return '0';
        }
    }
    if (a == '1' && b == '1')
    {
        if (*carry == '0')
        {
            *carry = '0';
            return '0';
        }
        else
        {
            *carry = '1';
            return '9';
        }
    }
    if (a == '1' && b == '2')
    {
        if (*carry == '0')
        {
            *carry = '1';
            return '9';
        }
        else
        {
            *carry = '1';
            return '8';
        }
    }
    if (a == '1' && b == '3')
    {
        if (*carry == '0')
        {
            *carry = '1';
            return '8';
        }
        else
        {
            *carry = '1';
            return '7';
        }
    }
    if (a == '1' && b == '4')
    {
        if (*carry == '0')
        {
            *carry = '1';
            return '7';
        }
        else
        {
            *carry = '1';
            return '6';
        }
    }
    if (a == '1' && b == '5')
    {
        if (*carry == '0')
        {
            *carry = '1';
            return '6';
        }
        else
        {
            *carry = '1';
            return '5';
        }
    }
    if (a == '1' && b == '6')
    {
        if (*carry == '0')
        {
            *carry = '1';
            return '5';
        }
        else
        {
            *carry = '1';
            return '4';
        }
    }
    if (a == '1' && b == '7')
    {
        if (*carry == '0')
        {
            *carry = '1';
            return '4';
        }
        else
        {
            *carry = '1';
            return '3';
        }
    }
    if (a == '1' && b == '8')
    {
        if (*carry == '0')
        {
            *carry = '1';
            return '3';
        }
        else
        {
            *carry = '1';
            return '2';
        }
    }
    if (a == '1' && b == '9')
    {
        if (*carry == '0')
        {
            *carry = '1';
            return '2';
        }
        else
        {
            *carry = '1';
            return '1';
        }
    }
    if (a == '2' && b == '0')
    {
        if (*carry == '0')
        {
            *carry = '0';
            return '2';
        }
        else
        {
            *carry = '0';
            return '1';
        }
    }
    if (a == '2' && b == '1')
    {
        if (*carry == '0')
        {
            *carry = '0';
            return '1';
        }
        else
        {
            *carry = '0';
            return '0';
        }
    }
    if (a == '2' && b == '2')
    {
        if (*carry == '0')
        {
            *carry = '0';
            return '0';
        }
        else
        {
            *carry = '1';
            return '9';
        }
    }
    if (a == '2' && b == '3')
    {
        if (*carry == '0')
        {
            *carry = '1';
            return '9';
        }
        else
        {
            *carry = '1';
            return '8';
        }
    }
    if (a == '2' && b == '4')
    {
        if (*carry == '0')
        {
            *carry = '1';
            return '8';
        }
        else
        {
            *carry = '1';
            return '7';
        }
    }
    if (a == '2' && b == '5')
    {
        if (*carry == '0')
        {
            *carry = '1';
            return '7';
        }
        else
        {
            *carry = '1';
            return '6';
        }
    }
    if (a == '2' && b == '6')
    {
        if (*carry == '0')
        {
            *carry = '1';
            return '6';
        }
        else
        {
            *carry = '1';
            return '5';
        }
    }
    if (a == '2' && b == '7')
    {
        if (*carry == '0')
        {
            *carry = '1';
            return '5';
        }
        else
        {
            *carry = '1';
            return '4';
        }
    }
    if (a == '2' && b == '8')
    {
        if (*carry == '0')
        {
            *carry = '1';
            return '4';
        }
        else
        {
            *carry = '1';
            return '3';
        }
    }
    if (a == '2' && b == '9')
    {
        if (*carry == '0')
        {
            *carry = '1';
            return '3';
        }
        else
        {
            *carry = '1';
            return '2';
        }
    }
    if (a == '3' && b == '0')
    {
        if (*carry == '0')
        {
            *carry = '0';
            return '3';
        }
        else
        {
            *carry = '0';
            return '2';
        }
    }
    if (a == '3' && b == '1')
    {
        if (*carry == '0')
        {
            *carry = '0';
            return '2';
        }
        else
        {
            *carry = '0';
            return '1';
        }
    }
    if (a == '3' && b == '2')
    {
        if (*carry == '0')
        {
            *carry = '0';
            return '1';
        }
        else
        {
            *carry = '0';
            return '0';
        }
    }
    if (a == '3' && b == '3')
    {
        if (*carry == '0')
        {
            *carry = '0';
            return '0';
        }
        else
        {
            *carry = '1';
            return '9';
        }
    }
    if (a == '3' && b == '4')
    {
        if (*carry == '0')
        {
            *carry = '1';
            return '9';
        }
        else
        {
            *carry = '1';
            return '8';
        }
    }
    if (a == '3' && b == '5')
    {
        if (*carry == '0')
        {
            *carry = '1';
            return '8';
        }
        else
        {
            *carry = '1';
            return '7';
        }
    }
    if (a == '3' && b == '6')
    {
        if (*carry == '0')
        {
            *carry = '1';
            return '7';
        }
        else
        {
            *carry = '1';
            return '6';
        }
    }
    if (a == '3' && b == '7')
    {
        if (*carry == '0')
        {
            *carry = '1';
            return '6';
        }
        else
        {
            *carry = '1';
            return '5';
        }
    }
    if (a == '3' && b == '8')
    {
        if (*carry == '0')
        {
            *carry = '1';
            return '5';
        }
        else
        {
            *carry = '1';
            return '4';
        }
    }
    if (a == '3' && b == '9')
    {
        if (*carry == '0')
        {
            *carry = '1';
            return '4';
        }
        else
        {
            *carry = '1';
            return '3';
        }
    }
    if (a == '4' && b == '0')
    {
        if (*carry == '0')
        {
            *carry = '0';
            return '4';
        }
        else
        {
            *carry = '0';
            return '3';
        }
    }
    if (a == '4' && b == '1')
    {
        if (*carry == '0')
        {
            *carry = '0';
            return '3';
        }
        else
        {
            *carry = '0';
            return '2';
        }
    }
    if (a == '4' && b == '2')
    {
        if (*carry == '0')
        {
            *carry = '0';
            return '2';
        }
        else
        {
            *carry = '0';
            return '1';
        }
    }
    if (a == '4' && b == '3')
    {
        if (*carry == '0')
        {
            *carry = '0';
            return '1';
        }
        else
        {
            *carry = '0';
            return '0';
        }
    }
    if (a == '4' && b == '4')
    {
        if (*carry == '0')
        {
            *carry = '0';
            return '0';
        }
        else
        {
            *carry = '1';
            return '9';
        }
    }
    if (a == '4' && b == '5')
    {
        if (*carry == '0')
        {
            *carry = '1';
            return '9';
        }
        else
        {
            *carry = '1';
            return '8';
        }
    }
    if (a == '4' && b == '6')
    {
        if (*carry == '0')
        {
            *carry = '1';
            return '8';
        }
        else
        {
            *carry = '1';
            return '7';
        }
    }
    if (a == '4' && b == '7')
    {
        if (*carry == '0')
        {
            *carry = '1';
            return '7';
        }
        else
        {
            *carry = '1';
            return '6';
        }
    }
    if (a == '4' && b == '8')
    {
        if (*carry == '0')
        {
            *carry = '1';
            return '6';
        }
        else
        {
            *carry = '1';
            return '5';
        }
    }
    if (a == '4' && b == '9')
    {
        if (*carry == '0')
        {
            *carry = '1';
            return '5';
        }
        else
        {
            *carry = '1';
            return '4';
        }
    }
    if (a == '5' && b == '0')
    {
        if (*carry == '0')
        {
            *carry = '0';
            return '5';
        }
        else
        {
            *carry = '0';
            return '4';
        }
    }
    if (a == '5' && b == '1')
    {
        if (*carry == '0')
        {
            *carry = '0';
            return '4';
        }
        else
        {
            *carry = '0';
            return '3';
        }
    }
    if (a == '5' && b == '2')
    {
        if (*carry == '0')
        {
            *carry = '0';
            return '3';
        }
        else
        {
            *carry = '0';
            return '2';
        }
    }
    if (a == '5' && b == '3')
    {
        if (*carry == '0')
        {
            *carry = '0';
            return '2';
        }
        else
        {
            *carry = '0';
            return '1';
        }
    }
    if (a == '5' && b == '4')
    {
        if (*carry == '0')
        {
            *carry = '0';
            return '1';
        }
        else
        {
            *carry = '0';
            return '0';
        }
    }
    if (a == '5' && b == '5')
    {
        if (*carry == '0')
        {
            *carry = '0';
            return '0';
        }
        else
        {
            *carry = '1';
            return '9';
        }
    }
    if (a == '5' && b == '6')
    {
        if (*carry == '0')
        {
            *carry = '1';
            return '9';
        }
        else
        {
            *carry = '1';
            return '8';
        }
    }
    if (a == '5' && b == '7')
    {
        if (*carry == '0')
        {
            *carry = '1';
            return '8';
        }
        else
        {
            *carry = '1';
            return '7';
        }
    }
    if (a == '5' && b == '8')
    {
        if (*carry == '0')
        {
            *carry = '1';
            return '7';
        }
        else
        {
            *carry = '1';
            return '6';
        }
    }
    if (a == '5' && b == '9')
    {
        if (*carry == '0')
        {
            *carry = '1';
            return '6';
        }
        else
        {
            *carry = '1';
            return '5';
        }
    }
    if (a == '6' && b == '0')
    {
        if (*carry == '0')
        {
            *carry = '0';
            return '6';
        }
        else
        {
            *carry = '0';
            return '5';
        }
    }
    if (a == '6' && b == '1')
    {
        if (*carry == '0')
        {
            *carry = '0';
            return '5';
        }
        else
        {
            *carry = '0';
            return '4';
        }
    }
    if (a == '6' && b == '2')
    {
        if (*carry == '0')
        {
            *carry = '0';
            return '4';
        }
        else
        {
            *carry = '0';
            return '3';
        }
    }
    if (a == '6' && b == '3')
    {
        if (*carry == '0')
        {
            *carry = '0';
            return '3';
        }
        else
        {
            *carry = '0';
            return '2';
        }
    }
    if (a == '6' && b == '4')
    {
        if (*carry == '0')
        {
            *carry = '0';
            return '2';
        }
        else
        {
            *carry = '0';
            return '1';
        }
    }
    if (a == '6' && b == '5')
    {
        if (*carry == '0')
        {
            *carry = '0';
            return '1';
        }
        else
        {
            *carry = '0';
            return '0';
        }
    }
    if (a == '6' && b == '6')
    {
        if (*carry == '0')
        {
            *carry = '0';
            return '0';
        }
        else
        {
            *carry = '1';
            return '9';
        }
    }
    if (a == '6' && b == '7')
    {
        if (*carry == '0')
        {
            *carry = '1';
            return '9';
        }
        else
        {
            *carry = '1';
            return '8';
        }
    }
    if (a == '6' && b == '8')
    {
        if (*carry == '0')
        {
            *carry = '1';
            return '8';
        }
        else
        {
            *carry = '1';
            return '7';
        }
    }
    if (a == '6' && b == '9')
    {
        if (*carry == '0')
        {
            *carry = '1';
            return '7';
        }
        else
        {
            *carry = '1';
            return '6';
        }
    }
    if (a == '7' && b == '0')
    {
        if (*carry == '0')
        {
            *carry = '0';
            return '7';
        }
        else
        {
            *carry = '0';
            return '6';
        }
    }
    if (a == '7' && b == '1')
    {
        if (*carry == '0')
        {
            *carry = '0';
            return '6';
        }
        else
        {
            *carry = '0';
            return '5';
        }
    }
    if (a == '7' && b == '2')
    {
        if (*carry == '0')
        {
            *carry = '0';
            return '5';
        }
        else
        {
            *carry = '0';
            return '4';
        }
    }
    if (a == '7' && b == '3')
    {
        if (*carry == '0')
        {
            *carry = '0';
            return '4';
        }
        else
        {
            *carry = '0';
            return '3';
        }
    }
    if (a == '7' && b == '4')
    {
        if (*carry == '0')
        {
            *carry = '0';
            return '3';
        }
        else
        {
            *carry = '0';
            return '2';
        }
    }
    if (a == '7' && b == '5')
    {
        if (*carry == '0')
        {
            *carry = '0';
            return '2';
        }
        else
        {
            *carry = '0';
            return '1';
        }
    }
    if (a == '7' && b == '6')
    {
        if (*carry == '0')
        {
            *carry = '0';
            return '1';
        }
        else
        {
            *carry = '0';
            return '0';
        }
    }
    if (a == '7' && b == '7')
    {
        if (*carry == '0')
        {
            *carry = '0';
            return '0';
        }
        else
        {
            *carry = '1';
            return '9';
        }
    }
    if (a == '7' && b == '8')
    {
        if (*carry == '0')
        {
            *carry = '1';
            return '9';
        }
        else
        {
            *carry = '1';
            return '8';
        }
    }
    if (a == '7' && b == '9')
    {
        if (*carry == '0')
        {
            *carry = '1';
            return '8';
        }
        else
        {
            *carry = '1';
            return '7';
        }
    }
    if (a == '8' && b == '0')
    {
        if (*carry == '0')
        {
            *carry = '0';
            return '8';
        }
        else
        {
            *carry = '0';
            return '7';
        }
    }
    if (a == '8' && b == '1')
    {
        if (*carry == '0')
        {
            *carry = '0';
            return '7';
        }
        else
        {
            *carry = '0';
            return '6';
        }
    }
    if (a == '8' && b == '2')
    {
        if (*carry == '0')
        {
            *carry = '0';
            return '6';
        }
        else
        {
            *carry = '0';
            return '5';
        }
    }
    if (a == '8' && b == '3')
    {
        if (*carry == '0')
        {
            *carry = '0';
            return '5';
        }
        else
        {
            *carry = '0';
            return '4';
        }
    }
    if (a == '8' && b == '4')
    {
        if (*carry == '0')
        {
            *carry = '0';
            return '4';
        }
        else
        {
            *carry = '0';
            return '3';
        }
    }
    if (a == '8' && b == '5')
    {
        if (*carry == '0')
        {
            *carry = '0';
            return '3';
        }
        else
        {
            *carry = '0';
            return '2';
        }
    }
    if (a == '8' && b == '6')
    {
        if (*carry == '0')
        {
            *carry = '0';
            return '2';
        }
        else
        {
            *carry = '0';
            return '1';
        }
    }
    if (a == '8' && b == '7')
    {
        if (*carry == '0')
        {
            *carry = '0';
            return '1';
        }
        else
        {
            *carry = '0';
            return '0';
        }
    }
    if (a == '8' && b == '8')
    {
        if (*carry == '0')
        {
            *carry = '0';
            return '0';
        }
        else
        {
            *carry = '1';
            return '9';
        }
    }
    if (a == '8' && b == '9')
    {
        if (*carry == '0')
        {
            *carry = '1';
            return '9';
        }
        else
        {
            *carry = '1';
            return '8';
        }
    }
    if (a == '9' && b == '0')
    {
        if (*carry == '0')
        {
            *carry = '0';
            return '9';
        }
        else
        {
            *carry = '0';
            return '8';
        }
    }
    if (a == '9' && b == '1')
    {
        if (*carry == '0')
        {
            *carry = '0';
            return '8';
        }
        else
        {
            *carry = '0';
            return '7';
        }
    }
    if (a == '9' && b == '2')
    {
        if (*carry == '0')
        {
            *carry = '0';
            return '7';
        }
        else
        {
            *carry = '0';
            return '6';
        }
    }
    if (a == '9' && b == '3')
    {
        if (*carry == '0')
        {
            *carry = '0';
            return '6';
        }
        else
        {
            *carry = '0';
            return '5';
        }
    }
    if (a == '9' && b == '4')
    {
        if (*carry == '0')
        {
            *carry = '0';
            return '5';
        }
        else
        {
            *carry = '0';
            return '4';
        }
    }
    if (a == '9' && b == '5')
    {
        if (*carry == '0')
        {
            *carry = '0';
            return '4';
        }
        else
        {
            *carry = '0';
            return '3';
        }
    }
    if (a == '9' && b == '6')
    {
        if (*carry == '0')
        {
            *carry = '0';
            return '3';
        }
        else
        {
            *carry = '0';
            return '2';
        }
    }
    if (a == '9' && b == '7')
    {
        if (*carry == '0')
        {
            *carry = '0';
            return '2';
        }
        else
        {
            *carry = '0';
            return '1';
        }
    }
    if (a == '9' && b == '8')
    {
        if (*carry == '0')
        {
            *carry = '0';
            return '1';
        }
        else
        {
            *carry = '0';
            return '0';
        }
    }
    if (a == '9' && b == '9')
    {
        if (*carry == '0')
        {
            *carry = '0';
            return '0';
        }
        else
        {
            *carry = '1';
            return '9';
        }
    }
    return '?';
}

// compare 2 charcters without using >,< sign
char com(char ch1, char ch2)
{
    if ((ch1 == '0' && ch2 == '1') || (ch1 == '0' && ch2 == '2') || (ch1 == '0' && ch2 == '3') || (ch1 == '0' && ch2 == '4') || (ch1 == '0' && ch2 == '5') || (ch1 == '0' && ch2 == '6') || (ch1 == '0' && ch2 == '7') || (ch1 == '0' && ch2 == '8') || (ch1 == '0' && ch2 == '9') || (ch1 == '1' && ch2 == '2') || (ch1 == '1' && ch2 == '3') || (ch1 == '1' && ch2 == '4') || (ch1 == '1' && ch2 == '5') || (ch1 == '1' && ch2 == '6') || (ch1 == '1' && ch2 == '7') || (ch1 == '1' && ch2 == '8') || (ch1 == '1' && ch2 == '9') || (ch1 == '2' && ch2 == '3') || (ch1 == '2' && ch2 == '4') || (ch1 == '2' && ch2 == '5') || (ch1 == '2' && ch2 == '6') || (ch1 == '2' && ch2 == '7') || (ch1 == '2' && ch2 == '8') || (ch1 == '2' && ch2 == '9') || (ch1 == '3' && ch2 == '4') || (ch1 == '3' && ch2 == '5') || (ch1 == '3' && ch2 == '6') || (ch1 == '3' && ch2 == '7') || (ch1 == '3' && ch2 == '8') || (ch1 == '3' && ch2 == '9') || (ch1 == '4' && ch2 == '5') || (ch1 == '4' && ch2 == '6') || (ch1 == '4' && ch2 == '7') || (ch1 == '4' && ch2 == '8') || (ch1 == '4' && ch2 == '9') || (ch1 == '5' && ch2 == '6') || (ch1 == '5' && ch2 == '7') || (ch1 == '5' && ch2 == '8') || (ch1 == '5' && ch2 == '9') || (ch1 == '6' && ch2 == '7') || (ch1 == '6' && ch2 == '8') || (ch1 == '6' && ch2 == '9') || (ch1 == '7' && ch2 == '8') || (ch1 == '7' && ch2 == '9') || (ch1 == '8' && ch2 == '9'))
    {
        return '<';
    }
    if ((ch1 == '1' && ch2 == '0') || (ch1 == '2' && ch2 == '0') || (ch1 == '3' && ch2 == '0') || (ch1 == '4' && ch2 == '0') || (ch1 == '5' && ch2 == '0') || (ch1 == '6' && ch2 == '0') || (ch1 == '7' && ch2 == '0') || (ch1 == '8' && ch2 == '0') || (ch1 == '9' && ch2 == '0') || (ch1 == '2' && ch2 == '1') || (ch1 == '3' && ch2 == '1') || (ch1 == '4' && ch2 == '1') || (ch1 == '5' && ch2 == '1') || (ch1 == '6' && ch2 == '1') || (ch1 == '7' && ch2 == '1') || (ch1 == '8' && ch2 == '1') || (ch1 == '9' && ch2 == '1') || (ch1 == '3' && ch2 == '2') || (ch1 == '4' && ch2 == '2') || (ch1 == '5' && ch2 == '2') || (ch1 == '6' && ch2 == '2') || (ch1 == '7' && ch2 == '2') || (ch1 == '8' && ch2 == '2') || (ch1 == '9' && ch2 == '2') || (ch1 == '4' && ch2 == '3') || (ch1 == '5' && ch2 == '3') || (ch1 == '6' && ch2 == '3') || (ch1 == '7' && ch2 == '3') || (ch1 == '8' && ch2 == '3') || (ch1 == '9' && ch2 == '3') || (ch1 == '5' && ch2 == '4') || (ch1 == '6' && ch2 == '4') || (ch1 == '7' && ch2 == '4') || (ch1 == '8' && ch2 == '4') || (ch1 == '9' && ch2 == '4') || (ch1 == '6' && ch2 == '5') || (ch1 == '7' && ch2 == '5') || (ch1 == '8' && ch2 == '5') || (ch1 == '9' && ch2 == '5') || (ch1 == '7' && ch2 == '6') || (ch1 == '8' && ch2 == '6') || (ch1 == '9' && ch2 == '6') || (ch1 == '8' && ch2 == '7') || (ch1 == '9' && ch2 == '7') || (ch1 == '9' && ch2 == '8'))
    {
        return '>';
    }
    return '=';
}

// function to reverse a list
list reverse(list a)
{
    node *temp;
    list ans;
    temp = a.head;
    while (temp != NULL)
    {
        ans.additem(temp->data);
        temp = temp->next;
    }
    return ans;
}

// comparing 2 lists
char compare(list a, list b)
{
    // comapring integral part
    char ans = '=';
    a = reverse(a);
    b = reverse(b);
    node *temp1 = a.head, *temp2 = b.head;
    while (temp1 && temp2)
    {
        if (com(temp1->data, temp2->data) == '>')
        {
            ans = '>';
        }
        else
        {
            if (com(temp1->data, temp2->data) == '<')
            {
                ans = '<';
            }
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    if (temp1)
    {
        return '>';
    }
    if (temp2)
    {
        return '<';
    }
    return ans;
}

// funtion for adding numbers
list addTwoLists(list a, list b)
{
    list res;
    a = reverse(a);
    b = reverse(b);
    node *first = a.head, *second = b.head;
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
        res.additem(ch);
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
        res.additem('1');
    }
    return res;
}

// funtion for subtracting numbers
list subTwoLists(list a, list b)
{
    list res;
    a = reverse(a);
    b = reverse(b);
    node *first = a.head, *second = b.head;
    char ch, carry = '0';
    while (first != NULL || second != NULL)
    {
        if (first == NULL)
        {
            ch = sub('0', second->data, &carry);
        }
        if (second == NULL)
        {
            ch = sub(first->data, '0', &carry);
        }
        if (first && second)
        {
            ch = sub(first->data, second->data, &carry);
        }
        res.additem(ch);
        if (first)
        {
            first = first->next;
        }
        if (second)
        {
            second = second->next;
        }
    }
    node *temp = res.head;
    while (temp != NULL)
    {
        if (temp->data == '0')
        {
            temp = temp->next;
            res.deltop();
        }
        else
        {
            break;
        }
    }
    return res;
}

// function for dividing numbers
void div(list a, list b, list a_dec, list b_dec, list k)
{
    char ch, c = '0';
    list ans, num, den, one;
    one.additem('1');
    node *temp1 = a_dec.head, *temp2 = b_dec.head;
    // removing decimals
    while (temp1 != NULL)
    {
        b.addend('0');
        temp1 = temp1->next;
    }
    while (temp2 != NULL)
    {
        a.addend('0');
        temp2 = temp2->next;
    }
    temp1 = a.head;
    temp2 = b.head;
    while (temp1 != NULL && temp1->data == '0')
    {
        temp1 = temp1->next;
    }
    while (temp2 != NULL && temp2->data == '0')
    {
        temp2 = temp2->next;
    }
    // checking denominator=0 case
    if (temp2 == NULL)
    {
        cout << "Not Defined\n";
        return;
    }
    if (temp1 == NULL)
    {
        cout << "0.";
        while (k.head != NULL)
        {
            cout << "0";
            k = subTwoLists(k, one);
        }
        cout << "\n";
        return;
    }
    while (temp1 != NULL && temp2 != NULL)
    {
        num.addend(temp1->data);
        den.addend(temp2->data);
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    if (temp1 == NULL && temp2 == NULL)
    {
        list temp;
        ch = '0';
        while (compare(num, temp) != '<' && compare(num, addTwoLists(temp, den)) != '<')
        {
            ch = add(ch, '1', &c);
            temp = addTwoLists(temp, den);
        }
        ans.addend(ch);
        num = subTwoLists(num, temp);
        ans.addend('.');
        num.addend('0');
    }
    if (temp2 != NULL)
    {
        ans.addend('0');
        ans.addend('.');
        num.addend('0');
        den.addend(temp2->data);
        temp2 = temp2->next;
        while (temp2 != NULL && k.head != NULL)
        {
            num.addend('0');
            ans.addend('0');
            k = subTwoLists(k, one);
            den.addend(temp2->data);
            temp2 = temp2->next;
        }
    }
    if (temp1 != NULL)
    {
        while (1)
        {
            list temp;
            ch = '0';
            while (compare(num, temp) != '<' && compare(num, addTwoLists(temp, den)) != '<')
            {
                ch = add(ch, '1', &c);
                temp = addTwoLists(temp, den);
            }
            ans.addend(ch);
            num = subTwoLists(num, temp);
            if (temp1 == NULL)
            {
                break;
            }
            num.addend(temp1->data);
            temp1 = temp1->next;
        }
        ans.addend('.');
        num.addend('0');
    }
    while (k.head != NULL)
    {
        list temp;
        ch = '0';
        while (compare(num, temp) != '<' && compare(num, addTwoLists(temp, den)) != '<')
        {
            ch = add(ch, '1', &c);
            temp = addTwoLists(temp, den);
        }
        ans.addend(ch);
        num = subTwoLists(num, temp);
        num.addend('0');
        k = subTwoLists(k, one);
    }
    ans.display();
}

int main()
{
    fstream file;
    char c, sign;
    list a, b, a_int, b_int, a_dec, b_dec, a_neg, b_neg, temp1, temp2, ans, k;
    file.open("input.txt");
    // we are adding decimals in backward direction
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
        temp1.addend(c);
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
            temp1.addend(c);
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
        temp2.addend(c);
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
            temp2.addend(c);
        }
    }
    while (file.get(c))
    {
        if (c == '\n')
        {
            break;
        }
        if (k.head == NULL)
        {
            if (c == '0')
            {
                continue;
            }
        }
        k.addend(c);
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
    a.display();
    b.display();
    cout << sign;
    div(temp1, temp2, a_dec, b_dec, k);
    file.close();
    return 0;
}
