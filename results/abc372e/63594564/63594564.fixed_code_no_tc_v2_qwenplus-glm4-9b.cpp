#include <iostream>
#include <vector>
#include <set>

using namespace std;

#define ll long long

const int MAX_N = 2e5 + 5;

vector<int> parent(MAX_N + 1);
vector<set<int>> neighbors(MAX_N + 1);

void findSet(int x) {
    if (parent[x] != x) {
        parent[x] = findSet(parent[x]);
    }
    return parent[x];
}

void unionSets(int x, int y) {
    x = findSet(x);
    y = findSet(y);
    if (x != y) {
        if (neighbors[x].size() < neighbors[y].size()) {
            swap(x, y);
        }
        for (int neighbor : neighbors[y]) {
            neighbors[x].insert(neighbor);
        }
        neighbors[y].clear();
        parent[y] = x;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
    }

    while (q--) {
        int t, u, v;
        cin >> t >> u >> v;

        if (t == 1) {
            // Union operation
            unionSets(u, v);
        } else {
            // Find the representative of the set v is in
            int rep_v = findSet(v);
            // Get the set of neighbors for rep_v
            set<int> neighbors_of_v = neighbors[rep_v];
            if (t == 2) {
                // Find the k-th largest element
                int k;
                cin >> k;
                if (k > neighbors_of_v.size()) {
                    cout << -1 << '\n';
                } else {
                    // Output the k-th largest element
                    cout << *nextseen(neighbors_of_v.upper_bound(neighbors_of_v.begin()), k) << '\n';
                }
            }
        }
    }

    return 0;
}