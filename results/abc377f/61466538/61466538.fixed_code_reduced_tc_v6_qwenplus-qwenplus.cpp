#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<pll, ll> plll;
typedef pair<pll, pll> ppll;
typedef long double ld;
typedef tree<int,null_type,less<>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define V vector
#define fst first
#define snd second
#define ins insert
#define pb push_back
#define eb emplace_back
#define dbgs(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define ROF(i, a, b) for (int i = (b) - 1; i >= (a); --i)

template<typename T> void re(T &x) { cin >> x; }
template<typename T, typename ... U> void re(T &t, U &...u) { re(t); re(u...); }
template<typename T> void re(V<T> &x) { for(auto &a : x) re(a); }

template <typename T, typename V> ostream& operator<<(ostream& out, const pair<T, V> x) { out << "{" << x.fst << " : " << x.snd << "}"; return out; }
template <typename T> ostream& operator<<(ostream& out, const set<T> x) { for (auto& it : x) { out << it << " "; } return out; }
template <typename T> ostream& operator<<(ostream& out, const multiset<T> x) { for (auto& it : x) { out << it << " "; } return out; }
template <typename T, typename V> ostream& operator<<(ostream& out, const map<T, V> x) { for (auto& it : x) { out << "[" << it.fst << "]" << " = " << it.snd << "\n"; } return out; }
template <typename T> ostream& operator<<(ostream& out, const V<T> x) { if(!x.empty()) { for (int i = 0; i < x.size() - 1; ++i) { out << x[i] << " "; } out << x.back(); } return out; }
template <typename T> ostream& operator<<(ostream& out, const V<V<T>> x) { for (int i = 0; i < x.size() - 1; ++i) { out << "[" << i << "]" << " = {" << x[i] << "}\n"; } out << "[" << x.size() - 1 << "]" << " = {" << x.back() << "}\n"; return out; }

template <class T, class U> inline void chmin(T& a, U&& b) { if (b < a) { a = b; } }
template <class T, class U> inline void chmax(T& a, U&& b) { if (a < b) { a = b; } }
template <class T, class U, class V> inline void clip(T& v, U&& lower, V&& upper) { if (v < lower) { v = lower; } else if (v > upper) { v = upper; } }

bool inBounds(const pll &a, const ll n) {
    return 1 <= a.fst && a.fst <= n && 1 <= a.snd && a.snd <= n;
}

// F - Avoid Queen Attack
void solve() {
    ll n, m; re(n, m);
    vector<pii> q(m); FOR(i, 0, m) { re(q[i].fst, q[i].snd); }

    set<ll> row, col, diag1, diag2;
    set<pll> blocked;

    for (auto &[i, j] : q) {
        row.insert(i);
        col.insert(j);
        diag1.insert(i - j);
        diag2.insert(i + j);
        blocked.insert({i, j});
    }

    // Total squares: N^2
    ll total = n * n;

    // Subtract all squares attacked by any piece via row, column, or diagonal
    ll attacked = 0;

    // Rows and columns
    attacked += (ll)row.size() * n;
    attacked += (ll)col.size() * n;
    // Subtract overlaps: row ∩ col (squares where both a row and column intersect, i.e., pieces themselves)
    // Each piece is counted twice in above additions, so subtract them once
    attacked -= (ll)m;

    // Diagonals of type i-j
    for (ll d : diag1) {
        ll count;
        if (n + abs(d) - 1 <= n) {
            count = n - abs(d);
        } else {
            count = n - abs(d);
        }
        attacked += count;
    }

    // Diagonals of type i+j
    for (ll d : diag2) {
        ll count;
        if (d <= n)
            count = d - 1;
        else
            count = 2 * n - d + 1;
        attacked += count;
    }

    // Now subtract the overcounted intersections between rows/columns/diagonals
    // These are the actual occupied cells that were counted multiple times

    // Remove overcounts due to row-diag1 overlaps
    for (ll r : row) {
        for (ll d : diag1) {
            ll c = r - d;
            if (1 <= c && c <= n)
                blocked.insert({r, c});
        }
    }

    // Remove overcounts due to col-diag1 overlaps
    for (ll c : col) {
        for (ll d : diag1) {
            ll r = c + d;
            if (1 <= r && r <= n)
                blocked.insert({r, c});
        }
    }

    // Remove overcounts due to row-diag2 overlaps
    for (ll r : row) {
        for (ll d : diag2) {
            ll c = d - r;
            if (1 <= c && c <= n)
                blocked.insert({r, c});
        }
    }

    // Remove overcounts due to col-diag2 overlaps
    for (ll c : col) {
        for (ll d : diag2) {
            ll r = d - c;
            if (1 <= r && r <= n)
                blocked.insert({r, c});
        }
    }

    // Remove overcounts due to diag1-diag2 overlaps (intersection of diagonals)
    for (ll d1 : diag1) {
        for (ll d2 : diag2) {
            // Solve i - j = d1 and i + j = d2
            if ((d1 + d2) % 2 == 0) {
                ll i = (d2 + d1) / 2;
                ll j = (d2 - d1) / 2;
                if (1 <= i && i <= n && 1 <= j && j <= n)
                    blocked.insert({i, j});
            }
        }
    }

    // Adjust attacked count by removing overcounts
    ll total_unique_attacked = attacked - (blocked.size() - m);

    // Now subtract from total and output result
    ll ans = n * n - total_unique_attacked;
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    //cin >> t;
    while(t--) solve();
    return 0;
}