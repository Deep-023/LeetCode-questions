class Solution {
public:
    vector<int> arr[501];
    int checkWays(vector<vector<int>>& pairs) {
        int count = 0;
        for(int i=0;i<pairs.size();i++){
            arr[pairs[i][0]].push_back(pairs[i][1]);
            arr[pairs[i][1]].push_back(pairs[i][0]);
        }
        
        priority_queue<pair<int,int>> pq;
        for(int i=1;i<=500;i++){
            int size = arr[i].size();
            if(size>0) pq.push({size,i});
        }

        int size = pq.size();
        int ans = 1;
        unordered_set<int> visited;

        while(!pq.empty()){
            int currNode = pq.top().second;
            int degree = pq.top().first;
            pq.pop();

        /*3.1 find neighbouring node with least degree that is >= currNode's degree*/
            int parent = -1;
		    int parentDegree = INT_MAX;
		for(auto &neighbour : arr[currNode]){
			if(visited.count(neighbour) && arr[neighbour].size() < parentDegree && arr[neighbour].size() >= degree){
				parent = neighbour;
				parentDegree = arr[neighbour].size();
			}
		}
		visited.insert(currNode);

        /*3.2 case when parent is not found => check if currNode itself is the root. 
		 if not, then tree can't be made*/
		if(parent == -1){
			if(degree != size-1) return 0;
			continue;
		}
        /*3.3 now check whether parent's adjList contains all the nodes present in currNode's adjList.
		 if not, then tree can't be made.*/
		for(auto &neighbour : arr[currNode]){
			if(neighbour == parent) continue;
			if(find(arr[parent].begin(),arr[parent].end(),neighbour) == arr[parent].end()) return 0;
		}

        /*3.4 check the special case of multiple trees when parent and currentNode have same degree*/
		if(degree == parentDegree)
			ans = 2;
        }

        return ans;

    }
};