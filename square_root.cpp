#include<bits/stdc++.h>
using namespace std;

float square_root(int n,int k)
{
    int start=1,end=n;
    float ans=0;
    while(start<end)
    {
        int mid=(start+end)/2;
        if(mid*mid==n)
        {
            //return mid;
           // cout<<mid;
            ans=mid;
            break;
        }
        else if(mid*mid<n) start++;
        else end--;
    }
   // cout<<ans<<endl;
    //for decimal part  time complexity is o(k) where k is very small value so we neglect it 
    float increment=0.1;
    for(int i=0;i<k;i++)
    {   cout<<ans;
        while(ans*ans<=n)
        {
            ans+=increment;
        }
        ans-=increment;
        increment/=10;
    }
    return ans;

}

int main()
{
    //calculate the square root of a number
    cout<<square_root(8,2);

    // time complexity for the whole part is log(n)+O(k) 
    //but O(k) is very small so we ignore that so the overall time complexity is log(n);
} 