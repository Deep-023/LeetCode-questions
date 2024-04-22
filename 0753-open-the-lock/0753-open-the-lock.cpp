typedef pair<string,int> pp;
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> set(deadends.begin(),deadends.end());

        if(set.count("0000")) return -1;
        queue<pp> q;
        q.push({"0000",0});
        set.insert("0000");
        int ans = INT_MAX;
        while(!q.empty()){
            auto [str, cost] = q.front();
            q.pop();

            if(str==target) return cost;
            for(int i=0;i<4;i++){
                char temp = str[i];
                str[i] = (temp-'0'+1)%10+'0';
                if(!set.count(str)){
                    set.insert(str);
                    q.push({str,cost+1});
                }
                str[i] = (temp-'0'-1+10)%10+'0'; 
                if(!set.count(str)){
                    set.insert(str);
                    q.push({str,cost+1});
                }
                str[i] = temp;
            }
        }
        return -1;
    }
};