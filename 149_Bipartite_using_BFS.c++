#include<bits/stdc++.h>
using namespace std;

class Solution {
private: 
    bool bfs(int start, vector<int> color, vector<int> adj[])
    {
        queue<int> q;
        q.push(start);
        color[start] = 0;

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(auto it: adj[node]) {
                if(color[it] == -1) {
                    color[it] = !color[node];
                    q.push(it); 
                }
                else if(color[it] == color[node]) {
                    return false;
                }
            }
        }

        return true;
    }
public:
    bool isBipartite(int V, vector<int>adj[]){
        vector<int> color(V, - 1); 
        
        // for connected components
        for(int i = 0;i<V;i++) {
            if(color[i] == -1) {
                if(bfs(i, color, adj) == false) 
                    return false; 
            }
        }
        return true; 
    }
};

void addEdge(vector <int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main(){
    
    // V = 4, E = 4
    vector<int>adj[4];
    
    addEdge(adj, 0, 2);
    addEdge(adj, 0, 3);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 1);

    Solution obj;
    bool ans = obj.isBipartite(4, adj);    
    if(ans)cout << "1\n";
    else cout << "0\n";  
    
    return 0;
}

/*
    TC => O(V + E)
    SC => O(V)
*/