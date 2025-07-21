#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

bool inBounds(const pll &p, ll n) {
    return 1 <= p.first && p.first <= n && 1 <= p.second && p.second <= n;
}

void solve() {
    ll N, M;
    cin >> N >> M;

    set<pll> pieces;
    set<ll> rows, cols, diag1, diag2;

    for (ll i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        pieces.insert({a, b});
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
    }

    // Total squares under attack:
    // - All squares in the same row or column as any piece
    // - Diagonals intersecting with all pieces

    // We'll compute total attacked positions using inclusion-exclusion

    // Count of squares attacked by row or column
    ll attacked_by_row_or_col = N * (rows.size() + cols.size()) - (ll)rows.size() * (ll)cols.size();

    // Count of squares attacked via diagonal 1 (i-j)
    set<pll> attacked_diag1;
    for (ll d : diag1) {
        // Equation: i - j = d => j = i - d
        // Valid for i from max(1, d+1) to min(N, N+d)
        ll count = 0;
        if (d >= 0) {
            // j = i - d >= 1 => i >= d + 1
            ll start = max(1LL, d + 1);
            ll end = min(N, N + d);
            count = max(0LL, end - start + 1);
        } else {
            // d < 0
            // j = i - d <= N => i <= N + d
            ll start = max(1, -d + 1);
            ll end = min(N, N + d);
            count = max(0LL, end - start + 1);
        }
        // Subtract those already counted via row/col
        for (ll r : rows) {
            ll j = r - d;
            if (j >= 1 && j <= N) {
                attacked_diag1.insert({r, j});
            }
        }
        for (ll c : cols) {
            ll i = c + d;
            if (i >= 1 && i <= N) {
                attacked_diag1.insert({i, c});
            }
        }
        attacked_by_row_or_col += count;
    }

    // Count of squares attacked via diagonal 2 (i+j)
    set<pll> attacked_diag2;
    for (ll s : diag2) {
        // Equation: i + j = s => j = s - i
        // Valid when 1 <= i <= N and 1 <= s - i <= N
        ll count = 0;
        if (s <= N + 1) {
            ll start = max(1LL, s - N);
            ll end = min(N, s - 1);
            count = max(0LL, end - start + 1);
        } else {
            ll start = s - N;
            ll end = min(N, s - 1);
            count = max(0LL, end - start + 1);
        }
        // Subtract those already counted via row/col
        for (ll r : rows) {
            ll j = s - r;
            if (j >= 1 && j <= N) {
                attacked_diag2.insert({r, j});
            }
        }
        for (ll c : cols) {
            ll i = s - c;
            if (i >= 1 && i <= N) {
                attacked_diag2.insert({i, c});
            }
        }
        attacked_by_row_or_col += count;
    }

    // Now subtract overlaps between diagonals and row/col
    attacked_by_row_or_col -= attacked_diag1.size();
    attacked_by_row_or_col -= attacked_diag2.size();

    // Also need to check intersections between both diagonals
    set<pll> diag_intersection;
    for (ll d1 : diag1) {
        for (ll d2 : diag2) {
            // Solve:
            // i - j = d1
            // i + j = d2
            // => i = (d1 + d2) / 2
            // => j = (d2 - d1) / 2
            if ((d1 + d2) % 2 == 0) {
                ll i = (d1 + d2) / 2;
                ll j = (d2 - d1) / 2;
                if (inBounds({i, j}, N)) {
                    diag_intersection.insert({i, j});
                }
            }
        }
    }

    // Remove duplicates between diagonal 1 and diagonal 2
    attacked_by_row_or_col -= diag_intersection.size();

    // Finally, subtract all the actual pieces since they're not empty
    attacked_by_row_or_col -= M;

    // Compute number of safe squares
    ll total_empty = N * N - M;
    ll safe_squares = total_empty - attacked_by_row_or_col;

    cout << safe_squares << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}