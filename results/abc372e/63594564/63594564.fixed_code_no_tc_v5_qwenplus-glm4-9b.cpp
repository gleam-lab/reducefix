#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 200005;

vector<int> parent(N), size(N), sortedList(N);
int n, q;

function<int(int)> find = [&](int x) {
    if (parent[x] != x) parent[x] = find(parent[x]);
    return parent[x];
};

void unionSets(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        if (size[a] < size[b]) swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}

void query(int v, int k) {
    vector<int> connectedNodes;
    for (int i = 1; i <= n; ++i) {
        if (find(i) == find(v)) {
            connectedNodes.push_back(i);
        }
    }
    sort(connectedNodes.rbegin(), connectedNodes.rend());
    if (k > connectedNodes.size()) cout << -1 << '\n';
    else cout << connectedNodes[k - 1] << '\n';
}

int main() {
    cin >> n >> q;
    parent[0] = 0;
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        size[i] = 1;
        sortedList[i] = i;
    }
    while (q--) {
        int t, a, b;
        cin >> t >> a >> b;
        if (t == 1) {
            unionSets(a, b);
        } else {
            query(b, b);
        }
    }
    return 0;
}