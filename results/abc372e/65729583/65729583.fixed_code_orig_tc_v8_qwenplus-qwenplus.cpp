#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define pb push_back
#define pf push_front
#define lb lower_bound
#define ub upper_bound

#define all(v) v.begin(),v.end() 
#define rall(v) v.rbegin(),v.rend()

const int N = 2 * 1e5 + 9;

int U[N];
set<int> V[N];

int Find(int u) {
    if (U[u] == u) return u;
    return U[u] = Find(U[u]);
}

void Union(int u, int v) {
    u = Find(u);
    v = Find(v);
    if (u == v) return;

    // Always merge smaller set into larger to maintain efficiency
    if (V[u].size() < V[v].size()) swap(u, v);

    // Merge v's elements into u
    for (int num : V[v]) {
        V[u].insert(num);
        if (V[u].size() > 10) break; // Keep only top 10 largest nodes
    }
    V[v].clear();
    U[v] = u;
}

void cumbia420PaLosCheems(int testCase) {
    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; ++i) {
        V[i].insert(i); // Initially each node is its own component
    }

    for (int i = 1; i <= n; ++i) {
        U[i] = i;
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
            if ((int)V[root].size() < k) {
                cout << -1 << endl;
            } else {
                auto it = V[root].end();
                advance(it, -k);
                cout << *it << endl;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--) {
        cumbia420PaLosCheems(1);
    }
    return 0;
}