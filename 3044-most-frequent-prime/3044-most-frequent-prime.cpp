class Solution {
public:
    
    bool isPrime(int a){
        for(int i=2;i<=sqrt(a);i++){
            if(a%i==0)
                return false;
        }
        return true;
    }
    
    
    int mostFrequentPrime(vector<vector<int>>& mat) {
        unordered_map<int,int> mp;
        int m = mat.size(),n=mat[0].size();
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                string str = "";
                for(int k=j;k<n;k++){
                    str.push_back(mat[i][k]+'0');
                    int num = stoi(str);
                    if(num > 10 && isPrime(num)){
                        mp[num]++;
                    }
                }
                str = "";
                for(int k=i;k<m;k++){
                    str.push_back(mat[k][j]+'0');
                    int num = stoi(str);
                    if(num > 10 && isPrime(num)){
                        mp[num]++;
                    }
                }
                str = "";
                int k = j;
                while(k>=0){
                    str.push_back(mat[i][k]+'0');
                    int num = stoi(str);
                    if(num > 10 && isPrime(num)){
                        mp[num]++;
                    }
                    k--;
                }
                str = "";
                k = i;
                while(k>=0){
                    str.push_back(mat[k][j]+'0');
                    int num = stoi(str);
                    if(num > 10 && isPrime(num)){
                        mp[num]++;
                    }
                    k--;
                }
                str = "";
                int p = i,q=j;
                while(p<m && q<n){
                    str.push_back(mat[p][q]+'0');
                    int num = stoi(str);
                    if(num > 10 && isPrime(num)){
                        mp[num]++;
                    }
                    p++;q++;
                }
                str = "";
                p = i,q=j;
                while(p<m && q>=0){
                    str.push_back(mat[p][q]+'0');
                    int num = stoi(str);
                    if(num > 10 && isPrime(num)){
                        mp[num]++;
                    }
                    p++;q--;
                }
                str = "";
                p = i,q=j;
                while(p>=0 && q<n){
                    str.push_back(mat[p][q]+'0');
                    int num = stoi(str);
                    if(num > 10 && isPrime(num)){
                        mp[num]++;
                    }
                    p--;q++;
                }
                str = "";
                p = i,q=j;
                while(p>=0 && q>=0){
                    str.push_back(mat[p][q]+'0');
                    int num = stoi(str);
                    if(num > 10 && isPrime(num)){
                        mp[num]++;
                    }
                    p--;q--;
                }
            }
        }
        
        int mx=-1,count = 0;
        for(auto& i:mp){
            if(count<i.second){
                mx = i.first;
                count = i.second;   
            }
            if(count == i.second  && mx<i.first)
                mx = i.first;
        }
        
        return mx;
        
    }
};