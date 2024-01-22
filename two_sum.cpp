#include<bits/stdc++.h>
using namespace std;

vector<int> twosum(vector<int> nums,int target)
{
     unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            if(mp.count(target-nums[i]))
            {
                return {mp[target-nums[i]],i};
            }
            mp[nums[i]]=i;
        }
       return {-1,-1};
}
int main()
{
    vector<int> arr={2,7,11,13};
    int target=9;
    vector<int>ans=twosum( arr, target);
    for(int i=0;i<ans.size();i++)

    {
        cout<<ans[i]<<" ";
        
    }

}