class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int sum = accumulate(arr.begin(),arr.end(),0);
        if(sum%3)
            return false;
        int target = sum/3;
        cout<<target<<endl;
        int n = arr.size(),check=0,s=0;
        for(int i=0;i<n;i++){
            s+=arr[i];
            if(s==target){
                s = 0;
                check++;
            }
        }

        return check>=3;
    }
};