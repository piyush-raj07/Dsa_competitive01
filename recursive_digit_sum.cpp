#include<bits/stdc++.h>
using namespace std;

int help(string n,int sum)
 {
     if(n.size()==1) return sum;
   string temp=n;
     sum=0;
    for(int i=0;i<temp.size();i++)
    {
       sum+=temp[i]-'0';
    }
    
    return  help(to_string(sum),sum);
 }
int main()
{
    string n;
    int k;
    cin>>n>>k;
    string temp=n;
    string result="";
    for(int i=0;i<k;i++)
    {
        result+=temp;
    }
    
    cout<<endl<<help(result,k);
}