#include<bits/stdc++.h>
using namespace std;

int hcf(int n,int m)
{
    if(n==0)return m;
    if(m==0) return n;
    if(n==m) return n;

    if(n>m) return hcf(n-m,m);
    else return hcf(n,m-n);
}
int main()
{
    int n,m;
    cin>>n>>m;
    int hcf_ans=hcf(n,m);
    int lcm=n*m/hcf_ans;
    cout<<"lcm"<<lcm<<" "<<"hcf"<<hcf_ans;
}