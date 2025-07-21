#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const ll MAXN = 1e9 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m; cin >> n >> m;
    unordered_set<ll> rows, cols, diags1, diags2;

    for(ll i = 0; i < m; ++i) {
        ll x, y; cin >> x >> y;
        rows.insert(x);
        cols.insert(y);
        diags1.insert(x + y);
        diags2.insert(x - y);
    }

    ll total_squares = n * n;
    ll occupied_by_rows = rows.size() * n;
    ll occupied_by_cols = cols.size() * n;
    ll occupied_by_diags = diags1.size() * n + diags2.size() * n;

    ll subtracted = 2 * (rows.size() * cols.size());

    ll result = total_squares - occupied_by_rows - occupied_by_cols + subtracted - occupied_by_diags;
    cout << result << '\n';

    return 0;
}