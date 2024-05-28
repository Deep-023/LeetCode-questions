class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int left = 0,n = s.size();
        int mx = 0, len=0, og = maxCost;
        //cout<<n<<endl;
        for(int i=0;i<n;i++){
            //cout<<abs(s[i]-t[i])<<" ";
            if(abs(s[i]-t[i]) > og){
                maxCost = og;
                len = 0;
                left = i+1;
                continue;
            }

            while(left<i && maxCost < abs(s[i]-t[i])){
                if(maxCost + abs(s[left]-t[left]) <= og)
                    maxCost += abs(s[left]-t[left]);
                left++;
                len = max(0,len-1);
            }

            if(maxCost >= abs(s[i]-t[i])){
                //cout<<"i : "<<i<<" maxCost: "<<maxCost;
                maxCost -= abs(s[i]-t[i]);
                //cout<<" maxCost: "<<maxCost<< endl;
                len++;
            }
            mx = max(mx,len);
        }
        return mx;
    }
};

//3 6 15 11 3 9 8 15 22 10 3 7 3 4 0 