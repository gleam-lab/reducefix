#include <iostream>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef pair<ii, ii> iiii;

#define LINE cerr << " ------------------------------------------ " << endl
#define debug1(x) cerr << "? " << #x << " : " << x << endl
#define debug2(x, y) cerr << "? [ " << #x << " = " << x << " | " << #y << " = " << y << " ]" << endl
#define debug3(x, y, z) cerr << "? [ " << #x << " = " << x << " | " << #y << " = " << y << " | " << #z << " = " << z << " ]" << endl
#define debug4(x, y, z, w) cerr << "? [ " << #x << " = " << x << " | " << #y << " = " << y << " | " << #z << " = " << z << " | " << #w << " = " << w << " ]" << endl
#define debugPair(x) cerr << "? " << #x << ": ( " << x.first << " , " << x.second << " )" << endl
#define debugList(x) cerr << "? " << #x << ": "; for (auto it : x) cerr << it << " "; cerr << endl
#define debugIterablePairs(x) cerr << "? " << #x << " : { " << endl; for (auto it : x) cerr << "    " << it.first << " -> " << it.second << endl; cerr << "} " << endl
#define debugGraph(G) cerr << "? " << #G << " = { " << endl; int cntNodes = 0; for (auto adj : G) { if (adj.size()) { cerr << cntNodes << " => "; for (auto it : adj) cerr << it << " "; cerr << endl; } cntNodes++; } cerr << "}" << endl
#define debugMatrix(arr, F, C) cerr << "? " << #arr << endl; for (int i = 0; i < F; i++) { cerr << "[ "; for (int j = 0; j < C; j++) { cerr << arr[i][j] << " "; } cerr << "]" << endl; }

#define pb push_back
#define pf push_front
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

const int N = 2e5 + 9;
const int mod = 1e9 + 7;
const int inf = 2e9 + 9;
const ll modL = 1e9 + 7;
const ll infL = 2e18 + 9;
const double pi = acos(-1);

int U[N];
tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> V[N];

int Find(int u) {
    if (U[u] == u) return u;
    return U[u] = Find(U[u]);
}

void Union(int u, int v) {
    u = Find(u);
    v = Find(v);
    if (u == v) return;
    if (V[u].size() < V[v].size()) swap(u, v);
    U[v] = u;
    for (int num : V[v]) {
        V[u].insert(num);
    }
    V[v].clear();
}

void solve() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        U[i] = i;
        V[i].insert(-i); // Using negative to simulate descending order
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
            if (V[u].size() < k) {
                cout << -1 << endl;
            } else {
                cout << -(*V[u].find_by_order(k - 1)) << endl;
            }
        }
    }
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    solve();
    return 0;
}