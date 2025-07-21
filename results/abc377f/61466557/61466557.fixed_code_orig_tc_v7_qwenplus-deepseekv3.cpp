#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll N, M;
    cin >> N >> M;

    set<ll> rows, cols, diag1, diag2;
    set<pair<ll, ll>> pieces;

    for (ll i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
        pieces.insert({a, b});
    }

    ll total = N * N;
    ll attacked = 0;

    // Rows and columns
    ll row_count = rows.size();
    ll col_count = cols.size();
    attacked += row_count * N;
    attacked += col_count * N;
    attacked -= row_count * col_count; // subtract intersections

    // Diagonals (i + j = d)
    for (ll d : diag1) {
        ll cnt;
        if (d <= N + 1) {
            cnt = d - 1;
        } else {
            cnt = 2 * N - d + 1;
        }
        attacked += cnt;
        
        // Subtract intersections with rows and columns
        for (ll r : rows) {
            ll c = d - r;
            if (c >= 1 && c <= N && pieces.count({r, c}) == 0) {
                attacked--;
            }
        }
        for (ll c : cols) {
            ll r = d - c;
            if (r >= 1 && r <= N && pieces.count({r, c}) == 0) {
                attacked--;
            }
        }
    }

    // Anti-diagonals (i - j = d)
    for (ll d : diag2) {
        ll cnt;
        if (d >= 0) {
            cnt = N - d;
        } else {
            cnt = N + d;
        }
        attacked += cnt;
        
        // Subtract intersections with rows and columns
        for (ll r : rows) {
            ll c = r - d;
            if (c >= 1 && c <= N && pieces.count({r, c}) == 0) {
                attacked--;
            }
        }
        for (ll c : cols) {
            ll r = c + d;
            if (r >= 1 && r <= N && pieces.count({r, c}) == 0) {
                attacked--;
            }
        }
    }

    // Now, subtract the original pieces (they are already counted in rows/cols/diags)
    attacked -= M;

    // Also, check intersections between diag1 and diag2
    set<pair<ll, ll>> diag_intersections;
    for (ll d1 : diag1) {
        for (ll d2 : diag2) {
            ll i = (d1 + d2) / 2;
            ll j = (d1 - d2) / 2;
            if ((d1 + d2) % 2 == 0 && (d1 - d2) % 2 == 0) {
                if (i >= 1 && i <= N && j >= 1 && j <= N) {
                    diag_intersections.insert({i, j});
                }
            }
        }
    }
    // Subtract the intersections that were added twice (once in diag1 and once in diag2)
    for (auto p : diag_intersections) {
        if (pieces.count(p) == 0) {
            attacked--;
        }
    }

    ll safe = total - attacked;
    cout << max(safe, 0LL) << endl;

    return 0;
}