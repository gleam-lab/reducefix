#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2 * 1e5 + 5;
vector<int> par(MAXN);
vector< vector<int> > vec(MAXN);
int find(int x) {
    if (par[x] != x) par[x] = find(par[x]);
    return par[x];
}

void unite(int x, int y) {
    int a = find(x), b = find(y);
    if (a != b) {
        par[b] = a;
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        par[i] = i;
    }
    int u, v;
    while (q--) {
        char type;
        cin >> type;
        if (type == '1') {
            cin >> u >> v;
            unite(u, v);
            vec[find(u)].push_back(v);
        } else {
            cin >> v >> u;
            vector<int> &conn = vec[find(v)];
            if (u <= conn.size()) {
                cout << conn[u - 1] << endl;
            } else {
                cout << -1 << endl;
            }
        }
    }
    return 0;
}