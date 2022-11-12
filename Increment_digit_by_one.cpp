#include <iostream>

using namespace std;

struct list{
    int val;
    struct list* next;
};

// ------------------------------------------- Function to add a node at head ---------------------------------------------------------------------

void insertathead(list** h,int data){
    list* newnode = new list;
    newnode->val = data;
    newnode->next= *h;
   *h= newnode;
}

//------------------------------------------- Function to print list ------------------------------------------------------------------------------

void printlist(list** h){
    list* p=*h;
    while(p!=NULL)
   { cout<<p->val<<" ";
    p=p->next;
   }
   cout<<endl;
}

// ------------------------------------------Function to increment number by 1 ----------------------------------------------------------------------

void addone(list** h)
{
    list* fast= *h;
    list* slow=  NULL;  
    int flag=0;
    
  // do fast=fast->next till non 9 number is found and when found set slow=fast and find another non 9 number by fast=fast->next
  
          while(fast!=NULL){
              
           if(fast->val == 9)  {fast=fast->next;             // finding non 9 number
           }
           else{
               flag=1;                           // number is not of kind 99999 so no need to add a node and set other values to 0
               slow=fast;
               fast=fast->next; 
               }
                     }
           if(slow!=NULL)          
          slow->val=(slow->val)+1;                     // incrementing number not of type 9999
       
     if(flag==0){                         // flag is used to check if number contains only 9 as a digit then set flag to 1 else 0
         
         insertathead(h,1);
        
         slow=*h;
        while(slow->next!=NULL)   // head is pointing to node with 1 value that's 
                                  //why loop is exetuted 4+1 times hence we are using slow->next instead of slow!=NULL
         {//cout<<"WE "<<endl;
         slow=slow->next;
         slow->val=0;
         }

    }
}


int main()
{
  list* head=NULL;
 insertathead(&head,9);
 insertathead(&head,9);
 insertathead(&head,9);
 insertathead(&head,9);
 insertathead(&head,9);
  printlist(&head);
 addone(&head);

   printlist(&head);
  
    return 0;
}

