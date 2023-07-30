class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int tank=0;
        int ans=0, totalgas=0, totalcost=0;
        
        for(int i=0;i<n;i++){
            totalgas += gas[i];
            totalcost += cost[i];
            tank += gas[i]-cost[i];
            if(tank<0){
                ans=i+1;
                tank=0;
            }
                
        }
        return totalgas-totalcost >= 0 ? ans : -1;
    }
};