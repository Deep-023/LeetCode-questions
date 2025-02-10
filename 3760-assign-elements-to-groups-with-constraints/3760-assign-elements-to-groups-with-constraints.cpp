class Solution {
public:
    vector<int> assignElements(vector<int>& groups, vector<int>& elements) {
        vector<int> arr(1e5+1,-1);
        int n = groups.size();
        vector<int> ans(n,-1);
        unordered_set<int> s;
        for(int i=0;i<elements.size();i++){
            if(s.count(elements[i]) || arr[elements[i]] != -1) continue;
            for(int p = elements[i] ; p<= 1e5 ; p+=elements[i]){
                if(arr[p] == -1)
                    arr[p] = i;
            }
            s.insert(elements[i]);
        }

        for(int i=0;i<n;i++){
            ans[i] = arr[groups[i]];
        }

        return ans;
    }
};