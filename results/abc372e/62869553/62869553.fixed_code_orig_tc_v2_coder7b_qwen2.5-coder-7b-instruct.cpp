#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    vector<int> parent, size;
    UnionFind(int n) : parent(n), size(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }
    
    int find(int x) {
        if (parent[x] != x) {
            return parent[x] = find(parent[x]);
        }
        return x;
    }
    
    void unite(int x, int y) {
        int rootX = find(x), rootY = find(y);
        if (rootX == rootY) return;
        
        if (size[rootX] > size[rootY]) {
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
        } else {
            parent[rootX] = rootY;
            size[rootY] += size[rootX];
        }
    }
};

vector<vector<int>> adjList(200005);

void solve() {
    int n, q;
    cin >> n >> q;
    
    UnionFind uf(n + 1);
    
    while (q--) {
        int type, v, k;
        cin >> type >> v;
        
        if (type == 1) {
            int u;
            cin >> u;
            uf.unite(u, v);
        } else {
            cin >> k;
            v--;
            
            // Get all connected nodes using BFS
            vector<bool> visited(n + 1, false);
            queue<int> q;
            q.push(v);
            visited[v] = true;
            vector<int> connectedNodes;
            
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                connectedNodes.push_back(node);
                
                for (int neighbor : adjList[node]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        q.push(neighbor);
                    }
                }
            }
            
            // Sort the connected nodes
            sort(connectedNodes.begin(), connectedNodes.end());
            
            // Find the k-th largest element
            if (k <= connectedNodes.size()) {
                cout << connectedNodes.back() - 1 << endl;
            } else {
                cout << "-1" << endl;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    solve();
    
    return 0;
}