#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* next;

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

void push(struct Node* &head,int newdata)
{    
    if(head==NULL) return ;
     struct Node* temp=(struct Node*)malloc(sizeof(struct Node));

     temp->data=newdata;
     temp->next=head;
     head=temp;

}
void pop(struct Node* &head)
{
    struct Node* temp=head;
    head=head->next;
    temp->next=NULL;
    delete(temp);
}

int main()
{
    struct Node* head=takeinput();
    push(head,5);
    print(head);
    pop(head);
    print(head);


}
