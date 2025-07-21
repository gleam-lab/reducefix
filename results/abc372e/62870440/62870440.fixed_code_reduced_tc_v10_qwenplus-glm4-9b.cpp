#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 200005;
int parent[MAX_N], size[MAX_N], rank[MAX_N];

void init(int n) {
    for (int i = 0; i <= n; i++) {
        parent[i] = i;
        size[i] = 1;
        rank[i] = 0;
    }
}

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void unionSets(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY) {
        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
        } else if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
            size[rootY] += size[rootX];
        } else {
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
            rank[rootX] += 1;
        }
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    init(n);

    vector<pair<int, int>> queries;
    for (int i = 0; i < q; i++) {
        int type, u, v;
        cin >> type >> u >> v;
        queries.push_back({type, u, v});
    }

    sort(queries.begin(), queries.end());

    vector<int> componentSize(n + 1, 0);
    vector<int> componentLeaders(n + 1);
    vector<vector<int>> components(n + 1);

    for (auto& q : queries) {
        if (q.first == 1) { // Union operation
            int u = q.second;
            int v = q.third;
            int rootU = find(u);
            int rootV = find(v);
            if (rootU != rootV) {
                componentSize[rootU] += componentSize[rootV];
                components[rootU].insert(end(components[rootU]), begin(components[rootV]), end(components[rootV]));
                components[rootU].push_back(max(u, v));
                components[rootV].clear();
                unionSets(u, v);
                componentLeaders[rootU] = max(componentLeaders[rootU], max(u, v));
            }
        } else if (q.first == 2) { // Find k-th largest
            int v = q.second;
            int k = q.third;
            int rootV = find(v);
            if (k > componentSize[rootV]) {
                cout << -1 << endl;
            } else {
                vector<int> sortedComponents = components[rootV];
                sort(sortedComponents.rbegin(), sortedComponents.rend());
                cout << sortedComponents[k - 1] << endl;
            }
        }
    }

    return 0;
}