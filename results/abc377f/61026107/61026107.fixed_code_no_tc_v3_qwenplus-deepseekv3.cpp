#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    ll n, m;
    cin >> n >> m;
    set<ll> rows, cols, diags1, diags2;
    set<pair<ll, ll>> pieces;

    for (int i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diags1.insert(a - b);
        diags2.insert(a + b);
        pieces.insert({a, b});
    }

    ll total = n * n - m;  // Total empty squares, subtracting existing pieces.

    ll unsafe = 0;

    // Squares covered by rows.
    unsafe += rows.size() * n;

    // Squares covered by columns.
    unsafe += cols.size() * n;

    // Squares covered by diags1 (i - j = constant)
    for (auto d : diags1) {
        ll x = max(1LL, 1 + d);
        ll y = max(1LL, 1 - d);
        ll cnt = min(n - x + 1, n - y + 1);
        if (x < 1 || y < 1) {
            cnt = min(n, n - abs(d));
        }
        unsafe += cnt;
    }

    // Squares covered by diags2 (i + j = constant)
    for (auto d : diags2) {
        ll x = max(1LL, d - n);
        ll y = max(1LL, d - n);
        ll cnt = min(n - x + 1, n - (d - x) + 1);
        if (d <= n + 1) {
            cnt = min(d - 1, n);
        } else {
            cnt = min(2 * n - d + 1, n);
        }
        unsafe += cnt;
    }

    // Subtract overlaps where squares are counted multiple times.
    // Squares covered by both rows and columns.
    for (auto r : rows) {
        for (auto c : cols) {
            if (pieces.count({r, c}) == 0) {
                unsafe--;
            }
        }
    }

    // Squares covered by both rows and diags1.
    for (auto r : rows) {
        for (auto d : diags1) {
            ll c = r - d;
            if (c >= 1 && c <= n && pieces.count({r, c}) == 0) {
                unsafe--;
            }
        }
    }

    // Squares covered by both rows and diags2.
    for (auto r : rows) {
        for (auto d : diags2) {
            ll c = d - r;
            if (c >= 1 && c <= n && pieces.count({r, c}) == 0) {
                unsafe--;
            }
        }
    }

    // Squares covered by both columns and diags1.
    for (auto c : cols) {
        for (auto d : diags1) {
            ll r = c + d;
            if (r >= 1 && r <= n && pieces.count({r, c}) == 0) {
                unsafe--;
            }
        }
    }

    // Squares covered by both columns and diags2.
    for (auto c : cols) {
        for (auto d : diags2) {
            ll r = d - c;
            if (r >= 1 && r <= n && pieces.count({r, c}) == 0) {
                unsafe--;
            }
        }
    }

    // Squares covered by both diags1 and diags2.
    for (auto d1 : diags1) {
        for (auto d2 : diags2) {
            if ((d1 + d2) % 2 != 0) continue;
            ll r = (d1 + d2) / 2;
            ll c = (d2 - d1) / 2;
            if (r >= 1 && r <= n && c >= 1 && c <= n && pieces.count({r, c}) == 0) {
                unsafe--;
            }
        }
    }

    // Squares covered by rows, columns, and diags1.
    for (auto r : rows) {
        for (auto c : cols) {
            ll d1 = r - c;
            if (diags1.count(d1) && pieces.count({r, c}) == 0) {
                unsafe++;
            }
        }
    }

    // Squares covered by rows, columns, and diags2.
    for (auto r : rows) {
        for (auto c : cols) {
            ll d2 = r + c;
            if (diags2.count(d2) && pieces.count({r, c}) == 0) {
                unsafe++;
            }
        }
    }

    // Squares covered by rows, diags1, and diags2.
    for (auto r : rows) {
        for (auto d1 : diags1) {
            ll c = r - d1;
            ll d2 = r + c;
            if (c >= 1 && c <= n && diags2.count(d2) && pieces.count({r, c}) == 0) {
                unsafe++;
            }
        }
    }

    // Squares covered by columns, diags1, and diags2.
    for (auto c : cols) {
        for (auto d1 : diags1) {
            ll r = c + d1;
            ll d2 = r + c;
            if (r >= 1 && r <= n && diags2.count(d2) && pieces.count({r, c}) == 0) {
                unsafe++;
            }
        }
    }

    // Squares covered by rows, columns, diags1, and diags2.
    for (auto r : rows) {
        for (auto c : cols) {
            ll d1 = r - c;
            ll d2 = r + c;
            if (diags1.count(d1) && diags2.count(d2) && pieces.count({r, c}) == 0) {
                unsafe--;
            }
        }
    }

    ll safe = total - unsafe;
    cout << safe << "\n";

    return 0;
}