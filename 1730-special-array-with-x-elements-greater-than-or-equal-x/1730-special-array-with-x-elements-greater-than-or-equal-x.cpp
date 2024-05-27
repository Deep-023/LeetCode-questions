#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

class Solution {
public:
    template<class T> using oset = tree<T,null_type,greater_equal<int>,rb_tree_tag,tree_order_statistics_node_update>;
    
    int specialArray(vector<int>& nums) {
        oset<int> set;
        for(int i=0;i<nums.size();i++)
            set.insert(nums[i]);
        int mx = *max_element(nums.begin(),nums.end());

        for(int i=1;i<=mx;i++){
            if(i==set.order_of_key(i-1))
                return i;
        }
        return -1;
    }
};