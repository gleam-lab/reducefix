#include <iostream>
#include <set>

using namespace std;

typedef long long ll;

bool inBounds(ll a, ll n) {
    return 1 <= a && a <= n;
}

void solve() {
    ll n, m; cin >> n >> m;
    set<ll> rows, cols, diag, antidiag;
    
    for (ll i = 0; i < m; ++i) {
        ll a, b; cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag.insert(a + b);
        antidiag.insert(a - b);
    }
    
    ll total_squares = n * n;
    ll occupied_by_rows = rows.size() * n;
    ll occupied_by_cols = cols.size() * n;
    ll occupied_by_diag = diag.size() * n;
    ll occupied_by_antidiag = antidiag.size() * n;
    
    ll intersections = diag.size() + antidiag.size();
    
    ll answer = total_squares - occupied_by_rows - occupied_by_cols + intersections;
    
    cout << answer << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    while(t--) solve();
    return 0;
}