class Solution {
public:
    int bestClosingTime(string customers) {
        int ansInd=customers.size();
        int ans=0;
        vector<int> leftPenalty(ansInd,0);
        vector<int> rightPenalty(ansInd,0);
        int count=0;
        for(int i=0;i<ansInd;i++){
            if(customers[i]=='N')
                leftPenalty[i] = count++;
        }
        ans=count;
        count=0;
        for(int i=ansInd-1;i>=0;i--){
            if(customers[i]=='N')
                rightPenalty[i] = count;
            else
                count++;
        }
        
        for(int i=0;i<customers.size();i++){
            if(customers[i]=='N'){
                if(ans>leftPenalty[i]+rightPenalty[i]){
                    ans = leftPenalty[i]+rightPenalty[i];
                    ansInd = i;
                }else if(ans==leftPenalty[i]+rightPenalty[i] && ansInd>i)
                    ansInd=i;
            }
        }
        return ansInd;
    }
};