class Solution {
public:
    bool check(string &s, int idx, int sum, int num ){
        if(idx==s.size()){
            if(sum==num){
                return true;
            }
            return false;
        }

        for(int i=idx;i<s.size();i++){
            string temp = s.substr(idx,i-idx+1);
            if(check(s,i+1,sum+stoi(temp),num))
                return true;
        }

        return false;
    }

    int punishmentNumber(int n) {
        int ans = 1;
        for(int i=2;i<=n;i++){
            string s = to_string(i*i);
            if(check(s,0,0,i)){
                ans += i*i;
            }
        }

        return ans;
    }
};