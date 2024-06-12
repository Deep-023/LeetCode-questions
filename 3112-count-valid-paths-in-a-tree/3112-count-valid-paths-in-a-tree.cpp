class Solution {
public:
    #define ll long long
    vector<ll> primes;
    vector<ll> visited,groupCount;
    vector<vector<int>> adj;
    ll groupNumber;
    
    ll dfs(ll node){ //count the number of nodes in a subgroup with 0 primes
        if(primes[node] || visited[node]!=0) return 0;
        visited[node] = groupNumber;
        
        ll ans = 1;
        for(auto &c:adj[node]){
            ans+=dfs(c);
        }
        return ans;
    }
    
    
    long long countPaths(int n, vector<vector<int>>& edges) {
        primes.resize(n+1,1);
        visited.resize(n+1,0);
        groupCount.resize(n+1,0);
        primes[0]=primes[1]=0; 

        for(ll i=2;i<=n;i++) // uses sieve's algo compute primes
            if(primes[i])
                for(ll j=i*i;j<=n;j+=i)
                    primes[j]=0;
        
        adj = vector<vector<int>>(n + 1, vector<int>());
        for(auto &e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        groupNumber = 1;
        
        for(ll i=1;i<=n;i++){ //give every node a group number
            ll count = dfs(i);
            if(count>0 || primes[i])
                groupCount[groupNumber++] = count;
        }
        ll ans=0;
        
        for(ll i=2;i<=n;i++){
            if(primes[i]){
                vector<ll> v;
                ll sum = 0;
                for(auto c:adj[i]){
                    v.push_back(groupCount[visited[c]]);
                    sum+=groupCount[visited[c]]; //calculate sum of the all the node in subgroups
                }
                ll curAns = 0;
                for(auto c:v){
                    curAns+=((sum-c)*c); //pairing all no primes with other non primes with prime as middle
                }
                curAns/=2; //every edge is counted twice i.e (a,b) & (b,a) so delete them
                curAns+=sum;
                ans+=curAns;
            }
        }
        return ans;
    }
};