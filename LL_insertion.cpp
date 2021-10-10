#include <iostream>
#include <sstream>
#include <stdlib.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

//------------------------- functions declaration -----------------

void insert_begin();
void display();
void input_list();
void insert_last();
void insert_in_middle();
void insert_at_position();
//---------------------------- main function ----------------
int main()
{
    cout << "Type 1 to input element in the beginning " << endl;
    cout << "Type 2 to input element at last " << endl;
    cout << "Type 3 to input element in the middle " << endl;
    cout << "Type 4 to input element at a particular position " << endl;
    int input;
    cin >> input;
    input_list();

    switch (input)
    {
    case 1:
        insert_begin();
        break;
    case 2:
        insert_last();
        break;
    case 3:
        insert_in_middle();
        break;
    case 4:
        insert_at_position();
        break;
    }

    return 0;
}

//---------- --------------------- insert begin --------

void insert_begin()
{

    struct node *newp;
    newp = (struct node *)malloc(sizeof(struct node));
    cout << "\nEnter value to insert in the beginning \n";
    cin >> newp->data;
    newp->next = head;
    head = newp;
    display();
}

//------------------------------------- display -------------------------

void display()
{
    cout << "Linked list is: " << endl;
    struct node *ptr;
    ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}

//----------------------------------- input_list -------------------------

void input_list()
{
    struct node *p;
    struct node *q;
    char ch;
    do
    //  while (ch != '0')
    {
        if (head == NULL)
        {
            p = (struct node *)malloc(sizeof(struct node));
            //   p->next= NULL;

            head = p;
        }
        else
        {
            q = (struct node *)malloc(sizeof(struct node));
            p->next = q;
            p = q;
            //  cout<<"enter value"<<endl;
            //  cin>>p->data;
        }
        cout << "enter value" << endl;
        cin >> p->data;
        p->next = NULL;
        cout << "press 0 to stop" << endl;
        cin >> ch;

    } while (ch != '0');
    display();
}

//------------------------------- insert at last ---------------------------

void insert_last()
{
    struct node *p = head;
    //struct node*new_node;
    // p=head;
    struct node *new_node = new struct node;
    //dynamic memory allocation-- to get a memory block which new_node can point

    cout << "Enter value to insert at the end \n";
    cin >> new_node->data;
    new_node->next = NULL;

    while (p->next != NULL)
    { // loop to get p pointing at last element
        p = p->next;
    }
    p->next = new_node;
    display();
}

//------------------------------- insert in the middle ---------------------------

void insert_in_middle()
{
    int info;
    struct node *p = head;
    struct node *new_node = new struct node;
    cout << "Enter value to be inserted after which data \n";
    cin >> info;
    cout << "Enter value to insert after " << info << endl;
    cin >> new_node->data;
    new_node->next = NULL;

    while (p->data != info)
        p = p->next;

    new_node->next = p->next;
    p->next = new_node;

    display();
}

//------------------------------- insert at a position ---------------------------

void insert_at_position()
{

    int count = 1, pos = 0;
    printf("\ninput pos \n");
    scanf("%d", &pos);
    if(pos==0)
    printf("Positions start from 0 \n");
    if(pos==1)
    insert_begin();

    node *temp=head;
    node *newnodee = (node *)malloc(sizeof(node));
    printf("input value to be inserted at %d position \n", pos);
    scanf("%d", &newnodee->data);
    newnodee->next = NULL;
    
    while (temp->next != NULL)
    {
        if (count == (pos - 1))
        {printf("If is called\n");
            newnodee->next = temp->next;
            temp->next = newnodee;
            printf("value is : %d ", newnodee->data);
            break;
        }
        else
        {
            temp = temp->next;
            count++;
        }
    }
    display();

}