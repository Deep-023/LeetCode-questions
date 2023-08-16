class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>>pq;
        int n = nums.size(),count=0;
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(i<k){
                pq.push({nums[i],i});
                count++;
                if(count==k)
                    ans.push_back(pq.top().first);
            }else{
                pq.push({nums[i],i});
                while(!pq.empty() && pq.top().second<=i-k){
                    pq.pop();
                }
                ans.push_back(pq.top().first);
            }
        }
        return ans;
    }
};