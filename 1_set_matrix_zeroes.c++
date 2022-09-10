#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>> &matrix)
{
    int n = matrix.size(), m = matrix[0].size(), col_0 = 1;

    for(int i = 0; i < n; i++)
    {
        if(matrix[i][0] == 0)
        {
            col_0 = 0;
        }
        for(int j = 1; j < m; j++)
        {
            if(matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        for(int j = m - 1; j >= 1; j--)
        {
            if(matrix[i][0] == 0 or matrix[0][j] == 0)
            {
                matrix[i][j] = 0;
            }        
        }

        if(col_0 == 0)
            matrix[i][0] = 0;
    }
    
}

/*
    TC => O((N*M)) + (N*M))
    SC => O(1)
*/
};