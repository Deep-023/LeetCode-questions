class Graph {
public:
    vector<vector<long>> graph;
    int N=0;
    Graph(int n, vector<vector<int>>& edges) {
        N = n;
        graph = vector<vector<long>>(n,vector<long>(n,1e9));
        
        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]][edges[i][1]] = edges[i][2];
        }
        
        for(int i=0;i<n;i++)
            graph[i][i] = 0;
        
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    graph[i][j] = min(graph[i][j], graph[i][k]+graph[k][j]);
                }
            }
        }
    }
    
    void addEdge(vector<int> edge) {
        for(int i=0;i<N;++i){
            for(int j=0;j<N;++j){
                graph[i][j] = min(graph[i][j],graph[i][edge[0]]+graph[edge[1]][j]+edge[2]);
            }
        }

    }
    
    int shortestPath(int node1, int node2) {
        return graph[node1][node2] >= 1e9 ? -1 : graph[node1][node2] ;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */