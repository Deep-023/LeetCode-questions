/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    
    void preOrder(TreeNode* root, string& ans){
        if(root==NULL)
            return;
        
        ans += to_string(root->val)+ " ";
        preOrder(root->left,ans);
        preOrder(root->right,ans);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans;
        preOrder(root,ans);
        return ans;
    }
    
    TreeNode* makeTree(vector<int>& preor, vector<int>& inor, int& idx, int left, int right, int n){  
        if(idx >= n)
            return NULL;
        
        int pos = find(inor.begin(),inor.end(),preor[idx]) - inor.begin();
        
        if(pos<left || pos>right)
            return NULL;
        
        TreeNode* root = new TreeNode(preor[idx++]);
        root->left= makeTree(preor, inor, idx, left, pos-1,n);
        root->right= makeTree(preor, inor, idx, pos+1, right,n);
        
        return root;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty())
            return NULL;
        
        stringstream s(data); 
        vector<int> preor;
        string word;
        
        while(s>>word){
                preor.push_back(stoi(word));
        }
        
        vector<int> inor = preor;
        sort(inor.begin(),inor.end());
        int i =0;
        return makeTree(preor,inor,i,0,preor.size()-1, preor.size());
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;