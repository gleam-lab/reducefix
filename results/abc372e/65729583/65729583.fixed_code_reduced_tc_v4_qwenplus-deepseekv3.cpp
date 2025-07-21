#include <iostream>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef pair<ii, ii> iiii;

#define LINE cerr << " ------------------------------------------ " << endl
#define debug1(x) cerr << "? " << #x << " : " << x << endl
#define debug2(x, y) cerr << "? [" << #x << " = " << x << " | " << #y << " = " << y << "]" << endl
#define debug3(x, y, z) cerr << "? [" << #x << " = " << x << " | " << #y << " = " << y << " | " << #z << " = " << z << "]" << endl
#define debug4(x, y, z, w) cerr << "? [" << #x << " = " << x << " | " << #y << " = " << y << " | " << #z << " = " << z << " | " << #w << " = " << w << "]" << endl
#define debugPair(x) cerr << "? " << #x << ": ( " << x.first << " , " << x.second << " )" << endl
#define printList(x) { for (auto val : x) { if (x.begin() != val) cout << " "; cout << val; } cout << endl; }
#define debugList(x) cerr << "? " << #x << ": "; if (x.empty()) { cerr << "[ ]"; } else { cerr << "[ "; for (auto it = x.begin(); it != x.end(); ++it) { if (it != x.begin()) cerr << " , "; cerr << *it; } cerr << " ]"; } cerr << endl
#define debugIterablePairs(x) cerr << "? " << #x << " : { " << endl; for (auto it : x) { cerr << "    " << it.first << " -> " << it.second << endl; } cerr << "}" << endl
#define debugGraph(x) cerr << "? " << #x << " = { " << endl; int cntNodes = 0; for (auto adj : x) { if (adj.size()) { cerr << "   " << cntNodes << " => "; debugList(adj); } cntNodes++; } cerr << "}" << endl
#define debugMatrix(x, r, c) cerr << "? " << #x << endl; for (int i = 0; i < r; i++) { cerr << "[ "; for (int j = 0; j < c; j++) { cerr << x[i][j] << " "; } cerr << "]" << endl; }

const int N = 2e5 + 9;
const int mod = 1e9 + 7;
const int inf = 2e9 + 9;
const ll modL = 1e9 + 7;
const ll infL = 2e18 + 9;
const double pi = acos(-1);

typedef tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int parent[N];
ordered_set vertices[N];

int Find(int u) {
    if (parent[u] == u) return u;
    return parent[u] = Find(parent[u]);
}

void Union(int u, int v) {
    u = Find(u);
    v = Find(v);
    if (u == v) return;
    if (vertices[u].size() < vertices[v].size()) swap(u, v);
    parent[v] = u;
    for (int num : vertices[v]) {
        vertices[u].insert(num);
    }
}

void solve() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        vertices[i].insert(i);
    }

    while (q--) {
        int cmd;
        cin >> cmd;
        if (cmd == 1) {
            int u, v;
            cin >> u >> v;
            Union(u, v);
        } else {
            int v, k;
            cin >> v >> k;
            int root = Find(v);
            if (vertices[root].size() < k) {
                cout << -1 << endl;
            } else {
                cout << *vertices[root].find_by_order(k - 1) << endl;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}