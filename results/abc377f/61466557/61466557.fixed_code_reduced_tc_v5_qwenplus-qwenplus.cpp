#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;

bool inBounds(pll p, ll n) {
    return 1 <= p.first && p.first <= n && 1 <= p.second && p.second <= n;
}

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<pll> pieces(m);
    set<ll> rows, cols;
    set<ll> diag1, diag2; // diag1 = i-j, diag2 = i+j
    set<pll> occupied;

    for (int i = 0; i < m; ++i) {
        ll x, y;
        cin >> x >> y;
        pieces[i] = {x, y};
        rows.insert(x);
        cols.insert(y);
        diag1.insert(x - y);
        diag2.insert(x + y);
        occupied.insert({x, y});
    }

    ll total = n * n;
    ll attacked = 0;

    // Rows and Columns
    attacked += (ll)rows.size() * n;
    attacked += (ll)cols.size() * n;
    attacked -= (ll)rows.size() * cols.size(); // intersection

    // Diagonals: i - j
    for (ll d : diag1) {
        ll cnt;
        if (n + d <= 0 || d >= n) cnt = 0;
        else cnt = min(d, n - d); // error-prone estimation
        cnt = max(0LL, n - abs(d));
        attacked += cnt;
    }

    // Diagonals: i + j
    for (ll d : diag2) {
        ll cnt;
        if (d < 1 || d > 2 * n) cnt = 0;
        else if (d <= n + 1)
            cnt = d - 1;
        else
            cnt = 2 * n - d + 1;
        attacked += cnt;
    }

    // Overlaps between rows/cols and diagonals
    set<pll> overlap;
    for (ll r : rows) {
        for (ll c : cols) {
            overlap.insert({r, c});
        }
    }

    for (ll r : rows) {
        for (ll d : diag1) {
            ll j = r - d;
            if (1 <= j && j <= n)
                overlap.insert({r, j});
        }
        for (ll d : diag2) {
            ll j = d - r;
            if (1 <= j && j <= n)
                overlap.insert({r, j});
        }
    }

    for (ll c : cols) {
        for (ll d : diag1) {
            ll i = d + c;
            if (1 <= i && i <= n)
                overlap.insert({i, c});
        }
        for (ll d : diag2) {
            ll i = d - c;
            if (1 <= i && i <= n)
                overlap.insert({i, c});
        }
    }

    for (ll d1 : diag1) {
        for (ll d2 : diag2) {
            if ((d2 + d1) % 2 == 0) {
                ll i = (d1 + d2) / 2;
                ll j = (d2 - d1) / 2;
                if (inBounds({i, j}, n)) {
                    overlap.insert({i, j});
                }
            }
        }
    }

    // Remove overlaps (counted multiple times)
    attacked -= (ll)overlap.size();

    // Also remove already occupied squares
    attacked -= (ll)occupied.size();

    // Result
    cout << n * n - attacked << "\n";
}