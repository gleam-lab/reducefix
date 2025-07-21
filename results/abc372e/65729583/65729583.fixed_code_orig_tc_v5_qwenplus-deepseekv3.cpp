#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const int MAXN = 2e5 + 5;
const int MAXK = 10;

int parent[MAXN];
int size[MAXN];
multiset<int> top[MAXN];

void init() {
    for (int i = 0; i < MAXN; ++i) {
        parent[i] = i;
        size[i] = 1;
        top[i].insert(-i); // Use negative to simulate max heap with multiset
    }
}

int find(int u) {
    if (parent[u] != u) {
        parent[u] = find(parent[u]);
    }
    return parent[u];
}

void mergeSets(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;

    if (size[u] < size[v]) {
        swap(u, v);
    }

    parent[v] = u;
    size[u] += size[v];

    for (auto it = top[v].begin(); it != top[v].end(); ++it) {
        top[u].insert(*it);
        if (top[u].size() > MAXK) {
            top[u].erase(top[u].begin());
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    init();

    int N, Q;
    cin >> N >> Q;

    while (Q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int u, v;
            cin >> u >> v;
            mergeSets(u, v);
        } else {
            int v, k;
            cin >> v >> k;
            v = find(v);
            if (top[v].size() < k) {
                cout << -1 << '\n';
            } else {
                auto it = top[v].rbegin();
                advance(it, k - 1);
                cout << -(*it) << '\n';
            }
        }
    }

    return 0;
}