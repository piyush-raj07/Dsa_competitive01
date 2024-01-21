#include<bits/stdc++.h>
using namespace std;

int factorial(int n)
{
    if(n==1 || n==0) return 1;

   return  n*factorial(n-1); 

}
int power(int n,int m)
{
    if(m==0) return 1;
    return n*power(n,m-1);
}
int lcm(int n,int m)
{    
     if(n==0) return m;
     if(m==0)return n;
     int res=max(n,m);
     while(res>0)
     {
        if(res%n==0 && res%m==0) return res;
        res++;
     }
     return res;
}
int main()
{
    int n;
    cin>>n;
    int m;
    cin>>m;
    cout<<lcm(n,m);
  // cout<< factorial(n);
   //cout<<power(n,m);
}