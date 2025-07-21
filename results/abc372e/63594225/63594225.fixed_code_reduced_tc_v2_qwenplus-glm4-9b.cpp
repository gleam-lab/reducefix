#include "bits/stdc++.h"

using namespace std;

#define ll long long
#define N 200005

vector<int> adj[N];
vector<int> components;

int findComponents(int node, int component) {
    components.push_back(node);
    for (int child : adj[node]) {
        if (!components.count(child)) {
            findComponents(child, component);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    while (q--) {
        int query, u, v, k;
        cin >> query >> u >> v;

        if (query == 1) {
            if (!adj[u].count(v)) {
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        } else if (query == 2) {
            sort(components.begin(), components.end(), greater<int>());
            if (components.count(v)) {
                cout << components[v - 1] << '\n';
            } else {
                cout << "-1\n";
            }
        }
    }

    return 0;
}