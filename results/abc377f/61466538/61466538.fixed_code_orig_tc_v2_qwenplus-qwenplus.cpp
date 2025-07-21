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
    return 1 <= a.first && a.first <= n && 1 <= a.second && a.second <= n;
}

// F - Avoid Queen Attack
void solve() {
    ll n, m;
    re(n, m);
    set<pll> pieces;
    set<ll> rows, cols, diag1, diag2;

    for (ll i = 0; i < m; ++i) {
        ll a, b;
        re(a, b);
        pieces.insert({a, b});
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
    }

    ll total = n * n;
    // Subtract rows and columns
    total -= (ll)rows.size() * n;
    total -= (ll)cols.size() * n;
    // Add back intersections of row and column (double-counted)
    total += (ll)rows.size() * (ll)cols.size();

    // Now subtract diagonals of type i-j
    for (ll d : diag1) {
        ll count;
        if (d >= 0) {
            count = n - d;
        } else {
            count = n + d;
        }
        total -= count;
        // Remove already occupied squares on this diagonal
        for (ll r : rows) {
            ll c = r - d;
            if (1 <= c && c <= n)
                if (pieces.count({r, c})) total += 1;
        }
    }

    // Now subtract diagonals of type i+j
    for (ll d : diag2) {
        ll count;
        if (d <= n) {
            count = d - 1;
        } else {
            count = 2 * n - d + 1;
        }
        total -= count;
        // Remove already occupied squares on this diagonal
        for (ll r : rows) {
            ll c = d - r;
            if (1 <= c && c <= n)
                if (pieces.count({r, c})) total += 1;
        }
    }

    // Also check for overlap between the two diagonal sets
    set<pll> seen;
    for (ll d1 : diag1) {
        for (ll d2 : diag2) {
            // Solve:
            // i - j = d1
            // i + j = d2
            // => i = (d1 + d2)/2
            // => j = (d2 - d1)/2
            if ((d1 + d2) % 2 != 0) continue;
            ll i = (d1 + d2) / 2;
            ll j = (d2 - d1) / 2;
            if (1 <= i && i <= n && 1 <= j && j <= n) {
                if (!pieces.count({i, j})) {
                    if (!seen.count({i, j})) {
                        seen.insert({i, j});
                        total += 1;
                    }
                }
            }
        }
    }

    // Remove overlaps with rows and cols again
    for (auto [r, c] : pieces) {
        if (rows.count(r)) total += 1;
        if (cols.count(c)) total += 1;
        if (diag1.count(r - c)) total += 1;
        if (diag2.count(r + c)) total += 1;
    }

    cout << max(0LL, total);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    //cin >> t;
    while(t--) solve();
    return 0;
}