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

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string arr;
        if(root==NULL) return "null";
        arr += to_string(root->val);
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        while(!q.empty()){
            TreeNode* top = q.front();
            q.pop();
            arr+=",";
            if(top==NULL) arr+="null";
            else{
                arr += to_string(top->val);
                q.push(top->left);
                q.push(top->right);
            }
        }
        return arr;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="null") return NULL;
        stringstream str(data);
        string word; getline(str,word,',');
        TreeNode* root = new TreeNode(stoi(word));
        queue<TreeNode*> q;
        q.push(root);
        while(getline(str,word,',')){
            TreeNode* node = q.front();
            q.pop();
            if(word=="null")
                node->left= NULL;
            else{
                node->left = new TreeNode(stoi(word));
                q.push(node->left);
            }

            getline(str,word,',');
            if(word=="null")
                node->right= NULL;
            else{
                node->right = new TreeNode(stoi(word));
                q.push(node->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));