#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll mod = 1e9 + 7;

// Function to calculate power modulo m
ll qpow(ll a, ll b, ll m) {
    ll res = 1;
    while (b) {
        if (b & 1) (res *= a) %= m;
        (a *= a) %= m, b >>= 1;
    }
    return res;
}

// Function to calculate power
ll qpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

void solve() {
    ll n, m;
    cin >> n >> m;
    set<ll> h, v, d1, d2; // d1 stores diagonals i + j = d, d2 stores diagonals i - j = d

    for (int i = 1, x, y; i <= m; i++) {
        cin >> x >> y;
        h.insert(x);
        v.insert(y);
        d1.insert(x + y);
        d2.insert(x - y);
    }

    // Calculate initial number of empty squares
    ll ans = (n - h.size()) * (n - v.size());

    // Adjust for diagonals
    for (auto d : d1) {
        set<ll> s; // Set to keep track of unique lines intersecting the diagonal
        for (auto x : h) {
            if (1 <= d - x && d - x <= n) s.insert(d - x); // Horizontal line
        }
        for (auto y : v) {
            if (1 <= d - y && d - y <= n) s.insert(d - y); // Vertical line
        }
        ll len = d <= n ? d : n - (d - n) + 1; // Length of the diagonal
        ans = (ans + mod - (len - s.size())) % mod; // Update answer
    }

    for (auto d : d2) {
        set<ll> s; // Set to keep track of unique lines intersecting the diagonal
        for (auto x : h) {
            if (1 <= x - d && x - d <= n) s.insert(x - d); // Horizontal line
        }
        for (auto y : v) {
            if (1 <= d + y && d + y <= n) s.insert(d + y); // Vertical line
        }
        ll len = d >= 0 ? d : n - (1 - d) + 1; // Length of the diagonal
        ans = (ans + mod - (len - s.size())) % mod; // Update answer
    }

    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int _ = 1;
    while (_--) {
        solve();
    }

    return 0;
}