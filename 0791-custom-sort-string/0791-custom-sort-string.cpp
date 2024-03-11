class Solution {
public:
    string customSortString(string order, string s) {
        int arr[26];
        memset(arr,0,sizeof(arr));
        for(int i=0;i<s.size();i++){
            arr[s[i]-'a']++;
        }
        string ans = "";
        for(int i=0;i<order.size();i++){
            while(arr[order[i]-'a'] > 0){
                ans.push_back(order[i]);
                arr[order[i]-'a']--;
            }
        }
        
        for(int i=0;i<26;i++){
            while(arr[i]>0){
                ans.push_back(i+'a');
                arr[i]--;
            }
        }
        
        return ans;
    }
};