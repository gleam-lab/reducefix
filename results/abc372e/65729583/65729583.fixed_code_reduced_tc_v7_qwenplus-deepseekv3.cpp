#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

const int MAXN = 2e5 + 5;
int parent[MAXN];
vector<int> components[MAXN];

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
    if (components[u].size() < components[v].size()) {
        swap(u, v);
    }
    parent[v] = u;
    components[u].insert(components[u].end(), components[v].begin(), components[v].end());
    components[v].clear();
    sort(components[u].begin(), components[u].end(), greater<int>());
    if (components[u].size() > 10) {
        components[u].resize(10);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        components[i] = {i};
    }

    while (Q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int u, v;
            cin >> u >> v;
            unite(u, v);
        } else {
            int v, k;
            cin >> v >> k;
            v = find(v);
            if (components[v].size() < k) {
                cout << -1 << '\n';
            } else {
                cout << components[v][k - 1] << '\n';
            }
        }
    }

    return 0;
}