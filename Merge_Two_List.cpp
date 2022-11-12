#include<bits/stdc++.h>
using namespace std;

class listnode{
public:
    int val;
    listnode* next;

void insertathead(listnode** h,int data){
    listnode* newnode = new listnode;
    newnode->val = data;
    newnode->next= *h;
   *h= newnode;
}
void printlist(listnode** h){
    listnode* p=*h;
    cout<<"List is: "<<endl;
    while(p!=NULL)
   { cout<<p->val<<" ";
    p=p->next;
   }
   cout<<endl;
}

    listnode* mergefunc(listnode* l1, listnode* l2){

//----------- Recursion ------------------------------------

    //     if(l1==NULL) return l2;
    //     if(l2==NULL ) return l1;

    // if(l1->val < l2->val) {
    //    l1->next= mergefunc(l1->next,l2);
    //    return l1;
    // }
    // else {
    //    l2->next= mergefunc(l1,l2->next);
    //    return l2;
    // }

// ----------- Iteration ---------------------------

   listnode* p=l1;

   if(l1->val > l2->val) { 
    p=l2; l2=l2->next;
    }                             // pointing the smallest val by p
                        // and then moving to next part of the list having smallest val
    else l1=l1->next;                   // p mein head of new list will be stored

    listnode* curr=p;             
    while(l1 && l2){
        if(l1->val < l2->val) { 
            curr->next=l1;                 // agr smallest l1 mein h toh 1st smallest 
            l1=l1->next;  }                     // ka next this smallest
            else{
                curr->next=l2;
                l2=l2->next;                   // same for l2
            }
            curr=curr->next;    
                                //            1   ->   2   ->   3
//                                                     ^        ^
//                                                     |        |
              //          ( curr=curr->next )         curr ---- curr (new pos of curr)
//                                   Now [curr->next=l1] will create link b/w 3 and l1
            
    }
    if(!l1) curr->next=l2;  // copying bachi list
    if(!l2) curr->next=l1; //            ,,
    
return p;                   // returning pointer to 1t smallest 
    
}

};



int main(){
listnode obj;
listnode* l1=NULL, *l2=NULL;
obj.insertathead(&l1,9);
obj.insertathead(&l1,3);
 obj.insertathead(&l1,2);
 obj.insertathead(&l2,7);
 obj.insertathead(&l2,6);
 obj.insertathead(&l2,4);
 obj.insertathead(&l2,1);

  obj.printlist(&l1);
   obj.printlist(&l2);
l1=obj.mergefunc(l1,l2);
 obj.printlist(&l1);

    return 0;
}