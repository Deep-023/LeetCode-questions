class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ans;
        sort(potions.begin(),potions.end());
        for(long long i:spells){
            int left = 0;
            int right = potions.size()-1;
            int mid = left + (right-left)/2;
            while(left<=right){
                if(potions[mid]*i >= success)
                    right = mid-1;
                else
                    left = mid+1;
                mid = left + (right-left)/2;
            }
            int count = potions.size() - left;
            ans.push_back(count);
        }
        return ans;
    }
};