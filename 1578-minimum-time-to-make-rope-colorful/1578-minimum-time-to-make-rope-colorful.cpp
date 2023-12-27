class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int mini = neededTime[0];
        int ans=0,sum=mini,num;
    
        for(int i=1;i<colors.size();i++){
            num = neededTime[i];
            sum+= num;
            if(colors[i-1]==colors[i]){
                mini = max(mini,num);
            }else{
                ans += mini;
                mini = num;
            }
        }
        
        ans += mini;
        return sum-ans;
    }
};