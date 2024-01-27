#include<bits/stdc++.h>
using namespace std;

int i,j=0;
int k=5;
int a[5];

void push(int n)
{
    if(j<k)
    {
        a[j++]=n;
    }
    else{
        j=0;
        if(i==j) cout<<"queue is full";
        else a[j++]=n;
    }
}

void pop()
{
    if(i<k) a[i++]=-1;
    else{
        i=0;
        if(i==j) cout<<"queue is empty";
        else a[i++]=-1;
    }
}
int main()
{
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    push(6);

    pop();
    pop();
    pop();
    pop();
    pop();
    pop();
}