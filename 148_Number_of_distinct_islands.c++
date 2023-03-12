#include <bits/stdc++.h>
using namespace std;

#define vvi     vector<vector<int>>
#define vpii    vector<pair<int, int>>

class Solution
{
private:
    void dfs(int row, int col, vvi &vis, vvi &grid, vpii &vec, int row0, int col0)
    {
        // mark the cell as visited
        vis[row][col] = 1;

        // coordinates - base coordinates
        vec.push_back({row - row0, col - col0});
        int n = grid.size();
        int m = grid[0].size();

        // delta row and delta column
        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, -1, 0, +1};

        // traverse all 4 neighbours
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            // check for valid unvisited land neighbour coordinates
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                !vis[nrow][ncol] && grid[nrow][ncol] == 1)
            {
                dfs(nrow, ncol, vis, grid, vec, row0, col0);
            }
        }
    }

public:
    int countDistinctIslands(vvi &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vvi vis(n, vector<int>(m, 0));
        set<vpii> st;

        // traverse the grid
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                // if not visited and is a land cell
                if (!vis[i][j] && grid[i][j] == 1)
                {
                    vpii vec;
                    dfs(i, j, vis, grid, vec, i, j);
                    // store in set
                    st.insert(vec);
                }
            }
        }
        return st.size();
    }
};

int main()
{

    vvi grid{
        {1, 1, 0, 1, 1},
        {1, 0, 0, 0, 0},
        {0, 0, 0, 0, 1},
        {1, 1, 0, 1, 1}};

    Solution obj;
    cout << obj.countDistinctIslands(grid) << endl;
}

/*
    TC => O(N * M * LOG(N * M)) + o(N * M * 4) ~ O(N * M)
        // In the worst case we are traversing for all 4 neighbours of a node.
    SC => O(N * M) // Visited array and set
*/