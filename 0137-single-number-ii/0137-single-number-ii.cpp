class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<32;i++){ // for all the bits
            int sum=0;
            for(int j=0; j<nums.size();j++){
                if((nums[j]>>i)&1){ //checking it the desired bit is 1 or not
                    sum++;
                }
            }
            sum = sum%3; //taking mod of the count of number of times the bit was 1
            if(sum!=0){
                ans |= sum<<i; //adding the number at the desired position
            }  
        }
        return ans;
    }
};

/*brute force
int singleNumber(vector<int>& nums) {
        unordered_map<int,int> sett;
        for(int i=1;i<nums.size();i++){
            sett[nums[i]]++;
        }
        for(auto i:sett){
            if(i.second==1)
                return i.first;
        }
        return -1;
    }
*/