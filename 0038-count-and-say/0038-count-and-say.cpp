class Solution {
public:
    string countAndSay(int n) {
        string s = "1"; 
        for(int i=1;i<n;i++){
            string temp = "";
            pair<char,int> count = {'_',0};
            for(int j=0;j<s.size();j++){
                //cout<<count.first<<" "<<count.second<<endl;
                if(count.first == '_'){
                    count.first = s[j];
                    count.second++;
                }
                else if(count.first != s[j]){
                    temp += to_string(count.second) + string(1,count.first); 
                    count.second = 1;
                    count.first = s[j];
                }else
                    count.second++;
            }
            //cout<<count.first<<" "<<count.second<<endl;
            temp = temp + to_string(count.second) + string(1,count.first);
            //cout<<temp<<endl;
            s = temp;
        }
        return s;
    }
};