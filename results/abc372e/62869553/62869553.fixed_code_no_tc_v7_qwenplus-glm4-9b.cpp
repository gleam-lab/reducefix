#include<bits/stdc++.h>
using namespace std;
int parent[200005];
int size[200005];

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

int merge(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY) {
        if (size[rootX] < size[rootY]) {
            parent[rootX] = rootY;
            size[rootY] += size[rootX];
        } else {
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
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

    while (q--) {
        int type, u, v, k;
        cin >> type >> u >> v;
        if (type == 1) {
            merge(u, v);
        } else if (type == 2) {
            int rootV = find(v);
            int count = 0;
            for (int i = n; i >= 1; i--) {
                if (find(i) == rootV) {
                    cout << i << "\n";
                    break;
                }
                count++;
                if (count >= k) {
                    cout << -1 << "\n";
                    break;
                }
            }
        }
    }

    return 0;
}