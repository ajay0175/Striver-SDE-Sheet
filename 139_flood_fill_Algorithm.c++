#include <bits/stdc++.h>
using namespace std;    

class Solution {
public:
    
    void dfs(vector<vector<int>>& image, int i, int j, int previousColor, int newColor)
    {
        if(i < 0 or i >= image.size() or j < 0 or j >= image[0].size() or image[i][j] == newColor or image[i][j] != previousColor)
        {
            return;
        }

        image[i][j] = newColor;

        dfs(image, i - 1, j, previousColor, newColor);  //up
        dfs(image, i + 1, j, previousColor, newColor);  //down
        dfs(image, i, j - 1, previousColor, newColor);  //left
        dfs(image, i, j + 1, previousColor, newColor);  //right
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int x, int y, int newColor)
    {
        int previousColor = image[x][y];
        dfs(image, x, y, previousColor, newColor);
        return image;
    }
};

int main() {
    vector<vector<int>> image = {
        {1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 0, 0},
        {1, 0, 0, 1, 1, 0, 1, 1},
        {1, 2, 2, 2, 2, 0, 1, 0},
        {1, 1, 1, 2, 2, 0, 1, 0},
        {1, 1, 1, 2, 2, 2, 2, 0},
        {1, 1, 1, 1, 1, 2, 1, 1},
        {1, 1, 1, 1, 1, 2, 2, 1},
    };

    int x = 4, y = 4, newColor = 3;

    Solution obj;
    obj.floodFill(image, x, y, newColor);

    cout << "The Updated image after calling floodFill Algorithm: \n";

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
           cout << image[i][j] << " ";
        cout << '\n';
    }

    return 0;
}

/*
    TC => O(M * N)
    SC => O(M * N) => Auxilary space
*/