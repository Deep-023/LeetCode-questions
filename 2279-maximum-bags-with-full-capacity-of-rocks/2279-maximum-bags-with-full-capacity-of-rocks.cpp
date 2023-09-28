class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int addR) {
        vector<int> need;
        int n = capacity.size();
        for(int i=0;i<n;i++){
            need.push_back(capacity[i]-rocks[i]);
        }
        sort(need.begin(),need.end());
        int count = 0;
        for(int i=0;i<n;i++){
            if(need[i]==0)
                count++;
            else if(need[i]<=addR){
                addR -= need[i];
                count++;
            }
        }
        return count;
    }
};