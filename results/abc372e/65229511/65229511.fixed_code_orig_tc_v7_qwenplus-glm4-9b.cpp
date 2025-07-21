#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const int MAX_N = 200100; // Adjusted for 1-based indexing

int parent[MAX_N];
int rank[MAX_N];

void initializeUnionFind(int n) {
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
        rank[i] = 0;
    }
}

int findRoot(int x) {
    if (x != parent[x])
        parent[x] = findRoot(parent[x]);
    return parent[x];
}

void unite(int x, int y) {
    int rootX = findRoot(x);
    int rootY = findRoot(y);
    
    if (rootX != rootY) {
        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
}

vector<int> queries;

int main() {
    int n, q;
    cin >> n >> q;

    // Reading and storing queries
    for (int i = 0; i < q; ++i) {
        int type;
        cin >> type;
        if (type == 1) {
            int u, v;
            cin >> u >> v;
            queries.push_back(1);
            queries.push_back(u);
            queries.push_back(v);
        } else if (type == 2) {
            int v, k;
            cin >> v >> k;
            queries.push_back(2);
            queries.push_back(v);
            queries.push_back(k);
        }
    }

    // Processing queries
    initializeUnionFind(n);
    
    for (int i = 0; i < queries.size(); ++i) {
        int type = queries[i];
        if (type == 1) {
            int u = queries[i + 1];
            int v = queries[i + 2];
            unite(u, v);
            i += 2;
        } else if (type == 2) {
            int v = queries[i + 1];
            int k = queries[i + 2];
            int rootV = findRoot(v - 1); // Convert to 0-based index
            set<int> adjVertices;
            for (int i = 0; i < n; ++i) {
                if (findRoot(i) == rootV) {
                    adjVertices.insert(i + 1); // Convert to 1-based index
                }
            }
            if (adjVertices.size() < k) {
                cout << -1 << endl;
            } else {
                auto it = adjVertices.rbegin();
                advance(it, k - 1);
                cout <<*it << endl;
            }
            i += 2;
        }
    }

    return 0;
}