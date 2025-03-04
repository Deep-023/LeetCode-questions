class Solution {
public:
    bool checkPowersOfThree(int n) {
        vector<int> arr;
        int temp = 1;
        while(temp<=n){
            arr.push_back(temp);
            temp *= 3;
        }

        unordered_set<int> st;
        st.insert(0);

        for(int i=0;i<arr.size();i++){
            vector<int> temparr;
            for(auto& j:st){
                if(j+arr[i]<=n)
                    temparr.push_back(j+arr[i]);
            }
            st.insert(temparr.begin(),temparr.end());
        }

        return st.count(n);
    }
};