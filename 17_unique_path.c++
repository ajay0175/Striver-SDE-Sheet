#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countPaths(int i,int j,int n,int m,vector<vector<int>> &dp)
    {
        if(i==(n-1)&&j==(m-1)) return 1;
        if(i>=n||j>=m) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
     else return dp[i][j]=countPaths(i+1,j,n,m,dp)+countPaths(i,j+1,n,m,dp);
        
    }
    int uniquePaths1(int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
       
        //dp[1][1]=1;
       int num=countPaths(0,0,m,n,dp);
        if(m==1&&n==1)
            return num;
        return dp[0][0];
    }


    int uniquePaths2(int m, int n) {
            int N = n + m - 2;
            int r = m - 1; 
            double res = 1;
            
            for (int i = 1; i <= r; i++)
                res = res * (N - r + i) / i;
            return (int)res;
    }
};

int main()
{
    Solution obj;
    int totalCount= obj.uniquePaths1(3,7);
    cout<<"The total number of Unique Paths are "<<totalCount<<endl;
}

/*
    Dynamic Programmming Approch
    TC => (N  * M) AT MAX THERE CAN BE (n * m) number of states
    SC => (N * M)
*/

/*
    Combonatorics Approch (optimal)
    TC => (N - 1 OR M - 1)
    SC => (1)
*/

