#include <bits/stdc++.h>

using namespace std;

#define ff first
#define ss second
#define ll long long
#define SZ(s) (int)(s).size()

const int N = 2e5 + 5;

vector<set<int>> components;
vector<int> parent;

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int a, int b) {
    int rootA = find(a);
    int rootB = find(b);
    
    if (rootA == rootB)
        return;

    // Always merge smaller component into the larger one
    if (components[rootA].size() < components[rootB].size())
        swap(rootA, rootB);

    // Merge component B into A
    for (int node : components[rootB]) {
        components[rootA].insert(node);
        parent[node] = rootA;
    }
    // Clear B's set to save space
    components[rootB].clear();
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    components.resize(n + 1);
    parent.resize(n + 1);

    // Initialize each node as its own component
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        components[i].insert(i);
    }

    while (q--) {
        int t;
        cin >> t;

        if (t == 1) {
            int u, v;
            cin >> u >> v;
            unite(u, v);
        } else {
            int v, k;
            cin >> v >> k;
            int root = find(v);
            
            // We want the k-th largest in descending order
            if (SZ(components[root]) < k) {
                cout << -1 << '\n';
            } else {
                auto it = components[root].rbegin(); // reverse iterator for descending
                advance(it, k - 1);
                cout << *it << '\n';
            }
        }
    }

    return 0;
}