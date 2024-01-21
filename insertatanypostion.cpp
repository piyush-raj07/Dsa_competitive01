#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

struct Node *takeinput()
{
    int data;
    cin >> data;
    struct Node *head = NULL;
    struct Node *tail = NULL;

    while (data != -1)
    {
        struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));

        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
        newnode->data = data;
        newnode->next = NULL;
        cin >> data;
    }
    return head;
}

void print(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl; // Add this line to print a newline after the list
}

struct Node  *insert(struct Node  *head, int i, int data) // insert at ith position
{
      struct Node  *temp = head;
  
    if (i < 0) return head;
    
    if (i == 1)
    {
        struct Node  *newnode = (struct Node *)malloc(sizeof(struct Node));
        newnode->data=data;
        newnode->next = head;
         head = newnode;
         temp = head;

        return head;
    }

    else
    {   
         int k=1;
         while(k<i-1 && temp !=NULL)
        {
            temp = temp->next;
            k++;
            // if(temp ==NULL) break;
        }
          struct Node  *newnode = (struct Node *)malloc(sizeof(struct Node));  
              newnode->data=data;
              newnode->next = temp->next;
             temp->next = newnode;
    }
    return head;
}

/* struct Node* rotate(struct Node* head)
{
     
} */

void deleteith(struct Node*head, int i)
{
    struct Node *temp = head;
    if (i <= 0)
        cout << "Inalid index" << endl;
    if (i == 1 && head)
    {
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }

    else
    {
        int k = 1;
        while (k < i - 1 && temp != NULL)
        {
            temp = temp->next;
            k++;
        }
        struct Node *current = temp->next;
        temp->next = temp->next->next;
        current->next = NULL;
        delete current;
    }
}

void sortlinkedlist(struct Node* head)
{
    if(head==NULL)
    {
        return;
    }
    else{

        struct Node* curr=head;
        struct Node* index=NULL;
        while(curr!=NULL)
        {
            index=curr->next;
            while(index!=NULL)
            {
                if(curr->data>index->data)
                {
                    int temp=curr->data;
                    curr->data=index->data;
                    index->data=temp;
                }
                    index=index->next;
            }
            curr=curr->next;
        }
    }
    
}

struct Node* reverse(struct Node* head)
{
    struct Node* prev=NULL;
    struct Node* curr=head;

    while(curr!=NULL)
    {
        struct Node* newnode=curr->next;
        curr->next=prev;
        prev=curr;
        curr=newnode;
    }
    return prev;
}

bool ispalindrome(struct Node* head,struct Node* nhead)
{
    while(head!=NULL && nhead!=NULL)
    {
        if(head->data !=nhead->data) return false;
        head=head->next;
        nhead=nhead->next;
    }
    return true;
}

bool palindrome2(struct Node* head)
{
    struct Node* temp=head;
    struct Node* prev=head;
    int length=0;
    while(temp!=NULL) 
    {
        length++;
        temp=temp->next;
    }
    int k=length/2;
    temp=head;
    while (k--)
    {
        temp=temp->next;

    }
    if(length%2==0)
    {   struct Node* curr=temp;
        while(curr!=NULL)
        {
            if(prev->data!=curr->data) return false;
            
        }
    }
    
   return false;

}

struct Node* removeduplicate(struct Node* head)
{

    struct Node* temp=head;
    while(temp!=NULL)
    {
        if(temp->next!=NULL && temp->data==temp->next->data)
        {
            struct Node* curr=temp;
            while(curr->next!=NULL && curr->data==curr->next->data)
            {
                curr=curr->next;
            }
            temp->next=curr->next;
        }
        else
        {
          temp=temp->next;
            
        }
    }
    return head;

}
void makecircular(struct Node* head)
{
    struct Node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=head;
}

void  splitcircular(struct Node* head)
{
    struct Node* temp=head;
    int length=0;
     if (head != NULL) {
        do {
            temp = temp->next;
            length++;
        } while (temp != head);
    }
    cout<<length<<endl;

    int k=length/2-1;
    temp=head;
    while(k--)
    {
        temp=temp->next;
    }
    struct Node* secondhead=temp->next;
    temp->next=head;
    temp=head;
    cout<<"first half"<<" ";
    while(temp->next!=head)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<temp->data;

    cout<<endl<<"second half"<<" ";

    struct Node* temp2=secondhead;
    while(temp2->next!=head)
    {
        temp2=temp2->next;
    }
    temp2->next=secondhead;
    temp2=secondhead;
      while(temp2->next!=secondhead)
    {
        cout<<temp2->data<<" ";
        temp2=temp2->next;
    }
    cout<<temp2->data;
}

struct Node* mergeLists(struct Node* head, struct Node* head2) {
    struct Node* temp = head;
    struct Node* temp2 = head2;
    struct Node* ans = NULL;
    struct Node* result = ans;
    int k = 1;

    while (temp != NULL && temp2 != NULL) {
        struct Node* var = (struct Node*)malloc(sizeof(struct Node));
        var->data = temp->data;
        var->next = NULL;

        if (ans == NULL) {
            ans = var;
            result = ans;
        } else {
            ans->next = var;
            ans = ans->next;
        }

        struct Node* var2 = (struct Node*)malloc(sizeof(struct Node));
        var2->data = temp2->data;
        var2->next = NULL;
        ans->next = var2;
        ans = ans->next;

        temp = temp->next;
        temp2 = temp2->next;
    }

    return result;
}

struct Node* rotatekplaces(struct Node* head,int k)
{
    struct Node* temp=head;
     struct Node* prev=NULL;
    struct Node* curr=head;

    int c=k-1;
    while(curr!=NULL && k--)
    {
        struct Node* newnode=curr->next;
        curr->next=prev;
        prev=curr;
        curr=newnode;
    }
    temp=prev;

    while(c--)
    {
        //curr=curr->next;
        temp=temp->next;
    }
    temp->next=curr;

    return prev;

}



int main()
{
    struct Node *head = takeinput();
    //struct Node *head2=takeinput();
     
    print(head);
    struct Node* ans=rotatekplaces(head,4);
    print(ans);
   // print(head2);
   // struct Node* ans=mergeLists(head,head2);
    //print(ans);
    //makecircular(head);
    //splitcircular(head);
   // print(head);
    
    
    //struct Node* newhead=reverse(head);
    //bool ans=ispalindrome(head,newhead);
    //if(ans==1) cout<<"true ";
    //else cout<<"false";
    //struct Node* ans=removeduplicate(head);
    //print(ans);
  // struct Node *newhead = insert(head,7,5);
  // print(newhead);
   //struct Node* rothead=rotate(head);
   //print(rothead);
   //deleteith(head,2);
   //sortlinkedlist(head);
  // print(head);


    return 0;
}
