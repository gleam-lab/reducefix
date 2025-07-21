#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

#define pb push_back
#define all(v) v.begin(), v.end()
#define sz(v) ((int)(v).size())

const int MAXN = 2 * (int)1e5 + 9;

// We use a Disjoint Set Union (Union-Find) structure with small modifications
class DSU {
public:
    vector<int> parent;
    vector<multiset<int>> components;

    DSU(int n) {
        parent.resize(n + 1);
        components.resize(n + 1);
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
            components[i].insert(i);  // Store actual values in descending order
        }
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int u, int v) {
        int root_u = find(u);
        int root_v = find(v);

        if (root_u == root_v)
            return;

        // Always merge smaller into larger for efficiency
        if (components[root_u].size() < components[root_v].size()) {
            swap(root_u, root_v);
        }

        // Merge the smaller component into the larger one
        for (int val : components[root_v]) {
            components[root_u].insert(val);
        }

        parent[root_v] = root_u;
    }
};

void solve() {
    int N, Q;
    cin >> N >> Q;

    DSU dsu(N);

    while (Q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int u, v;
            cin >> u >> v;
            dsu.unite(u, v);
        } else {
            int v, k;
            cin >> v >> k;
            int root = dsu.find(v);

            if (sz(dsu.components[root]) < k) {
                cout << -1 << endl;
            } else {
                // Get the k-th largest using reverse iterator
                auto it = dsu.components[root].rbegin();
                advance(it, k - 1);
                cout << *it << endl;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();

    return 0;
}