class Solution {
public:
    
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> mp;
        for (int i = 0; i < arr2.size(); i++)
            mp[arr2[i]] = i;

        sort(arr1.begin(), arr1.end(), [&mp](int a, int b) {
            if (mp.count(a) && mp.count(b))
                return mp[a] < mp[b];
            if (mp.count(a))
                return true;
            if (mp.count(b))
                return false;
            return a < b;
        });

        return arr1;
    }
};