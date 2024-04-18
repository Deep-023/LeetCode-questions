#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

template<class T> using oset = tree<T,null_type,greater_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        oset<long long> set;
        long long ans = 0,n=nums.size();
        for(int i=0;i<n;i++){
           // if(nums[i]<= INT_MAX/2 && nums[i] >= INT_MIN/2 )
            ans += set.order_of_key(2*1ll*nums[i]);
            set.insert(nums[i]);
        }
        return ans;
        
    }
};