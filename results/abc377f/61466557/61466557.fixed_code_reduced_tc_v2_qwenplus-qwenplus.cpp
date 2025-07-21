#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

bool inBounds(const pll &a, const ll n) {
    return 1 <= a.first && a.first <= n && 1 <= a.second && a.second <= n;
}

// F - Avoid Queen Attack
void solve() {
    ll n, m;
    cin >> n >> m;
    vector<pll> q(m);
    for (ll i = 0; i < m; ++i) {
        cin >> q[i].first >> q[i].second;
    }

    set<ll> rows, cols, diag1, diag2;
    for (auto [i, j] : q) {
        rows.insert(i);
        cols.insert(j);
        diag1.insert(i - j);
        diag2.insert(i + j);
    }

    // Total squares attacked by queens
    ll attacked = 0;

    // Rows and columns cover entire grid when combined with diagonals
    // Count row and column coverage directly
    attacked += (ll)rows.size() * n;
    attacked += (ll)cols.size() * n;
    // Subtract overlap of rows and cols
    set<pair<ll, ll>> rc_overlap;
    for (ll r : rows) {
        for (ll c : cols) {
            rc_overlap.emplace(r, c);
        }
    }
    attacked -= (ll)rc_overlap.size();

    // Handle diagonal 1: i - j = d
    set<pll> d1_overlap;
    for (ll d : diag1) {
        ll cnt = max(0LL, min(n, n + d) - max(1LL, 1 + d) + 1);
        attacked += cnt;

        // Intersections with rows and columns
        for (ll r : rows) {
            pll p = {r, r - d};
            if (inBounds(p, n)) d1_overlap.insert(p);
        }
        for (ll c : cols) {
            pll p = {c + d, c};
            if (inBounds(p, n)) d1_overlap.insert(p);
        }
    }
    attacked -= (ll)d1_overlap.size();

    // Handle diagonal 2: i + j = d
    set<pll> d2_overlap;
    for (ll d : diag2) {
        ll cnt = (d <= n + n ? d <= n ? d - 1 : 2 * n - d + 1 : 0);
        attacked += cnt;

        // Intersections with rows and columns
        for (ll r : rows) {
            pll p = {r, d - r};
            if (inBounds(p, n)) d2_overlap.insert(p);
        }
        for (ll c : cols) {
            pll p = {d - c, c};
            if (inBounds(p, n)) d2_overlap.insert(p);
        }

        // Intersections with other diagonal
        for (ll d1 : diag1) {
            // Solve:
            // i + j = d
            // i - j = d1
            ll i = (d + d1) / 2;
            ll j = (d - d1) / 2;
            if ((d + d1) % 2 == 0 && (d - d1) % 2 == 0 && inBounds({i, j}, n)) {
                d2_overlap.insert({i, j});
            }
        }
    }
    attacked -= (ll)d2_overlap.size();

    // Total empty safe squares
    ll totalSafe = n * n - attacked - m;
    cout << totalSafe;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    while (t--) solve();
    return 0;
}