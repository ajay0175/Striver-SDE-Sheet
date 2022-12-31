#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
    bool isCycle(int V, vector<int> adj[])
    {
        int indegree[V] = {0};

        for (int i = 0; i < V; i++)
        {
           for(auto &it : adj[i]) {
                indegree[it]--;
           }
        }

        queue<int> q;

        for(int i = 0; i < V; i++) {
            if (indegree[i] == 0)
            {
                q.emplace(i);
            }
        }

        int cnt = 0;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            cnt++;

            for(auto it : adj[node]) {
                indegree[it]--;
                if(indegree[it] == 0) {
                    q.emplace(it);
                }
            }
        }

        if(cnt == V) {
            return false;
        }

        return true;
    }
};
 
void addEdge(vector<int> adj[],int u,int v)
{
    adj[u].push_back(v);
}

int main()
{
    vector<int> adj[5];
   
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 0);
    addEdge(adj, 3, 4);
    addEdge(adj, 4, 5);
   
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
    Space Complexity: O(N) + O(N) + O(N) => space for adjacent list , array and queue
*/