#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> componentes;

class Solution
{
private:
    void dfs(int node, vector<int> &vis, vector<int> adj[], stack<int> &st)
    {
        vis[node] = 1;
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                dfs(it, vis, adj, st);
            }
        }

        st.push(node);
    }

private:
    void dfs3(int node, vector<int> &vis, vector<int> adjT[], vector<int> &temp)
    {
        vis[node] = 1;
        temp.emplace_back(node);
        for (auto it : adjT[node])
        {
            if (!vis[it])
            {
                dfs3(it, vis, adjT, temp);
            }
        }
    }

public:
    // Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        // step one make a dfs call and store all the last visited value to stack
        vector<int> vis(V, 0);
        stack<int> st;
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs(i, vis, adj, st);
            }
        }

        // step two create a transpose list and reverse the graph using transpose list
        vector<int> adjT[V];
        for (int i = 0; i < V; i++)
        {
            vis[i] = 0;
            for (auto it : adj[i])
            {
                // i -> it
                // it -> i
                adjT[it].push_back(i);
            }
        }

        // step three make a dfs call on the reverse graph and count no. of scc
        int scc = 0;
        while (!st.empty())
        {
            vector<int> temp;
            int node = st.top();
            st.pop();
            if (!vis[node])
            {
                scc++;
                dfs3(node, vis, adjT, temp);
                componentes.emplace_back(temp);
            }
        }
        return scc;
    }
};

int main()
{

    int n = 5;
    int edges[5][2] = {
        {1, 0}, {0, 2}, {2, 1}, {0, 3}, {3, 4}};
    vector<int> adj[n];
    for (int i = 0; i < n; i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
    }
    Solution obj;
    int ans = obj.kosaraju(n, adj);
    cout << "The number of strongly connected components is: " << ans << endl;
    cout << "The components are: " << endl;
    for (auto &v : componentes)
    {
        for (auto &ele : v)
        {
            cout << ele << " ";
        }

        cout << endl;
    }
    return 0;
}

/*
    Time Complexity => O(V+E) + O(V+E) + O(V+E) ~ O(V+E) , where V = no. of vertices, E = no. of edges. The first step is a simple DFS, so the first term is O(V+E). The second step of reversing the graph and the third step, containing DFS again, will take O(V+E) each.

    Space Complexity => O(V) + O(V) + O(V+E), where V = no. of vertices, E = no. of edges. Two O(V) for the visited array and the stack we have used. O(V+E) space for the reversed adjacent list.
*/