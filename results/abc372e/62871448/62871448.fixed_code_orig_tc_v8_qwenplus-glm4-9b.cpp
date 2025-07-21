#include<bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
int parent[MAXN];

int find(int x) {
    if (parent[x] == x) return x;
    parent[x] = find(parent[x]);
    return parent[x];
}

void unionSets(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY) {
        if (rootX < rootY)
            parent[rootY] = rootX;
        else
            parent[rootX] = rootY;
    }
}

void kthLargest(int v, int k) {
    int root = find(v);
    vector<int> comp;
    for (int i = 1; i <= N; ++i) {
        if (find(i) == root) {
            comp.push_back(i);
        }
    }
    sort(comp.begin(), comp.end(), greater<int>());
    if (k > comp.size()) {
        cout << -1 << endl;
    } else {
        cout << comp[k - 1] << endl;
    }
}

int main() {
    int N, Q;
    cin >> N >> Q;
    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
    }
    while (Q--) {
        int type, x, y;
        cin >> type >> x >> y;
        if (type == 1) {
            unionSets(x, y);
        } else if (type == 2) {
            kthLargest(x, y);
        }
    }
    return 0;
}