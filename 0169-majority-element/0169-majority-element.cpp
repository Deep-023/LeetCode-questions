class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> m;
        int n = nums.size();
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        for(auto i= m.begin();i!= m.end();i++){
            if(i->second > n/2)   
                return i->first;
        }
        return -1;
    }
};