#include<bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:
    unordered_map<Node*,Node*> mp;

    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        if(!mp.count(node)) {
            mp[node] = new Node (node -> val, {});

            for(auto &i : node->neighbors){
                mp[node]->neighbors.push_back(cloneGraph(i));
            }
        }    
        return mp[node];
    }
};

/*
    TC => O(V + E) + O(V) ~= O(V + E) for the larger graph the O(V) is negligible
    SC => O(V + E)
*/
