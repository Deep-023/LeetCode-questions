class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0, n=fruits.size();
        int maxFruits = 0;
        unordered_map<int,int> mp;
        for( int right = 0; right<n; right++ ){
            while(mp.size()>=2 && !mp.count(fruits[right])){
                mp[fruits[left]]--;
                if(mp[fruits[left]]==0) mp.erase(fruits[left]);
                left++;
            }

            mp[fruits[right]]++;
            maxFruits = max(maxFruits,right-left+1);
        }

        return maxFruits;
    }
};