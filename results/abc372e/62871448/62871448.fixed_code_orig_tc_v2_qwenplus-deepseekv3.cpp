#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2e5 + 5;
int parent[MAX_N];
int rank_[MAX_N];
vector<int> component[MAX_N];

int find(int u) {
    if (parent[u] != u) {
        parent[u] = find(parent[u]);
    }
    return parent[u];
}

void unite(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;

    if (rank_[u] > rank_[v]) {
        parent[v] = u;
        component[u].insert(component[u].end(), component[v].begin(), component[v].end());
        sort(component[u].rbegin(), component[u].rend());
        if (component[u].size() > 10) {
            component[u].resize(10);
        }
    } else {
        parent[u] = v;
        component[v].insert(component[v].end(), component[u].begin(), component[u].end());
        sort(component[v].rbegin(), component[v].rend());
        if (component[v].size() > 10) {
            component[v].resize(10);
        }
        if (rank_[u] == rank_[v]) {
            rank_[v]++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, Q;
    cin >> N >> Q;

    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        rank_[i] = 0;
        component[i].push_back(i);
    }

    while (Q--) {
        int type, u, v;
        cin >> type >> u;
        if (type == 1) {
            cin >> v;
            unite(u, v);
        } else {
            int k;
            cin >> k;
            int root = find(u);
            if (component[root].size() < k) {
                cout << "-1\n";
            } else {
                cout << component[root][k - 1] << "\n";
            }
        }
    }

    return 0;
}