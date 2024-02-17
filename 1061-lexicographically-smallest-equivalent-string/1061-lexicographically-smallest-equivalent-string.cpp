class Solution {
public:
    
    vector<int>parent;
    
    int findParent(char a){
        int i = a-'a';
        return parent[i] = parent[i] == i ? i : findParent(parent[i]+'a');  
    }
    
    void make_pair(char a, char b){
        
        int u = findParent(a);
        int v = findParent(b);
        if(u!=v){
        if(u<v){
            parent[v]=u;
        }else if (u>v){
            parent[u]=v;
        }
        }
    }
    
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        
        for(int i=0;i<26;i++)
            parent.push_back(i);
        
        for(int i=0;i<s1.size();i++){
            make_pair(s1[i],s2[i]);
        }
        
        for(int i=0;i<baseStr.size();i++){
            int a = findParent(baseStr[i]);
            baseStr[i] = a+'a';
        }
        
        return baseStr;
        
        
    }
};