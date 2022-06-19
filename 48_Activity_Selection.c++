// same as N meeting in a room
#include <bits/stdc++.h>
using namespace std;

int maximumActivities(vector<int> &start, vector<int> &finish) {
    int n = start.size();
    vector<pair<int, int>> v;
    int activities = 0;
    
    for(int i = 0; i < n; i++)
    {
        v.push_back({finish[i], start[i]});
    }
    
    sort(v.begin(), v.end());
    int prev = -1;
    for(int i = 0 ; i < n ; i++)
    {
        if(v[i].second >= prev)
            activities++, prev = v[i].first;
    }
    
    return activities;
}

int main() {
   vector<int> start = {1,3,0,5,8,5};
   vector<int> end = {2,4,5,7,9,9};
  maximumActivities(start, end);
   return 0;
}

/*
    TC => O(N)
    SC => O(N)
*/