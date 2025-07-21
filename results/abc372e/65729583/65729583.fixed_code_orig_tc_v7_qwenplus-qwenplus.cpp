#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 2 * 100000 + 5;

int parent[MAXN];
multiset<int, greater<int>> components[MAXN];

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void unite(int u, int v) {
    int rootU = find(u);
    int rootV = find(v);

    if (rootU == rootV) return;

    // Always merge smaller into larger for efficiency
    if (components[rootU].size() < components[rootV].size()) {
        swap(rootU, rootV);
    }

    for (int val : components[rootV]) {
        components[rootU].insert(val);
    }
    components[rootV].clear();

    parent[rootV] = rootU;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    // Initialize DSU and each component with its own value
    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        components[i].insert(i);
    }

    while (Q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int u, v;
            cin >> u >> v;
            unite(u, v);
        } else if (type == 2) {
            int v, k;
            cin >> v >> k;
            int root = find(v);
            auto it = components[root].begin();
            int cnt = 0;

            int result = -1;
            while (it != components[root].end() && cnt < k) {
                if (++cnt == k) {
                    result = *it;
                    break;
                }
                ++it;
            }

            cout << result << '\n';
        }
    }

    return 0;
}