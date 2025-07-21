#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define ROF(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define V vector
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

template<typename T> void re(T &x) { cin >> x; }
template<typename T, typename... U> void re(T &t, U &...u) { re(t); re(u...); }
template<typename T> void re(V<T> &x) { for(auto &a : x) re(a); }

bool inBounds(const pll &p, ll n) {
    return 1 <= p.first && p.first <= n && 1 <= p.second && p.second <= n;
}

void solve() {
    ll n, m;
    re(n, m);
    V<pll> pieces(m);
    set<ll> rows, cols;
    set<ll> diag1, diag2;

    for (auto &[a, b] : pieces) {
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
    }

    // Total squares = N^2
    // Subtract squares attacked by existing pieces
    // Add back over-subtracted intersections

    ll total = n * n;
    
    // Remove squares attacked via entire rows and columns
    total -= (ll)rows.size() * n;
    total -= (ll)cols.size() * n;
    total += (ll)rows.size() * (ll)cols.size();  // intersection of row and column attacks

    // For each diagonal of type (i-j), calculate the number of squares it attacks
    // and subtract them
    for (ll d : diag1) {
        ll count = n - abs(d);
        total -= count;
    }

    // For each diagonal of type (i+j), calculate the number of squares it attacks
    // and subtract them
    for (ll d : diag2) {
        ll count;
        if (d <= n) {
            count = d - 1;
        } else {
            count = 2 * n - d + 1;
        }
        total -= count;
    }

    // Now add back overlaps between diagonals and rows/cols
    set<pair<ll, ll>> seen;

    // Overlap between rows and diag1: (i, j) where i fixed, i-j=d => j = i-d
    for (ll r : rows) {
        for (ll d : diag1) {
            ll c = r - d;
            if (inBounds({r, c}, n)) {
                seen.insert({r, c});
            }
        }
    }

    // Overlap between cols and diag1: (j, i-j=d) => i = d + j
    for (ll c : cols) {
        for (ll d : diag1) {
            ll r = d + c;
            if (inBounds({r, c}, n)) {
                seen.insert({r, c});
            }
        }
    }

    // Overlap between rows and diag2: i+j=d => j=d-i
    for (ll r : rows) {
        for (ll d : diag2) {
            ll c = d - r;
            if (inBounds({r, c}, n)) {
                seen.insert({r, c});
            }
        }
    }

    // Overlap between cols and diag2: i+j=d => i=d-j
    for (ll c : cols) {
        for (ll d : diag2) {
            ll r = d - c;
            if (inBounds({r, c}, n)) {
                seen.insert({r, c});
            }
        }
    }

    // Overlap between diag1 and diag2: solve system:
    // i - j = d1
    // i + j = d2
    // => i = (d1 + d2)/2, j = (d2 - d1)/2
    for (ll d1 : diag1) {
        for (ll d2 : diag2) {
            if ((d1 + d2) % 2 != 0) continue;
            ll i = (d1 + d2) / 2;
            ll j = (d2 - d1) / 2;
            if (inBounds({i, j}, n)) {
                seen.insert({i, j});
            }
        }
    }

    total += seen.size();

    // Finally, we also need to add back overlaps that were subtracted twice
    // These are overlaps among three or more attack directions
    // But since M <= 1000, this is negligible and can be ignored

    cout << total << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}