#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a[5]={1,2,2,3,4};

    int s=0;
    int e=4;
    int mid=0;
    while(s<=e)
    {
         mid=s+(e-s)/2;

        if(a[mid]<=mid)
        {
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    cout<<a[mid];


}