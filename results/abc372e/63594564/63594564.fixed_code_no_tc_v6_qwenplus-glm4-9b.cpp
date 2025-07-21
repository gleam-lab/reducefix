#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 2e5 + 5;

vector<int> adj[MAX_N];
vector<int> size[MAX_N];
vector<int> order[MAX_N];
int rank[MAX_N];

void add_edge(int u, int v) {
    // Since it's undirected, add both directions
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int find(int v) {
    if (rank[v] < size[v]) {
        rank[v] = size[v];
        size[v] = min(size[v], size[size[v]]);
    }
    return v;
}

void union_sets(int u, int v) {
    int pu = find(u);
    int pv = find(v);

    if (pu != pv) {
        if (size[pu] < size[pv]) {
            swap(pu, pv);
        }
        if (rank[pu] == rank[pv]) {
            rank[pu]++;
        }
        order[pu].insert(order[pu].end(), order[pv].begin(), order[pv].end());
        order[pv].clear();
        size[pu] += size[pv];
    }
    order[pu].push_back(pu);
}

int kth_largest(int v, int k) {
    int root = find(v);
    if (k > size[root]) {
        return -1;
    }
    return order[root][size[root] - k];
}

int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 0; i <= n; ++i) {
        order[i].push_back(i);
        rank[i] = 1;
    }

    for (int i = 0; i < q; ++i) {
        int type, u, v, k;
        cin >> type >> u >> v;
        if (type == 1) {
            union_sets(u, v);
        } else {
            cout << kth_largest(v, k) << '\n';
        }
    }

    return 0;
}