#include<bits/stdc++.h>
using namespace std;

int main()
{
    //priority_queue<int, vector<int>, greater<int>> h;
    /* priority_queue<int> h;
    for(int i=0;i<5;i++) 
    {
        int k;
        cin>>k;
        h.push(k);

    }

    for(int i=0;i<5;i++)
    {
        
       cout<<h.top()<<" ";
        h.pop();
    } */

    int a[6]={1,1,2,2,3,3};
    int n=6;
   set<int>s;
  for(int i=0;i<6;i++) s.insert(a[i]);
  
  priority_queue<int>pq;
  for(auto i:s)
  {
     pq.push(i);
     i++;
  }
  
  for(int i=0;i<pq.size();i++)
  {
    pq.top();
    pq.pop();
  }
  int ans=0;
  int k=6/2;
  while(n-- && !pq.empty())
  {
      ans+=pq.top();
      pq.pop();
  }
  return ans/2;


}