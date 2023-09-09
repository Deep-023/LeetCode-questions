class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        map<long long,long long> chart;
        for(auto i:segments){
            chart[i[0]] += i[2];
            chart[i[1]] -= i[2];
        }
        vector<vector<long long>> ans;
        long long prev, color = 0;
        for(auto curr : chart){
            if(color)
                ans.push_back({ prev, curr.first , color });
            color += curr.second;
            prev = curr.first;
        }
        return ans;
    }
};