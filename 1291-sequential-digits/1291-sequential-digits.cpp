class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>ans;
        string s = "123456789";
        
        for(int i=0;i<9;i++){
            for(int j=i;j<9;j++){
                int num = stoi(s.substr(i,j-i+1));
                if(num>=low && num<=high)
                    ans.push_back(num);
                else if(num>high)
                    break;
            }
        }
        
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};