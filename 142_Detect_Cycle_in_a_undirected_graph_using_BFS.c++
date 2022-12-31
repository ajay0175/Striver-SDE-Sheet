#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
    bool checkForCycle(int s, int V, vector<int> adj[], vector<int> &visited)
    {
        // Create a queue for BFS
        queue<pair<int, int>> q;
        visited[s] = true;
        q.push({s, -1});
        while (!q.empty())
        {
            int node = q.front().first;
            int par = q.front().second;
            q.pop();
 
            for (auto it : adj[node])
            {
                if (!visited[it])
                {
                    visited[it] = true;
                    q.push({it, node});
                }
                else if (par != it){
                    return true;
                }
            }
        }
        return false;
    }

    bool isCycle(int V, vector<int> adj[])
    {
        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (checkForCycle(i, V, adj, vis)) {
                    return true;
                }
            }
        }

        return false;
    }
};
 
void addEdge(vector<int> adj[],int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main()
{
    vector<int> adj[5];
   
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 4);
   
    Solution obj;
    int num = obj.isCycle(5, adj);

    if(num == 1){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
 
    return 0;
}

/*
    Time Complexity:  O(N+E) => N is the time taken and E is for traveling through adjacent nodes overall. 
    Space Complexity: O(N+E) +  O(N) + O(N) => space for adjacent list , array and queue
*/