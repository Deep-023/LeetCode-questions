class Solution {
public:
    vector<int> findDuplicates(vector<int>& arr) {
        vector<int> ans;
        unordered_map<int,int> map;
        for(int i=0;i<arr.size();i++){
            if(map[arr[i]])
            ans.push_back(arr[i]);
            else
            map[arr[i]] = 1;
        }
        return ans;
    }
};