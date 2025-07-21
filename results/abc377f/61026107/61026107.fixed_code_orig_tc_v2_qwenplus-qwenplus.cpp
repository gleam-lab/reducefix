#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct Point {
    ll x, y;
};

void solve() {
    ll n, m;
    cin >> n >> m;

    vector<Point> pieces(m);
    for (int i = 0; i < m; ++i) {
        cin >> pieces[i].x >> pieces[i].y;
    }

    // Sets to store attacked lines
    set<ll> rows, cols, diag1, diag2;
    // Set to store occupied squares
    set<pair<ll, ll>> occupied;

    for (const auto& p : pieces) {
        rows.insert(p.x);
        cols.insert(p.y);
        diag1.insert(p.x - p.y);
        diag2.insert(p.x + p.y);
        occupied.insert({p.x, p.y});
    }

    // Step 1: Count all attacked cells due to rows, cols, diag1, diag2
    set<pair<ll, ll>> attacked;

    // From rows
    for (ll r : rows) {
        for (ll c = 1; c <= n; ++c) {
            attacked.insert({r, c});
        }
    }

    // From cols
    for (ll c : cols) {
        for (ll r = 1; r <= n; ++r) {
            attacked.insert({r, c});
        }
    }

    // From diag1: i - j = k
    for (ll k : diag1) {
        ll lo = max(1LL, k + 1);
        ll hi = min(n, n + k);
        for (ll i = lo; i <= hi; ++i) {
            ll j = i - k;
            if (j >= 1 && j <= n) {
                attacked.insert({i, j});
            }
        }
    }

    // From diag2: i + j = k
    for (ll k : diag2) {
        ll lo = max(1LL, k - n);
        ll hi = min(n, k - 1);
        for (ll i = lo; i <= hi; ++i) {
            ll j = k - i;
            if (j >= 1 && j <= n) {
                attacked.insert({i, j});
            }
        }
    }

    // Remove occupied squares from attacked set
    for (auto p : occupied) {
        attacked.erase(p);
    }

    ll total_empty = n * n - m;
    ll safe_squares = total_empty - (attacked.size());

    cout << safe_squares << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}