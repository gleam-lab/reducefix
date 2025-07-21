#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int N = 2e5 + 5;

vector<int> adj[N];
vector<int> size(N);
vector<int> rank(N, 0);
vector<int> parent(N);

void init(int n) {
    for (int i = 0; i <= n; ++i) {
        parent[i] = i;
        size[i] = 1;
    }
}

void find(int x) {
    if (x == parent[x]) return;
    parent[x] = find(parent[x]);
}

void merge(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY) {
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
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    init(n);
    while (q--) {
        int t, v, k;
        cin >> t >> v >> k;
        if (t == 1) {
            cin >> k;
            merge(v, k);
        } else {
            v = find(v);
            int count = 0;
            auto sorted = adj[v];
            sort(sorted.begin(), sorted.end(), greater<int>());
            for (int u : sorted) {
                if (find(u) == v) {
                    count++;
                    if (count == k) {
                        cout << u << '\n';
                        break;
                    }
                }
            }
            if (count < k) {
                cout << -1 << '\n';
            }
        }
    }

    return 0;
}