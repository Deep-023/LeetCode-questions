class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        map<int,vector<int>> m;
        for(int i=0;i<groupSizes.size();i++){
            m[groupSizes[i]].push_back(i);
        }
        vector<vector<int>>ans;
        for(auto i:m){
            vector<int> num;
            int n=1;
            for(int j=0;j<i.second.size();j++){
                if(n<i.first){
                    n++;
                    num.push_back(i.second[j]);
                }
                else if(n==i.first){
                    num.push_back(i.second[j]);
                    ans.push_back(num);
                    n=1;
                    num={};
                }
            }
        }
        return ans;
    }
};