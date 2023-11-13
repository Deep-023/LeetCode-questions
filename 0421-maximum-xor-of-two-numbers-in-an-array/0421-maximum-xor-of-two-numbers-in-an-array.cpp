class Solution {
public:
    
    class Trie{
    public:  
        Trie* node[2];
        Trie(){
            this->node[0]=NULL;
            this->node[1]=NULL;
        }
    };
    
    void insert(Trie* root,int num){
        Trie* temp = root;
        for(int i=31;i>=0;i--){
            int n = (num>>i)&1;
            if(temp->node[n]!= NULL){
                temp = temp->node[n];
            }else{
                temp->node[n] = new Trie();
                temp = temp->node[n];
            }
        }
    }
    
    int findMax(Trie* root, int n){
        int ans = 0;
        Trie* temp = root;
        for(int i=31;i>=0;i--){
            int num= (n>>i)&1;
            if(temp->node[!num]!= NULL){
                ans |= 1<<i;
                temp = temp->node[!num];
            }else{
                temp = temp->node[num];
            }
        }
        return ans;
    }
    
    int findMaximumXOR(vector<int>& nums) {
        Trie* newNode = new Trie();
        for(auto &n : nums) insert(newNode,n); //insert all the elements into the Trie
        
        int ans=0; //Stores the maximum XOR possible so far
        for(auto n : nums){
            ans = max(ans, findMax(newNode,n));  //updates the ans as we traverse the array & compute max XORs at each element.
        }
        return ans;
    }
};