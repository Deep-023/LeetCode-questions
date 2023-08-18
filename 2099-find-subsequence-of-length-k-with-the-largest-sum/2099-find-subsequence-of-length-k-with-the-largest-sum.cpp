class Solution {
public:
    vector<int> maxSubsequence(vector<int>& dub, int k) {
        priority_queue<int>pq(dub.begin(),dub.end());
        unordered_map<int,int>m;
        vector<int> ans;
        int n = dub.size();
        for(int i=n-k;i<n;i++){
            m[pq.top()]++;
            pq.pop();
        }
        for(int i=0;i<n;i++){
            if(m[dub[i]]>0){
                m[dub[i]]--;
                ans.push_back(dub[i]);
            }
        }
        return ans;
    }
};