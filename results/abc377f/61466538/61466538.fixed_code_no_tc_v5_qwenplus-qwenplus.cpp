#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x) (x).begin(), (x).end()
#define FOR(i, a, b) for (ll i = (a); i < (b); ++i)

set<ll> row, col;
set<pll> blocked;
ll n, m;

// Check if (x, y) is on the diagonal or anti-diagonal of any piece
bool isCaptured(ll x, ll y) {
    if (row.count(x) || col.count(y)) return true;
    if (blocked.count({x, y})) return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    row.clear();
    col.clear();
    blocked.clear();

    for (ll i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        row.insert(a);
        col.insert(b);
        blocked.insert({a, b});
    }

    // We will compute how many squares are attacked using inclusion-exclusion
    // Total attacked = rows + columns + diagonals + anti-diagonals - overlaps

    ll total_squares = n * n;

    // Count total squares attacked by all pieces via rows and columns
    ll attacked_by_row = row.size() * n;
    ll attacked_by_col = col.size() * n;
    ll attacked_by_row_and_col = row.size() * col.size(); // overlap between row and column

    ll ans = total_squares;
    ans -= attacked_by_row;
    ans -= attacked_by_col;
    ans += attacked_by_row_and_col;

    // Now handle diagonals: i - j = constant
    set<ll> diag1;
    for (auto &p : blocked) {
        diag1.insert(p.first - p.second);
    }

    // For each diagonal (i-j), count number of squares on it and subtract
    for (auto d : diag1) {
        ll cnt;
        if (n % 2 == 0) {
            if (abs(d) <= n - 1) {
                cnt = n - abs(d);
            } else {
                cnt = 2 * n - abs(d) - 1;
            }
        } else {
            if (abs(d) <= n - 1) {
                cnt = n - abs(d);
            } else {
                cnt = 2 * n - abs(d) - 1;
            }
        }

        // Subtract all squares on this diagonal
        ans -= cnt;

        // Add back the ones that are already covered by row/col or both
        set<pll> overlap;
        for (auto r : row) {
            ll j = r - d;
            if (1 <= j && j <= n) {
                overlap.insert({r, j});
            }
        }
        for (auto c : col) {
            ll i = c + d;
            if (1 <= i && i <= n) {
                overlap.insert({i, c});
            }
        }
        ans += overlap.size();
    }

    // Now handle anti-diagonals: i + j = constant
    set<ll> diag2;
    for (auto &p : blocked) {
        diag2.insert(p.first + p.second);
    }

    for (auto s : diag2) {
        ll cnt;
        if (s >= 2 && s <= n + 1) {
            cnt = s - 1;
        } else {
            cnt = 2 * n + 1 - s;
        }

        ans -= cnt;

        set<pll> overlap;
        for (auto r : row) {
            ll j = s - r;
            if (1 <= j && j <= n) {
                overlap.insert({r, j});
            }
        }
        for (auto c : col) {
            ll i = s - c;
            if (1 <= i && i <= n) {
                overlap.insert({i, c});
            }
        }
        for (auto d1 : diag1) {
            // Solve i+j=s and i-j=d1 => i=(s+d1)/2, j=(s-d1)/2
            ll i = (s + d1) / 2;
            ll j = (s - d1) / 2;
            if ((s + d1) % 2 == 0 && (s - d1) % 2 == 0 && 1 <= i && i <= n && 1 <= j && j <= n) {
                overlap.insert({i, j});
            }
        }

        ans += overlap.size();
    }

    // Subtract the M squares that are already occupied
    ans -= m;

    cout << ans << endl;

    return 0;
}