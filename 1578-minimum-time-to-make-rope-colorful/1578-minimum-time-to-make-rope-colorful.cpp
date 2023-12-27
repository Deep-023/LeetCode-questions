class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int mini = neededTime[0],ans=0,sum=neededTime[0];\
        int n = colors.size();
        for(int i=1;i<n;i++){
            sum+= neededTime[i];
            if(colors[i-1]==colors[i]){
                mini = max(mini,neededTime[i]);
            }else{
                ans += mini;
                mini = neededTime[i];
            }
        }
        
        ans += mini;
        return sum-ans;
    }
};