#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

bool isPoss(vector<int>& stalls, int dist, int c){
    c--;
    int j=0;
    for(int i=1;i<stalls.size();i++){
        if(c==0){
            return true;
        }
        if(c>0){
            if((stalls[i]-stalls[j])>=dist){
                j=i;
                c--;
            }

        }

    }
    return (c==0);
}



void solve(){
    int n,c;
    cin>>n>>c;
    vector<int> stalls(n);

    int max = INT_MIN, min = INT_MAX;
    for(int i=0;i<n;i++){
        cin>>stalls[i];
        if(stalls[i]<min){
            min=stalls[i];
        }
        if(stalls[i]>max){
            max=stalls[i];
        }
    }
    sort(stalls.begin(),stalls.end());

    int s = 0, e= max-min;
    int ans=0;
    while(s<=e){
        int mid = (s+e)/2;
        bool isp = isPoss(stalls,mid,c);

        if(isp){
            ans = mid;
            s = mid+1;
        }
        else{
            e=mid-1;
        }

    }

    cout<<ans<<endl;





}

int main()
{
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}