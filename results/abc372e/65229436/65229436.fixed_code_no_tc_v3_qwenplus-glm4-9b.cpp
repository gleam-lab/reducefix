#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
using ll = long long;

const int MAX_N = 2e5 + 5;

vector<int> parent(MAX_N);
vector<int> rank(MAX_N);
vector<int> size(MAX_N);

int findRoot(int x) {
    if (parent[x] != x) {
        parent[x] = findRoot(parent[x]);
    }
    return parent[x];
}

void unite(int x, int y) {
    x = findRoot(x);
    y = findRoot(y);
    if (x == y) return;
    if (rank[x] > rank[y]) {
        parent[y] = x;
        size[x] += size[y];
    } else {
        parent[x] = y;
        size[y] += size[x];
        if (rank[x] == rank[y]) {
            rank[y]++;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;

    rep(i, n) {
        parent[i] = i;
        size[i] = 1;
        rank[i] = 0;
    }

    vector<int> answers;
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int u, v;
            cin >> u >> v;
            unite(u, v);
        } else {
            int v, k;
            cin >> v >> k;
            int root = findRoot(v);
            if (size[root] < k) {
                answers.push_back(-1);
            } else {
                // Select the k-th largest element
                auto it = upper_bound(size.begin(), size.end(), size[root] - k + 1);
                answers.push_back(*it - 1); // -1 because we are using 0-based index
            }
        }
    }

    for (int ans : answers) {
        cout << ans + 1 << endl;
    }

    return 0;
}