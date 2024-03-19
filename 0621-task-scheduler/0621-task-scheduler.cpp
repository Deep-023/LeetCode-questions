class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26);
        for(int i=0;i<tasks.size();i++)
            count[tasks[i]-'A']++;
        priority_queue<int> pq;
        for(int i=0;i<26;i++){
            if(count[i]>0)
                pq.push(count[i]);
        }
        
        int ans = 0;
        while(!pq.empty()){
            int size = pq.size();
            vector<int> temp;
            int time = 0;
            for(int i=0 ;i<n+1;i++){
                if(!pq.empty()){
                    temp.push_back(pq.top()-1);
                    pq.pop();
                    time++;
                }
            }
            
            while(!temp.empty()){
                if(temp.back() > 0)
                    pq.push(temp.back());
                temp.pop_back();
            }
            
            ans += !pq.empty() ? n+1 : time;
        }
        return ans;
    }
};