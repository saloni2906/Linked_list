#include <iostream>

using namespace std;

 struct ListNode{
    int data;
    ListNode* next;
};
ListNode* head= NULL;
ListNode*  p=head;


// ---------------- Reverse List -----------------

ListNode* reverselist(ListNode* h){
    ListNode* prev=NULL;
    ListNode* curr=h;
    ListNode* forward=NULL;
    
    while(curr!=NULL){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }
    // curr->next=prev;
    return prev;
   
}
    
// ---------------- Mid ---------------------
    
    int midoflist(ListNode* h){
        int len=0;
        while(h!=NULL){
            len++;
            h=h->next;
        }
       len = (len/2);
        return len;
    }
    
// ------------------- maximumsum -----------------------    

    int maxsum(ListNode*h1, ListNode* h2){
        int maximumsum=0,sum=0;
        while(h1!=NULL && h2!=NULL){
          sum =(h1->data) + (h2->data);
            if(maximumsum<sum) maximumsum=sum;
            h1=h1->next; h2=h2->next;
        }
        return maximumsum;
    }
    
//----------------------------------- Print List ----------------------------------------

void printlist(ListNode* printhead){
   ListNode*temp;
    temp=printhead;
    cout<<"Printing list ";
    while(temp!=NULL){
    cout<<temp->data<<" ";
    temp=temp->next;
    }
}

//------------------------------------ Insert in List ------------------------------------

void insertlist(int val){

    if(head==NULL){
    ListNode* newnode= new ListNode;
    newnode->data= val;
    newnode->next=NULL;
    head=newnode;
    p=head;
    }
    else {
    ListNode* newnode= new ListNode;
    newnode->data= val;
    newnode->next=NULL;
        p->next=newnode;
        p=p->next;
    }
    
}
    
//-------------------- Driver's code -------------------   
    
    int pairsum(ListNode* h) 
       {
        ListNode* prevhead2=NULL;
        int max=0, mid=0,mid2=0;
        mid=midoflist(h);
        mid2=mid;// mid = 2
        ListNode* head2= h;
        
        while(mid2!=0){
            prevhead2=head2;
            head2=head2->next;
            mid2--;
        }
        
        prevhead2->next=NULL;
        
      head2= reverselist(head2);
        max=maxsum(h,head2);
        return max;
        
       }
      
  int main(){
      int midval=0;
   insertlist(2);
   insertlist(6);
   insertlist(7);
   insertlist(3);
   insertlist(9);
   insertlist(5);
   printlist(head);
   cout<<endl;
      
  cout<<"Maximum twin sum is "<<pairsum(head)<<endl;
   return 0;
        }
