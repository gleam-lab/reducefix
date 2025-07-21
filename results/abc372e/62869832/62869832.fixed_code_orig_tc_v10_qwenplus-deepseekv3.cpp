#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int MAXK = 10;

int parent[MAXN];
vector<int> components[MAXN];

int find(int u) {
    if (parent[u] != u) {
        parent[u] = find(parent[u]);
    }
    return parent[u];
}

void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;
    if (components[u].size() < components[v].size()) {
        swap(u, v);
    }
    parent[v] = u;
    components[u].insert(components[u].end(), components[v].begin(), components[v].end());
    components[v].clear();
    sort(components[u].rbegin(), components[u].rend());
    if (components[u].size() > MAXK) {
        components[u].resize(MAXK);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        components[i] = {i};
    }

    while (Q--) {
        int type, u, v;
        cin >> type >> u;
        if (type == 1) {
            cin >> v;
            merge(u, v);
        } else {
            int k;
            cin >> k;
            u = find(u);
            if (k > components[u].size()) {
                cout << "-1\n";
            } else {
                cout << components[u][k - 1] << "\n";
            }
        }
    }

    return 0;
}