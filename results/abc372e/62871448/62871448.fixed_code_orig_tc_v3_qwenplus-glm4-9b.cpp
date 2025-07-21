#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

int parent[MAXN], size[MAXN];

int find(int x) {
    if (parent[x] == x) return x;
    parent[x] = find(parent[x]); // Path compression
    return parent[x];
}

void unionSets(int u, int v) {
    int rootU = find(u);
    int rootV = find(v);
    
    if (rootU != rootV) {
        if (size[rootU] < size[rootV]) {
            parent[rootU] = rootV;
            size[rootV] += size[rootU];
        } else {
            parent[rootV] = rootU;
            size[rootU] += size[rootV];
        }
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        size[i] = 1;
    }
    
    vector<int> results;
    
    for (int i = 0; i < q; i++) {
        int op, u, v, k;
        cin >> op >> u >> v;
        
        if (op == 1) {
            unionSets(u, v);
        } else {
            int rootV = find(v);
            int kth = n - size[rootV] + k;
            if (kth > 0 && kth <= size[rootV]) {
                // Find the k-th largest vertex
                for (int j = n; j > 0; --j) {
                    if (find(j) == rootV) {
                        if (--kth == 0) {
                            results.push_back(j);
                            break;
                        }
                    }
                }
            } else {
                results.push_back(-1);
            }
        }
    }
    
    for (int result : results) {
        cout << result << '\n';
    }
    
    return 0;
}