#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

const int MAXN = 2 * 100000 + 5;

int parent[MAXN];
multiset<int, greater<int>> components[MAXN];

// Find the root of a node with path compression
int find(int x, const vector<int>& parent) {
    if (parent[x] != x)
        return find(parent[x], parent);
    return x;
}

// Union by size to maintain balance
void unite(int x, int y, vector<int>& parent, multiset<int>& large_component) {
    int root_x = find(x, parent);
    int root_y = find(y, parent);

    if (root_x == root_y)
        return;

    // Always merge smaller into larger for better performance
    if (components[root_x].size() < components[root_y].size()) {
        swap(root_x, root_y);
    }

    // Merge components
    for (auto val : components[root_y]) {
        components[root_x].insert(val);
    }
    components[root_y].clear();

    // Update parent relationship
    parent[root_y] = root_x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    // Initialize DSU structure
    vector<int> parent(N+1);
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
            unite(u, v, parent, components[find(u, parent)]);
        } else {
            int v, k;
            cin >> v >> k;
            int root = find(v, parent);
            auto& comp = components[root];

            if ((int)comp.size() < k) {
                cout << -1 << "\n";
            } else {
                auto it = comp.begin();
                advance(it, k-1);
                cout << *it << "\n";
            }
        }
    }

    return 0;
}