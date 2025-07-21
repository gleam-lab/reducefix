#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll n, m;
vector<ll> rows, cols, diags1, diags2;

bool canCapture(ll x, ll y) {
    return 
        binary_search(rows.begin(), rows.end(), x) ||
        binary_search(cols.begin(), cols.end(), y) ||
        binary_search(diags1.begin(), diags1.end(), x + y) ||
        binary_search(diags2.begin(), diags2.end(), x - y);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    rows.resize(n + 1);
    cols.resize(n + 1);
    diags1.resize(2 * n + 1);
    diags2.resize(2 * n + 1);

    for (ll i = 1; i <= m; ++i) {
        ll x, y;
        cin >> x >> y;
        rows[x] = y;
        cols[y] = x;
        diags1[x + y] = y;
        diags2[x - y + n] = y;
    }

    sort(rows.begin() + 1, rows.end());
    sort(cols.begin() + 1, cols.end());
    sort(diags1.begin() + 1, diags1.end());
    sort(diags2.begin() + 1, diags2.end());

    ll count = 0;
    for (ll i = 1; i <= n; ++i) {
        for (ll j = 1; j <= n; ++j) {
            if (!canCapture(i, j)) {
                ++count;
            }
        }
    }

    cout << count << endl;

    return 0;
}