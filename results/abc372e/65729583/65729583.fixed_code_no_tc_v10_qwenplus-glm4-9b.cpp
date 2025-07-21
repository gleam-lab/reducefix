#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

#define pb push_back
#define lb lower_bound
#define ub upper_bound

#define all(v) v.begin(),v.end() 
#define rall(v) v.rbegin(),v.rend()

#define ii    pair<int,int> 
#define iii   pair<int, ii>
#define iiii  pair<ii,ii>

#define ordered_set tree<ii, null_type,less<ii>, rb_tree_tag,tree_order_statistics_node_update> 
using namespace __gnu_pbds;

const int N    = 200100;
const int mod  = 1e9 + 7;
const int inf  = 2e9 + 9;
const ll modL = 1e9 + 7;
const ll infL = 2e18 + 9;
const double pi   = acos(-1);

const int K = 10;

int U[N];
vector<set<int>> G(N);

int Find(int u) {
    if (U[u] != u) {
        U[u] = Find(U[u]);
    }
    return U[u];
}

void Union(int u, int v) {
    u = Find(u);
    v = Find(v);
    if (u != v) {
        U[v] = u;
        G[u].insert({-v, G[v]});
        G[v].clear();
    }
}

void cumbia420PaLosCheems() {
    int n, q;
    cin >> n >> q;
    fill(U, U + n + 1, -1);

    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            int u, v;
            cin >> u >> v;
            Union(u, v);
        } else {
            int v, k;
            cin >> v >> k;
            v = Find(v);
            if (G[v].size() < k) {
                cout << -1 << endl;
            } else {
                cout << -G[v][k - 1].first << endl;
            }
        }
    }
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    cumbia420PaLosCheems();
    return 0;
}