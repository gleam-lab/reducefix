#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef tree<int, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define all(x) (x).begin(), (x).end()
#define pb push_back
#define FOR(i, a, b) for (ll i = (a); i < (b); ++i)

template<typename T> void re(T &x) { cin >> x; }
template<typename T, typename... U> void re(T &t, U&... u) { re(t); re(u...); }
template<typename T> void re(vector<T> &x) { for (auto &a : x) re(a); }

template<typename T> ostream& operator<<(ostream& out, const vector<T> &x) {
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
    ll n, m;
    re(n, m);
    vector<pll> pieces(m);
    set<pll> occupied;
    set<ll> rows, cols, diag1, diag2;

    for (ll i = 0; i < m; ++i) {
        ll a, b;
        re(a, b);
        pieces[i] = {a, b};
        occupied.insert({a, b});
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
    }

    ll total = n * n;

    // Subtract rows and columns (with inclusion-exclusion correction)
    total -= (ll)rows.size() * n;
    total -= (ll)cols.size() * n;
    total += (ll)rows.size() * (ll)cols.size();  // Overlap between rows and columns

    // Subtract anti-diagonals (i - j), add back overlaps
    for (ll d : diag1) {
        ll count = n - abs(d);
        total -= count;

        // Count overlaps with rows and columns
        set<pll> overlap;
        for (ll r : rows) {
            ll c = r - d;
            if (inBounds({r, c}, n)) overlap.insert({r, c});
        }
        for (ll c : cols) {
            ll r = c + d;
            if (inBounds({r, c}, n)) overlap.insert({r, c});
        }
        total += overlap.size();
    }

    // Subtract main diagonals (i + j), add back overlaps
    for (ll d : diag2) {
        ll count = (d <= n + 1) ? (d - 1) : (2 * n - d + 1);
        total -= count;

        // Count overlaps with rows, columns, and other diagonals
        set<pll> overlap;
        for (ll r : rows) {
            ll c = d - r;
            if (inBounds({r, c}, n)) overlap.insert({r, c});
        }
        for (ll c : cols) {
            ll r = d - c;
            if (inBounds({r, c}, n)) overlap.insert({r, c});
        }
        for (ll od : diag1) {
            ll i = (d + od) / 2;
            ll j = (d - od) / 2;
            if ((d + od) % 2 == 0 && inBounds({i, j}, n)) {
                overlap.insert({i, j});
            }
        }
        total += overlap.size();
    }

    // Also remove the positions already occupied by existing pieces
    total -= m;

    cout << total << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    //cin >> t;
    while (t--) solve();

    return 0;
}