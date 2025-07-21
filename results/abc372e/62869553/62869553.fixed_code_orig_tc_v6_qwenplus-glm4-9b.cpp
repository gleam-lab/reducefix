#include<bits/stdc++.h>
using namespace std;
int n, q;
vector<int> parent, size, rank;

int find_set(int x) {
    if (parent[x] != x) 
        parent[x] = find_set(parent[x]); // Path compression
    return parent[x];
}

void union_set(int x, int y) {
    int rootX = find_set(x);
    int rootY = find_set(y);
    
    if (rootX != rootY) {
        // Union by rank
        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
        } else if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
            size[rootY] += size[rootX];
        } else {
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
            rank[rootX]++;
        }
    }
}

int main() {
    cin >> n >> q;
    parent.resize(n + 1);
    size.resize(n + 1, 1);
    rank.resize(n + 1);

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    for (int i = 0; i < q; i++) {
        int op, u, v;
        cin >> op >> u >> v;

        if (op == 1) { // Add edge
            union_set(u, v);
        } else if (op == 2) { // Query k-th largest connected vertex
            int root = find_set(v);
            int total = size[root];
            if (k > total) {
                cout << -1 << endl;
            } else {
                // Output the (total-k+1)-th smallest element
                cout << v;
                for (int z = total - 1; z > total - k; z--) {
                    root = find_set(v);
                    total = size[root];
                    for (int x = 1; x <= n; x++) {
                        if (find_set(x) == root && size[x] > 0) {
                            v = x;
                            size[x]--;
                            total--;
                        }
                    }
                }
                cout << endl;
            }
        }
    }

    return 0;
}