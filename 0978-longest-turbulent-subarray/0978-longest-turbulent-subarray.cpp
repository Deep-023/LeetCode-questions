class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int count =1, maxCount=1, n=arr.size();
        int sign = 0;
        for(int i=0;i<n-1;i++){
            if(sign){
                if(arr[i]>arr[i+1]){
                    count++;
                }
                else if(arr[i]<arr[i+1]){
                    maxCount = max(count,maxCount);
                    sign = !sign;
                    count = 2;
                }
                else{
                    maxCount = max(count,maxCount);
                    count = 1;
                }
            }
            else 
            {
                if(arr[i]<arr[i+1]){
                    count++;
                }
                else if(arr[i]>arr[i+1]){
                    maxCount = max(count,maxCount);
                    sign = !sign;
                    count = 2;
                }else{
                    maxCount = max(count,maxCount);
                    count = 1;
                }
            }
            sign = !sign;
        }
        maxCount = max(count,maxCount);
        return maxCount;
        
    }
};