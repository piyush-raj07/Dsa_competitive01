#include<bits/stdc++.h>
using namespace std;

int largest(int a[],int n,int i,int max)
{
   if(i==n)return max;
   
   if(max<a[i])
   {
      max=a[i];
     return  largest(a,n,i+1,max);
   }
   else{
       return  largest(a,n,i+1,max);

   }
  // return max;


}

int reverse_no(int n,int rev)
{   
     
    if(n==0) return rev;
    int rem=n%10;
    rev=rev*10+rem;
    n=n/10;
   return reverse_no(n,rev);
}
int smallest(int a[],int n,int i,int max)
{
   if(i==n)return max;
   
   if(max>a[i])
   {
      max=a[i];
     return  smallest(a,n,i+1,max);
   }
   else{
       return  smallest(a,n,i+1,max);

   }
  // return max;


}

void subset_sum(int a[],int n,int i,int sum,vector<int>&ans)
{
    if(i==n)
    {
        //cout<<sum<<" ";
        ans.push_back(sum);
        return;
    }
     
     sum+=a[i];
    // ans.push_back(sum);
     subset_sum(a,n,i+1,sum,ans);
      
      sum-=a[i];
      subset_sum(a,n,i+1,sum,ans);
}
int main()
{
    // int n;
    // cin>>n;
    int a[]={2,3};
    //cout<<largest(a,5,0,a[0]);
    //cout<<endl<<smallest(a,5,0,a[0]);

    //cout<<reverse_no(987,0);
   
   // vector<vector<int>>dp(n,vector<int>(6+1,-1));
    
    vector<int>ans;
    subset_sum(a,2,0,0,ans);
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";


}