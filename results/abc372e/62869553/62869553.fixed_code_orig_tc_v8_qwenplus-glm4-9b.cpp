#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 200005;
const int MAX_K = 10;

int parent[MAX_N];
vector<int> ranks(MAX_N), elements[MAX_N], topK[MAX_N];

void initialize(int n) {
    fill(parent, parent + n + 1, -1);
    for (int i = 1; i <= n; i++) {
        ranks[i] = 0;
        elements[i].push_back(i);
    }
}

int find(int x) {
    if (parent[x] == -1) return x;
    parent[x] = find(parent[x]);
    return parent[x];
}

void unionSets(int u, int v) {
    int rootU = find(u);
    int rootV = find(v);
    if (rootU != rootV) {
        if (ranks[rootU] > ranks[rootV]) {
            parent[rootV] = rootU;
            elements[rootU].insert(elements[rootU].end(), elements[rootV].begin(), elements[rootV].end());
            elements[rootV].clear();
        } else if (ranks[rootU] < ranks[rootV]) {
            parent[rootU] = rootV;
            elements[rootV].insert(elements[rootV].end(), elements[rootU].begin(), elements[rootU].end());
            elements[rootU].clear();
        } else {
            parent[rootV] = rootU;
            ranks[rootU]++;
            elements[rootU].insert(elements[rootU].end(), elements[rootV].begin(), elements[rootV].end());
            elements[rootV].clear();
        }
    }
}

int kthLargest(int v, int k) {
    int rootV = find(v);
    if (k > topK[rootV].size()) return -1;
    return topK[rootV][k - 1];
}

int main() {
    int n, q;
    cin >> n >> q;
    initialize(n);

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int u, v;
            cin >> u >> v;
            unionSets(u, v);
        } else {
            int v, k;
            cin >> v >> k;
            cout << kthLargest(v, k) << endl;
        }
    }

    return 0;
}