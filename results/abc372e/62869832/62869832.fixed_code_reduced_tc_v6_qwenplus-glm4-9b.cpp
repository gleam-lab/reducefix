#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    vector<int> parent;
    vector<int> rank;
    vector<vector<int>> sizes;
    vector<vector<int>> sorted_vertices;

    UnionFind(int n) : parent(n + 1), rank(n + 1, 0), sizes(n + 1, vector<int>(n + 1, 0)), sorted_vertices(n + 1) {}

    int find(int x) {
        if (parent[x] == x) return x;
        parent[x] = find(parent[x]);
        return parent[x];
    }

    void union_sets(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);
        if (rootA != rootB) {
            if (rank[rootA] > rank[rootB]) {
                parent[rootB] = rootA;
            } else if (rank[rootA] < rank[rootB]) {
                parent[rootA] = rootB;
            } else {
                parent[rootB] = rootA;
                rank[rootA]++;
            }
            // Merge the sizes and sorted_vertices of the two sets
            sizes[rootA].insert(sizes[rootA].end(), sizes[rootB].begin(), sizes[rootB].end());
            sorted_vertices[rootA].insert(sorted_vertices[rootA].end(), sorted_vertices[rootB].begin(), sorted_vertices[rootB].end());
        }
    }
    
    // Additional methods to handle the k-th largest vertex query
};