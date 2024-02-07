class Solution {
public:
    string frequencySort(string s) {
        int arr[26];
        int arr2[26];
        int arr3[10];
        memset(arr,0,26);
        memset(arr2,0,26);
        memset(arr2,0,26);
        priority_queue<pair<int,char>> pq;
        
        for(int i=0;i<s.size();i++){
            if(s[i]>='a' && s[i]<='z')
                arr[s[i]-'a']++;
            else if(s[i]>='A' && s[i]<='Z')
                arr2[s[i]-'A']++;
            else if(s[0]>='0' && s[i]<='9')
                arr3[s[i]-'0']++;
                
        }
        
        for(int i=0;i<26;i++){
            if(arr[i]>0)
                pq.push({arr[i],i+'a'});
            if(arr2[i]>0)
                pq.push({arr2[i],i+'A'});
            
            if(i<10){
                if(arr3[i]>0){
                pq.push({arr3[i],i+'0'});
                }
            }
        }
    
        
        int k=0;
        while(!pq.empty()){
            char ch = pq.top().second;
            int num = pq.top().first;
            
            for(int i=0;i<num;i++){
                s[k++] = ch;
            }
            
            pq.pop();
        }
        
        return s;
    }
};