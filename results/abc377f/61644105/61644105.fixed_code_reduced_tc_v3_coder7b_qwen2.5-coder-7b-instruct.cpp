#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;

int main() {
    ll n, m;
    cin >> n >> m;

    vector<ll> rows(m), cols(m), ups(m), downs(m);

    for (ll i = 0; i < m; ++i) {
        ll x, y;
        cin >> x >> y;
        rows[i] = y;
        cols[i] = x;
        ups[i] = y - x;
        downs[i] = x + y;
    }

    sort(rows.begin(), rows.end());
    sort(cols.begin(), cols.end());
    sort(ups.begin(), ups.end());
    sort(downs.begin(), downs.end());

    ll total_positions = n * n;
    ll invalid_positions = 0;

    // Count positions in rows
    for (ll i = 0; i < m; ++i) {
        invalid_positions += n - (rows[i] == rows.back() ? 0 : n - upper_bound(rows.begin(), rows.end(), rows[i]) + 1);
    }

    // Count positions in columns
    for (ll i = 0; i < m; ++i) {
        invalid_positions += n - (cols[i] == cols.back() ? 0 : n - upper_bound(cols.begin(), cols.end(), cols[i]) + 1);
    }

    // Count positions in upward diagonals
    for (ll i = 0; i < m; ++i) {
        invalid_positions += n - (ups[i] == ups.back() ? 0 : n - upper_bound(ups.begin(), ups.end(), ups[i]) + 1);
    }

    // Count positions in downward diagonals
    for (ll i = 0; i < m; ++i) {
        invalid_positions += n - (downs[i] == downs.back() ? 0 : n - upper_bound(downs.begin(), downs.end(), downs[i]) + 1);
    }

    cout << total_positions - invalid_positions << endl;

    return 0;
}