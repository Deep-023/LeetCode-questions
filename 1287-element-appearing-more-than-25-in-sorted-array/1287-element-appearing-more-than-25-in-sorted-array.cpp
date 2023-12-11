class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int size = arr.size();
        if(size==1)
            return arr[0];
        int count = 1;
        for(int i=0;i<size-1;i++){
            if(arr[i]==arr[i+1])
                count++;
            else
                count = 1;
            if(count>size/4)
                return arr[i];
        }
        
        return -1;
    }
};