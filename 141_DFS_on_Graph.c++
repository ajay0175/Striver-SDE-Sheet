#include <bits/stdc++.h>
using namespace std;


class Solution {
    private:
     void dfs(int node, vector<int> &vis, vector<int> adj[], vector<int> &storeDfs) {
        storeDfs.push_back(node); 
        vis[node] = 1; 

        for(auto it : adj[node]) {
            if(!vis[it]) {
                dfs(it, vis, adj, storeDfs); 
            }
        }
    }
  public:
    vector<int>dfsOfGraph(int n, vector<int> adj[]){
	    vector<int> storeDfs; 
	    vector<int> vis(n + 1, 0); 

        for(int i = 1; i <= n; i++) {
            if(!vis[i]) {
                dfs(i, vis, adj, storeDfs); 
            }
        }
	    return storeDfs; 
	}
};

void addEdge(vector < int > adj[], int u, int v) {
  adj[u].push_back(v);
  adj[v].push_back(u);
}

int main() {
    vector<int> adj[6];
    vector<int> ans;

    addEdge(adj,1,2);
    addEdge(adj,1,3);
    addEdge(adj,1,4);
    addEdge(adj,1,5);
    addEdge(adj,2,4);
    addEdge(adj,2,1);
    addEdge(adj,3,1);
    addEdge(adj,4,1);
    addEdge(adj,4,2);
    addEdge(adj,5,1);


    Solution obj;
    ans = obj.dfsOfGraph(5, adj);

    for(auto it : ans)
    cout << it << " ";

  return 0;
}

/*
    TC => O(N + E) [Where N i node and E is edges]
    SC => O(N + E) [It is for storing the adjency list] + O(2N)[It is for Auxilary space and visited array]
*/