class Solution {
public:
    
    int furthestBuilding(vector<int>& arr, int bricks, int ladders) {
        int n = arr.size();
        priority_queue<int> pq;
        int reach = 0,diff=0;
        for(int i=1;i<n;i++){
            if(arr[i-1]>arr[i]){
                reach++;
                continue;
            }
            diff = arr[i]-arr[i-1];
            if(bricks >= diff){
                reach++;
                bricks -= diff;
                pq.push(diff);
            }
            else if(!pq.empty() && pq.top() > diff && ladders > 0){
                ladders--;
                reach++;
                bricks += pq.top();
                pq.pop();
                bricks -= diff;
                pq.push(diff);
            }else if(ladders > 0){
                reach++;
                ladders--;
            }else
                break;
            
        }
        return reach;
    }
};