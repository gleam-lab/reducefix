#include "bits/stdc++.h"

using namespace std;

#define ff first
#define ss second
#define ll long long
#define SZ(s) (int)s.size()

int const N = 2e5 + 5;
int const K_LIMIT = 100; // We'll keep at most K_LIMIT elements in each set

vector<int> parent(N);
vector<set<int>> components(N);

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

    // Always merge smaller into larger for better performance
    if (components[rootA].size() < components[rootB].size())
        swap(rootA, rootB);

    components[rootA].insert(components[rootB].begin(), components[rootB].end());
    parent[rootB] = rootA;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    parent.resize(n+1);
    components.resize(n+1);

    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        components[i].insert(i);
    }

    while (q--) {
        int t, a, b;
        cin >> t >> a >> b;
        if (t == 1) {
            unite(a, b);
        } else {
            int root = find(a);
            if (components[root].size() < b) {
                cout << -1 << '\n';
            } else {
                auto it = components[root].rbegin(); // reverse iterator for descending order
                for (int i = 1; i < b && it != components[root].rend(); ++i)
                    ++it;
                if (it == components[root].rend()) {
                    cout << -1 << '\n';
                } else {
                    cout << *it << '\n';
                }
            }
        }
    }

    return 0;
}