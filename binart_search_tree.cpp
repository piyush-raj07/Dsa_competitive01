#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node*left,*right;
};


struct node* newnode(int key)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=key;
    temp->left=temp->right=NULL;
    return temp;
}
struct node* insert(struct node* root,int key)
{
    if(root==NULL) return newnode(key);

    if(key<root->data)  root->left= insert(root->left,key);
    else   root->right=insert(root->right,key);
    
    return root;
    
}

void inorder(struct node* root)
{   
    struct node* temp=root;
    if(temp==NULL) return;
   
    inorder(temp->left);
    cout<<temp->data<<" ";
    inorder(temp->right);
}

struct node* inordersuccessor(struct node* root)
{
     struct node* temp=root;
     while(temp && temp->left!=NULL)
     {
        temp=temp->left;
     }
     return temp;
}
struct node* deletenode(struct node* root,int key)
{
    if(root==NULL) return root;

    if(key<root->data) root->left=deletenode(root->left,key);
    else if(key>root->data) root->right=deletenode(root->right,key);
    else{
         //if the root with only one child
         if(root->left==NULL)
         {
            struct node* temp=root->right;
            free(root);
            return temp;
         }
          else if(root->right==NULL)
         {
            struct node* temp=root->left;
            free(root);
            return temp;
         }

         struct node* temp=inordersuccessor(root->right);
         root->data=temp->data;

         root->right=deletenode(root->right,temp->data);

    }
    return root;
}

int main()
{
    struct node* root=NULL;

    int n=0;;
  while(n!=-1)
  {
    cin>>n;
    if(n!=-1) root= insert(root,n);
  }
  

  cout << "Inorder traversal: ";
  inorder(root);
 
  cout << "\nAfter deleting 10\n";
  root = deletenode(root, 10);
  cout << "Inorder traversal: ";
  inorder(root); 
}