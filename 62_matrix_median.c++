#include<bits/stdc++.h>
using namespace std;

int getMedian(vector<vector<int>> &matrix)
{
    vector<int> ans;
    
    for(int i = 0; i < matrix.size(); i++)
    {
        for(int j = 0; j < matrix[0].size(); j++)
        {
            ans.emplace_back(matrix[i][j]);
        }
    }
    
   sort(ans.begin(), ans.end());
    int mid = ans.size() / 2;
    return ans[mid];
}

int main()
{
    vector<vector<int>> m {{1,3,5}, {2,6,9}, {3,6,9}};

    int ans = getMedian(m);
    cout << ans << '\n';

}

/*
    TC => O(N * M) + O((N + M)LOG(N + M))
    SC => O(N + M)
*/