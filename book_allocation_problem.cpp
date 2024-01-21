#include<bits/stdc++.h>
using namespace std;


bool isPossible (int arr[], int books, int students, int mid)
    {
        int studentCount = 1;
        int pageSum = 0;
        for (int i=0; i<books; i++)
        {
            if(pageSum + arr[i] <= mid)
            {
                pageSum += arr[i];
            }
            else
            {
                studentCount++;
                
                if(studentCount > students || arr[i] > mid)
                {
                    return false;
                }
                 
                 pageSum = arr[i];
            }
        }
           return true;
        
    }
    int main() 
    {
        int A[]={12,34,67,90};
        int M=2;
        int N=4;
        if(M>N)
        {
            return -1;
        }
        int start = 0;
        int end = accumulate (A, A+N, 0);
        int ans =-1;
        while (start<=end)
        {
            int mid = start + (end-start)/2;
            cout<<mid<<" "<<endl;
            
            if(isPossible(A, N, M, mid))
            {
                ans = mid;
                cout<<ans<<" ";
                end = mid-1;
            }
            else
            {
                start = mid + 1;
            }
        }
          
          cout<<endl<< ans;
    }




