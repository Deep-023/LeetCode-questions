class Solution {
public:
    
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<pair<double,int>> vec;
        for(int i=0;i<n;i++)
            vec.push_back({wage[i]*1.0/quality[i], quality[i]});

        sort(vec.begin(),vec.end());
        priority_queue<int> highQuality;
        double ans = DBL_MAX;
        long long totalQual = 0;
        for(int i=0;i<n;i++){
            double ratio = vec[i].first;
            int qual = vec[i].second;
            totalQual += qual;
            highQuality.push(qual);
            if(highQuality.size()>k){
                totalQual -= highQuality.top();
                highQuality.pop();
            }

            if(highQuality.size() == k){
                ans = min(ans,totalQual*ratio);
            }
        }

        return ans;
    }
};