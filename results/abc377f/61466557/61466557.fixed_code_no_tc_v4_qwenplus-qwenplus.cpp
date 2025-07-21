#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef tree<int, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define V vector
#define pb push_back
#define eb emplace_back
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define ROF(i, a, b) for (int i = (b)-1; i >= (a); --i)

template<typename T> void re(V<T> &x) { for(auto &a : x) re(a); }
template<typename T, typename... U> void re(T &t, U &...u) { cin >> t; re(u...); }

template<typename T> ostream& operator<<(ostream& out, const V<T> &x) {
    if (!x.empty()) {
        for (int i = 0; i < x.size() - 1; ++i) out << x[i] << " ";
        out << x.back();
    }
    return out;
}

bool inBounds(const pll &p, ll n) {
    return p.first >= 1 && p.first <= n && p.second >= 1 && p.second <= n;
}

void solve() {
    ll N, M;
    re(N, M);
    set<ll> rows, cols;
    set<ll> diag1, diag2; // diag1: i-j, diag2: i+j
    set<pll> occupied;

    for (int i = 0; i < M; ++i) {
        ll a, b;
        re(a, b);
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
        occupied.insert({a, b});
    }

    // Total squares not under attack
    ll totalSafeSquares = N * N;
    totalSafeSquares -= rows.size() * N; // Rows
    totalSafeSquares -= cols.size() * N; // Columns
    totalSafeSquares += rows.size() * cols.size(); // Overlap between rows and columns

    // Remove overlaps due to diagonal intersections with rows/cols
    auto computeDiagLength = [&](ll d, bool isSum) {
        if (isSum) {
            // i + j = d
            if (d < 1) return 0LL;
            if (d > 2 * N) return 0LL;
            return d <= N + 1 ? d - 1 : 2 * N - d + 1;
        } else {
            // i - j = d
            ll minVal = -N + 1, maxVal = N - 1;
            if (d < minVal || d > maxVal) return 0LL;
            return N - abs(d);
        }
    };

    // For each diagonal of the form i - j = d
    for (ll d : diag1) {
        ll diagCount = computeDiagLength(d, false);

        // Count how many cells on this diagonal are already excluded by rows or columns
        set<pll> overlapPoints;
        for (ll r : rows) {
            ll c = r - d;
            if (c >= 1 && c <= N) overlapPoints.insert({r, c});
        }
        for (ll c : cols) {
            ll r = c + d;
            if (r >= 1 && r <= N) overlapPoints.insert({r, c});
        }

        // Subtract diagonal length but add back overlaps that were double-counted
        totalSafeSquares -= diagCount;
        totalSafeSquares += overlapPoints.size();
    }

    // For each diagonal of the form i + j = d
    for (ll d : diag2) {
        ll diagCount = computeDiagLength(d, true);

        set<pll> overlapPoints;
        for (ll r : rows) {
            ll c = d - r;
            if (c >= 1 && c <= N) overlapPoints.insert({r, c});
        }
        for (ll c : cols) {
            ll r = d - c;
            if (r >= 1 && r <= N) overlapPoints.insert({r, c});
        }

        // Also consider overlaps with other diagonals
        for (ll od : diag1) {
            ll i = (d + od) / 2;
            ll j = (d - od) / 2;
            if ((d + od) % 2 == 0 && inBounds({i, j}, N)) {
                overlapPoints.insert({i, j});
            }
        }

        // Subtract diagonal length but add back overlaps that were double-counted
        totalSafeSquares -= diagCount;
        totalSafeSquares += overlapPoints.size();
    }

    // Finally subtract squares already occupied by pieces (which are not counted as safe)
    totalSafeSquares -= M;

    cout << totalSafeSquares << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}