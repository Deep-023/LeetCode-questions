class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string temp = "";
        int i=0,n=strs.size();
        while(true){
            if(i>=strs[0].size())
                return temp;
            char a = strs[0][i];
            for(int j=1;j<n;j++){
                if(i>=strs[j].size() || strs[j][i] != a)
                    return temp;
            }
            i++;
            temp.push_back(a);
        }
        
        return temp;
    }
};