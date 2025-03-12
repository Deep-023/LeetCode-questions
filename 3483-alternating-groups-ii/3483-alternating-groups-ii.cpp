class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        int ans = 0, preNum = 0, lastPost=0;

        for(int i=1;i<n;i++){
            if(colors[i]==colors[i-1]){
                if(lastPost == 0) preNum = i;
                lastPost = i;
            }
            if(i - lastPost + 1 >= k) ans++;
        }

        if(preNum==0 && lastPost==0 && colors[0] != colors[n-1]) return n;
    
        lastPost = max(lastPost,n-k+1);
        preNum = min(preNum,k-1);
        if(n-lastPost+preNum >= k && colors[0] != colors[n-1]){
            ans += (n-lastPost+preNum-k+1);
        }

        return ans;
    }
};