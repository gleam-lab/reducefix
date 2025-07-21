#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define trav(a,x) for(auto&a:x)
#define sz(x) (int)(x).size()
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;

const int INF = 1e9+7;

void solve() {
    int n,m; cin >> n >> m;
    unordered_set<int> row, col, diag1, diag2;
    rep(i,0,m){
        int r,c; cin >> r >> c;
        row.insert(r-1);
        col.insert(c-1);
        diag1.insert(r-1+c-1);
        diag2.insert(r-1-c-1);
    }
    ll res = n*n - (sz(row)*n + sz(col)*n - sz(diag1)*n - sz(diag2)*n);
    cout << res << '\n';
}

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    srand(time(0));
    int t=1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}