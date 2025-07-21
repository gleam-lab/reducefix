#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll N, M;
    cin >> N >> M;
    vector<pair<ll, ll>> queens(M);
    set<ll> rows, cols, diag1, diag2;
    for (ll i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        queens[i] = {a, b};
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
    }

    ll total = N * N;
    
    // Subtract squares attacked by rows or columns
    ll row_attacked = rows.size() * N;
    ll col_attacked = cols.size() * N;
    ll both_row_col = rows.size() * cols.size();
    total -= row_attacked + col_attacked - both_row_col;

    // Subtract squares attacked by diagonals (i - j)
    for (auto d : diag1) {
        ll cnt;
        if (d >= 0) {
            cnt = N - d;
        } else {
            cnt = N + d;
        }
        total -= cnt;
    }

    // Subtract squares attacked by diagonals (i + j)
    for (auto d : diag2) {
        ll cnt;
        if (d <= N + 1) {
            cnt = d - 1;
        } else {
            cnt = 2 * N - d + 1;
        }
        total -= cnt;
    }

    // Add back squares subtracted multiple times (intersections of rows/columns/diagonals)
    set<pair<ll, ll>> intersections;
    for (auto queen : queens) {
        intersections.insert(queen);
    }

    for (auto d1 : diag1) {
        for (auto r : rows) {
            ll c = r - d1;
            if (c >= 1 && c <= N) {
                intersections.insert({r, c});
            }
        }
        for (auto c : cols) {
            ll r = c + d1;
            if (r >= 1 && r <= N) {
                intersections.insert({r, c});
            }
        }
    }

    for (auto d2 : diag2) {
        for (auto r : rows) {
            ll c = d2 - r;
            if (c >= 1 && c <= N) {
                intersections.insert({r, c});
            }
        }
        for (auto c : cols) {
            ll r = d2 - c;
            if (r >= 1 && r <= N) {
                intersections.insert({r, c});
            }
        }
    }

    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            ll a = (d1 + d2);
            if (a % 2 != 0) continue;
            ll r = a / 2;
            ll c = (d2 - d1) / 2;
            if (r >= 1 && r <= N && c >= 1 && c <= N) {
                intersections.insert({r, c});
            }
        }
    }

    total += intersections.size();
    
    cout << total << endl;
    return 0;
}