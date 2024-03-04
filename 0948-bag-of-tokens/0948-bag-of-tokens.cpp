class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int i=0,n=tokens.size();
        int j = n-1,score=0,mx=0;
        
        while(i<=j){
            if(tokens[i]<=power){
                score++;
                power -= tokens[i++];
            }
            else{
                if(score>=1){
                    score--;
                    power += tokens[j--];
                }else
                    break;
            }
            mx = max(mx,score);
        }
        
        return mx;
    }
};