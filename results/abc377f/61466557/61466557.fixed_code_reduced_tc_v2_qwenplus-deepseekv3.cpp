#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    cin >> n >> m;
    set<ll> rows, cols, diag1, diag2;
    set<pll> pieces;

    for (ll i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
        pieces.insert({a, b});
    }

    ll total = n * n;
    ll attacked = 0;

    // Squares attacked by rows or columns
    ll row_attacks = rows.size() * n;
    ll col_attacks = cols.size() * n;
    ll row_col_intersect = 0;
    for (ll r : rows) {
        for (ll c : cols) {
            if (pieces.count({r, c}) == 0) {
                row_col_intersect++;
            }
        }
    }
    attacked += row_attacks + col_attacks - row_col_intersect;

    // Squares attacked by diagonals (i-j)
    for (ll d : diag1) {
        ll cnt;
        if (d >= 0) {
            cnt = n - d;
        } else {
            cnt = n + d;
        }
        attacked += cnt;

        // Subtract intersections with rows and cols
        for (ll r : rows) {
            ll c = r - d;
            if (c >= 1 && c <= n && pieces.count({r, c}) == 0) {
                attacked--;
            }
        }
        for (ll c : cols) {
            ll r = c + d;
            if (r >= 1 && r <= n && pieces.count({r, c}) == 0) {
                attacked--;
            }
        }
    }

    // Squares attacked by diagonals (i+j)
    for (ll d : diag2) {
        ll cnt;
        if (d <= n + 1) {
            cnt = d - 1;
        } else {
            cnt = 2 * n - d + 1;
        }
        attacked += cnt;

        // Subtract intersections with rows and cols
        for (ll r : rows) {
            ll c = d - r;
            if (c >= 1 && c <= n && pieces.count({r, c}) == 0) {
                attacked--;
            }
        }
        for (ll c : cols) {
            ll r = d - c;
            if (r >= 1 && r <= n && pieces.count({r, c}) == 0) {
                attacked--;
            }
        }
    }

    // Add back squares attacked by both diagonals (intersection of diag1 and diag2)
    for (ll d1 : diag1) {
        for (ll d2 : diag2) {
            if ((d1 + d2) % 2 != 0) continue;
            ll r = (d2 + d1) / 2;
            ll c = (d2 - d1) / 2;
            if (r >= 1 && r <= n && c >= 1 && c <= n && pieces.count({r, c}) == 0) {
                attacked--;
            }
        }
    }

    ll safe = total - attacked - m + pieces.size();
    cout << safe << endl;

    return 0;
}