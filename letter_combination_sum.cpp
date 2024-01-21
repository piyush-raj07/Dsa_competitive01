#include<bits/stdc++.h>
using namespace std;

void  help(string digits,int ind, string temp,vector<string>&ans,string mapping[])
{
    if(ind>=digits.length())
    {
       ans.push_back(temp);
       return;
    }

    int number=digits[ind]-'0';
    string value=mapping[number];

    for(int i=0;i<value.length();i++)
    {
        temp.push_back(value[i]);
        help(digits,ind+1,temp,ans,mapping);
        temp.pop_back();
    }
}
int main()
{
    string digtis;
    cin>>digtis;

    vector<string>ans;
    string temp;
    string mapping[10]={"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    help(digtis,0,temp,ans,mapping);

    for(int i=0;i<ans.size();i++) 
    {
        cout<<ans[i]<<" ";
    
    }
}