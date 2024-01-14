class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size())
            return false;
        
        vector<int> arr(26,0);
        vector<int> arr2(26,0);
        unordered_set<int> set;
        unordered_set<int> set2;
        int a=97;
        
        for(int i=0;i<word1.size();i++){
            arr[word1[i]-a]++;
            set.insert(word1[i]-a);
        }
        
        for(int i=0;i<word2.size();i++){
            arr2[word2[i]-a]++;
            set2.insert(word2[i]-a);
        }
        
        sort(arr.begin(),arr.end());
        sort(arr2.begin(),arr2.end());
        
        return arr==arr2 && set==set2;
        
    }
};