#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <ctime>

using namespace std;

const int N = 2e5 + 9;
const int mod = 1e9 + 7;

vector<int> graph[N];
set<int> nodes[N];

int Find(int u) {
    if (nodes[u].empty())
        return u;
    return Find(nodes[u].front());
}

void Union(int u, int v) {
    u = Find(u);
    v = Find(v);
    if (u != v) {
        nodes[v].insert(nodes[u].begin(), nodes[u].end());
        nodes[u].clear();
        nodes[u].insert(v);
        if (nodes[v].size() > 30) {
            nodes[v].resize(30);
        }
    }
}

void cumbia420PaLosCheems(int testCase) {
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        nodes[i].insert(-i);
    }

    int cmd, u, v, k;
    for (int i = 0; i < q; i++) {
        cin >> cmd;
        if (cmd == 1) {
            cin >> u >> v;
            Union(u, v);
        } else {
            cin >> u >> k;
            u = Find(u);
            if (nodes[u].size() < k) {
                cout << -1 << endl;
            } else {
                cout << -*(next(nodes[u].rbegin(), k - 1)) << endl;
            }
        }
    }
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t = 1;
    //cin >> t;
    while (t--) cumbia420PaLosCheems(t);
    return 0;
}