#include<bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &A, vector<int> &B, int k) {
    sort(A.begin(), A.end());
    sort(B.begin(),B.end());
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(int i = A.size() - 1; i >= 0; i--)
    {
        for(int j = B.size() - 1; j >= 0; j--)
        {
            int sum = A[i] + B[j];
            if(pq.size() == k)
            {
                if(pq.top() < sum)
                {
                    pq.pop();
                    pq.push(sum);
                }
                else
                {
                    break;
                }
            }
            else 
            {
                pq.push(sum);
            }
        }
    }
    
    vector<int> ans(k, 0);
    for(int i = 0; i < k; i++)
    {
        ans[k - i - 1] = pq.top();
        pq.pop();
    }
    
    return ans;
}

int main()
{
    vector<int> a{1, 3};
    vector<int> b{4, 2};
    int k = 2;

    vector<int> ans = solve(a, b, k);

    for(auto &e : ans)
    {
        cout << e << " ";
    }

    return 0;
}


/*
    TC => O(2NLOGN + 4 + K)
    SC => O(K)
*/  