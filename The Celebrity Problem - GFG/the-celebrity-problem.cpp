//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& m, int n) 
    {
        stack<int> s;
        
        for(int i=0;i<n;i++){
            s.push(i);    
        }
        
        while(s.size()>1){
            int a=s.top();
            s.pop();
            int b=s.top();
            s.pop();
            
            if(m[a][b] == 1 && m[b][a] == 0 ){
                s.push(b);
            }
            else if(m[a][b] == 0 && m[b][a] == 1 )
                s.push(a);
        }
        
        if(s.size() == 0)
            return -1;
        
        int top = s.top();
        for(int i=0;i<n;i++){
            if(m[top][i] == 1)
                return -1;
            if(i!=top && m[i][top]==0)
                return -1;
        }
        return top;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends