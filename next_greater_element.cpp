#include<bits/stdc++.h>
using namespace std;

vector<long long> nextLargerElement(int arr[], int n){
        // Your code here
        int max=0;
        stack<int>s;
        vector<long long>temp;
        temp.push_back(-1);
        
        for(int i=n-2;i>=0;i--)
        {
            if(arr[i]<arr[i+1])
            {
                temp.push_back(arr[i+1]);
                s.push(arr[i+1]);
            }
            else if(!s.empty()&& arr[i]<s.top())
            {   
                 temp.push_back(s.top());
                
            }
            else
            {  
                if( !s.empty() && arr[i]>s.top() ) s.push(arr[i]);
                temp.push_back(-1);
            }
        }
        
        reverse(temp.begin(),temp.end());
        return temp;

    }
int main()
{
  int arr[]={7,8,1,4};

  vector<long long>ans=nextLargerElement(arr,4);
  for(int i=0;i<ans.size();i++)
  {
      cout<<ans[i]<<" ";
  }
}