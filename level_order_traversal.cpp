#include<bits/stdc++.h>
using namespace std;

int levelorder_traversal(Node *root)
{
     queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int levelsize=q.size();
            vector<int>temp;
            for(int i=0;i<levelsize;i++)
            {
                TreeNode* front=q.front();
                q.pop();
                temp.push_back(front->val);

                if(front->left != NULL)
                {
                    q.push(front->left);
                }
                if(front->right != NULL)
                {
                    q.push(front->right);
                }
            }
            ans.push_back(temp);
        }
}

int main()
{
    
}