#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

int main() {
    ll N, M;
    cin >> N >> M;

    set<pll> placed;
    set<ll> rows, cols, diag1, diag2;

    for (ll i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        placed.insert({a, b});
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
    }

    // Total safe squares initially = total squares - occupied ones
    ll total_safe = N * N - M;

    // Subtract all cells attacked by existing pieces

    // Rows and columns already covered
    total_safe -= (N * rows.size());
    total_safe -= (N * cols.size());

    // Diagonals: a - b = c
    for (ll d : diag1) {
        ll count = 0;
        // Points on diagonal a - b = d
        if (d >= -(N - 1) && d <= N - 1) {
            count = N - abs(d);
        }
        total_safe -= count;
    }

    // Anti-diagonals: a + b = d
    for (ll d : diag2) {
        ll count = 0;
        // Points on anti-diagonal a + b = d
        if (d >= 2 && d <= 2 * N) {
            if (d <= N + 1)
                count = d - 1;
            else
                count = 2 * N + 1 - d;
        }
        total_safe -= count;
    }

    // Add back the intersections we subtracted multiple times

    // Intersections of row with column
    total_safe += rows.size() * cols.size();

    // Intersections of row with diag1
    for (ll r : rows) {
        for (ll d : diag1) {
            ll c = r - d;
            if (1 <= c && c <= N && !placed.count({r, c})) {
                total_safe += 1;
            }
        }
    }

    // Intersections of row with diag2
    for (ll r : rows) {
        for (ll d : diag2) {
            ll c = d - r;
            if (1 <= c && c <= N && !placed.count({r, c})) {
                total_safe += 1;
            }
        }
    }

    // Intersections of col with diag1
    for (ll c : cols) {
        for (ll d : diag1) {
            ll r = d + c;
            if (1 <= r && r <= N && !placed.count({r, c})) {
                total_safe += 1;
            }
        }
    }

    // Intersections of col with diag2
    for (ll c : cols) {
        for (ll d : diag2) {
            ll r = d - c;
            if (1 <= r && r <= N && !placed.count({r, c})) {
                total_safe += 1;
            }
        }
    }

    // Intersections of diag1 with diag2
    for (ll d1 : diag1) {
        for (ll d2 : diag2) {
            ll r = (d2 + d1) / 2;
            ll c = (d2 - d1) / 2;
            if ((d2 + d1) % 2 == 0 && (d2 - d1) % 2 == 0 &&
                1 <= r && r <= N &&
                1 <= c && c <= N &&
                !placed.count({r, c})) {
                total_safe += 1;
            }
        }
    }

    // Finally, subtract points that lie on both diagonals from diag1 and diag2
    for (ll d1 : diag1) {
        for (ll d2 : diag2) {
            ll r = (d2 + d1) / 2;
            ll c = (d2 - d1) / 2;
            if ((d2 + d1) % 2 == 0 && (d2 - d1) % 2 == 0 &&
                1 <= r && r <= N &&
                1 <= c && c <= N &&
                !placed.count({r, c})) {
                total_safe -= 1;
            }
        }
    }

    cout << max(0LL, total_safe) << endl;
    return 0;
}