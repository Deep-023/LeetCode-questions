class Solution {
public:
    class Trie{
        public:
        int size = 2;
        vector<Trie*> t;
        Trie(): t(2,NULL){
        }
    };
    
    void insert(Trie* root ,int n){
        Trie* trie = root;
        for(int i=31;i>=0;i--){
            int a = (n>>i)&1;
            if(!(trie->t[a])){
                trie->t[a] = new Trie();
            }
            trie = trie->t[a];
        }
    }
    
    int dfs(Trie* root, int x, int limit, int value, int height) {
        if (value > limit) return -1;
        
        if (height == -1) return x^value;
        
        int bit_x = (x >> height) & 1;
        
        if (root->t[1-bit_x] != nullptr) {
            int v = dfs(root->t[1-bit_x], x, limit, (value | ((1-bit_x) << height)), height-1);
            if (v >= 0) return v;
        }
        if (root->t[bit_x] != nullptr) {
            int v = dfs(root->t[bit_x], x, limit, (value | (bit_x << height)), height-1);
            if (v >= 0) return v;
        }
        
        return -1;
    }
    
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        Trie* root = new Trie();
        for(int i=0;i<nums.size();i++){
            insert(root,nums[i]);
        }
        for(int i=0;i<queries.size();i++){
            int a = dfs(root,queries[i][0],queries[i][1],0,31);
            ans.push_back(a);
        }
        return ans;
    }
};