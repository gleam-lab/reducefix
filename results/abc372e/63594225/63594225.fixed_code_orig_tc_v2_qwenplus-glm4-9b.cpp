#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int N = 200005;
vector<int> parent(N);
vector<int> size(N);

void init(int n) {
    for (int i = 0; i <= n; i++) {
        parent[i] = i;
        size[i] = 1;
    }
}

int find(int x) {
    if (parent[x] != x) parent[x] = find(parent[x]);
    return parent[x];
}

void unionSets(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY) {
        if (size[rootX] < size[rootY]) swap(rootX, rootY);
        parent[rootY] = rootX;
        size[rootX] += size[rootY];
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    init(n);

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
            int rootV = find(v);
            set<int> connectedVertices;
            for (int i = 1; i <= n; i++) {
                if (find(i) == rootV) {
                    connectedVertices.insert(i);
                }
            }
            if (connectedVertices.size() < k) {
                cout << -1 << endl;
            } else {
                auto it = connectedVertices.rbegin();
                advance(it, k - 1);
                cout << *it << endl;
            }
        }
    }

    return 0;
}