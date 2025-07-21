#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int parent[200005];
int rank[200005];

int find(int v) {
    if (parent[v] != v) {
        parent[v] = find(parent[v]);
    }
    return parent[v];
}

void merge(int u, int v) {
    int root_u = find(u);
    int root_v = find(v);
    if (root_u != root_v) {
        if (rank[root_u] > rank[root_v]) {
            parent[root_v] = root_u;
        } else if (rank[root_u] < rank[root_v]) {
            parent[root_u] = root_v;
        } else {
            parent[root_v] = root_u;
            rank[root_u] += 1;
        }
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
    while (q--) {
        int type, u, v, k;
        cin >> type >> u >> v;
        if (type == 1) {
            merge(u, v);
        } else {
            int root = find(u);
            vector<int> connected;
            for (int i = 1; i <= n; i++) {
                if (find(i) == root) {
                    connected.push_back(i);
                }
            }
            sort(connected.begin(), connected.end(), greater<int>());
            if (k > connected.size()) {
                cout << "-1\n";
            } else {
                cout << connected[k - 1] << "\n";
            }
        }
    }
    return 0;
}