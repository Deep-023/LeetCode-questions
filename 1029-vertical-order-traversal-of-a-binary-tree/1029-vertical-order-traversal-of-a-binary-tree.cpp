/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
typedef pair<TreeNode*,pair<int,int>> pp; 
class Solution {
public:

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>>mp;
        queue<pp> q;
        q.push({root,{0,0}});
        vector<vector<int>> ans;

        while(!q.empty()){
            pp top = q.front();
            q.pop();
            mp[top.second.second][top.second.first].insert(top.first->val);
            if(top.first->left)
                q.push({top.first->left,{top.second.first+1,top.second.second-1}});
            if(top.first->right)
                q.push({top.first->right,{top.second.first+1,top.second.second+1}}); 
        }

        for(auto &i : mp){
            vector<int> temp;
            for(auto &j:i.second)
                for(auto &k:j.second)
                    temp.push_back(k);
            ans.push_back(temp);
        }   


        return ans;
    }
};