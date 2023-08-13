class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        int n = indices.size(), add=0;
        int sSize = s.size();
        vector<int> visited(sSize,0);
        unordered_map<int,string> m;
        string ans;
        for(int i=0;i<n;i++){
            bool temp = true;
            int sn = sources[i].size();
            for(int j=0;j<sn;j++){
                if(s[indices[i]+j] != sources[i][j]){
                    cout<<s[i+j]<<" "<<sources[i][j];
                    temp= false;
                    break;
                }
            }
            //cout<<indices[i]+add<<" ";
            if(temp==true){
                for(int j=0;j<sn;j++){
                    visited[indices[i]+j] = 1;
                 }
                m[indices[i]]= targets[i];
                //ans.replace(indices[i]+add,sn,targets[i]);
            }
            //add+= targets[i].size()-sn;
        }
        for(int i=0;i<sSize;i++){
            if(!visited[i])
                ans.push_back(s[i]);
            else if( !m[i].empty())
                ans += m[i];
        }
        return ans;
    }
};