class Solution {
public:
    int largestInteger(int num) {
        string temp = to_string(num);
        string eve,odd;
        priority_queue<int> pq;
        for(int i=0;i<temp.size();i++){
            pq.push(temp[i]-'0'); 
        }
        
        for(int i=0;i<temp.size();i++){
            int num= pq.top();
            if(num&1){
                odd.push_back(num+'0');
            }else
                eve.push_back(num+'0');
            pq.pop();
        }
        int k=0,j=0;
        for(int i=0;i<temp.size();i++){
            if((temp[i]-'0')&1)
                temp[i] = odd[k++];
            else
                temp[i]= eve[j++];
        }
        
        return stoi(temp);   
    }
};