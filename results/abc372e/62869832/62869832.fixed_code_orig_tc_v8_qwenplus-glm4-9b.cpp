#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 200005;
vector<int> parent(MAX_N);
vector<vector<int>> components(MAX_N);

int find(int x) {
    if (parent[x] != x) parent[x] = find(parent[x]);
    return parent[x];
}

void unionSets(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY) {
        parent[rootY] = rootX;
        components[rootX].insert(components[rootX].end(), components[rootY].begin(), components[rootY].end());
        sort(components[rootX].rbegin(), components[rootX].rend());
        components[rootY].clear();
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
    }
    
    int u, v, k;
    
    for (int i = 0; i < q; ++i) {
        cin >> u >> v;
        
        if (u == 1 && v == 0) {
            break;
        }
        
        if (u == 1) {
            cin >> v;
            unionSets(u, v);
        } else if (u == 2) {
            cin >> v >> k;
            int root = find(v);
            if (k <= components[root].size()) {
                cout << components[root][k - 1] << endl;
            } else {
                cout << -1 << endl;
            }
        }
    }
    
    return 0;
}