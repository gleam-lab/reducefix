#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef tree<int,null_type,less<>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define V vector
#define FOR(i, a, b) for (ll i = (a); i < (b); ++i)
#define ROF(i, a, b) for (ll i = (b)-1; i >= (a); --i)

template<typename T> void re(V<T> &x) { for(auto &a : x) cin >> a; }
template<typename T> void re(T &x) { cin >> x; }

bool inBounds(const pll &p, ll n) {
    return 1 <= p.first && p.first <= n && 1 <= p.second && p.second <= n;
}

// Function to compute number of squares on diagonal i+j=d within an N x N grid
ll diag_sum_count(ll d, ll n) {
    if (d <= n + 1) return d - 1;
    else return 2 * n - d + 1;
}

// Function to compute number of squares on diagonal i-j=d within an N x N grid
ll diag_diff_count(ll d, ll n) {
    return n - abs(d);
}

void solve() {
    ll n, m;
    re(n, m);

    set<ll> rows, cols;
    set<ll> diag_sum, diag_diff;

    set<pll> occupied;

    for (ll i = 0; i < m; ++i) {
        ll a, b;
        re(a, b);
        rows.insert(a);
        cols.insert(b);
        diag_sum.insert(a + b);
        diag_diff.insert(a - b);
        occupied.insert({a, b});
    }

    // Total squares available initially
    ll total = n * n;

    // Subtract all squares attacked by existing pieces
    // Use inclusion-exclusion principle

    // Rows and columns
    ll row_attack = rows.size() * n;
    ll col_attack = cols.size() * n;
    ll overlap_row_col = static_cast<ll>(rows.size()) * static_cast<ll>(cols.size());

    total -= (row_attack + col_attack - overlap_row_col);

    // Diagonal (i-j)
    for (ll d : diag_diff) {
        ll cnt = diag_diff_count(d, n);
        total -= cnt;
        
        // Add back overlaps with rows and columns
        for (ll r : rows) {
            ll c = r - d;
            if (c >= 1 && c <= n)
                total += 1;
        }
        for (ll c : cols) {
            ll r = c + d;
            if (r >= 1 && r <= n)
                total += 1;
        }
        // Remove double-counted overlaps
        for (ll r : rows) {
            ll c = r - d;
            if (c >= 1 && c <= n && cols.count(c))
                total -= 1;
        }
    }

    // Diagonal (i+j)
    for (ll d : diag_sum) {
        ll cnt = diag_sum_count(d, n);
        total -= cnt;

        // Add back overlaps with rows and columns
        for (ll r : rows) {
            ll c = d - r;
            if (c >= 1 && c <= n)
                total += 1;
        }
        for (ll c : cols) {
            ll r = d - c;
            if (r >= 1 && r <= n)
                total += 1;
        }

        // Remove double-counted overlaps
        for (ll r : rows) {
            ll c = d - r;
            if (c >= 1 && c <= n && cols.count(c))
                total -= 1;
        }

        // Add back overlaps with other diagonals (i-j)
        for (ll od : diag_diff) {
            // Solve: i+j = d, i-j = od => i = (d+od)/2, j = (d-od)/2
            if ((d + od) % 2 == 0) {
                ll i = (d + od) / 2;
                ll j = (d - od) / 2;
                if (inBounds({i, j}, n))
                    total += 1;
            }
        }
    }

    // Now subtract squares that are already occupied
    total -= m;

    cout << total << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    //cin >> t;
    while(t--) solve();
    return 0;
}