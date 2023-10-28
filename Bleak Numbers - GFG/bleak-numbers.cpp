//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
	int is_bleak(int n)
	{
	    int number = n;
	    int num = n;
	    int bits = 0;
	    while(num>0){
	        bits++;
	        num /= 2;
	    }
	    
	    for(int i=1;i<=bits;i++){
	        num = n-i;
	        number = num;
	        int bbits = 0;
	        while(num>0){
	            if(num%2 == 1)
	                bbits++;
	            num /= 2;
	        }
	        if(number+bbits == n)
	            return 0;
	    }
	    return 1;
	}
};


//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	Solution ob;
    	int ans = ob.is_bleak(n);
    	cout << ans << "\n";
    }
	return 0;
}

// } Driver Code Ends