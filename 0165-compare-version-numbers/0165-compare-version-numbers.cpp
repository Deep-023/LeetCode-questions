class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> a;
        vector<int> b;
        stringstream v1(version1);
        stringstream v2(version2);
        string segment;
        while(getline(v1, segment, '.'))
            a.push_back(stoi(segment));

        while(getline(v2, segment, '.'))
            b.push_back(stoi(segment));

        int i=0,j=0,n=a.size(),m=b.size();
        while(i<n && j<m){
            if(a[i]<b[i])
                return -1;
            else if(a[i]>b[j])
                return 1;
            else{
                i++;
                j++;
            }
        }
        while(i<n){ 
            if(a[i++]!=0)
                return 1;
        }
        while(j<m){ 
            if(b[j++]!=0)
                return -1;
        }
        
        return 0;
    }
};