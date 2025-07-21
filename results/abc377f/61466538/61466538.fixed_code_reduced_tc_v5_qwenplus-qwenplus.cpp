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
    set<pll> pieces;
    set<ll> rows, cols, diag1, diag2;

    for (int i = 0; i < m; ++i) {
        ll a, b;
        re(a, b);
        pieces.insert({a, b});
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
    }

    // Total number of squares not attacked by existing piece's row or column
    ll total = n * n;
    total -= (ll)rows.size() * n;
    total -= (ll)cols.size() * n;
    total += (ll)rows.size() * (ll)cols.size();  // subtract overlap

    // For each diagonal of the form i - j = d
    set<pll> blocked;
    for (ll d : diag1) {
        ll cnt = max(0LL, n - abs(d)) - ((abs(d) % 2 == ((d + n) % 2)) ? 0 : 0);
        total -= cnt;
        // Count overlapping positions with rows and columns
        blocked.clear();
        for (ll r : rows) {
            ll c = r - d;
            if (1 <= c && c <= n)
                blocked.insert({r, c});
        }
        for (ll c : cols) {
            ll r = c + d;
            if (1 <= r && r <= n)
                blocked.insert({r, c});
        }
        total += (ll)blocked.size();
    }

    // For each diagonal of the form i + j = d
    for (ll d : diag2) {
        ll cnt = d <= n ? (d - 1) : (2 * n - d + 1);
        total -= cnt;
        // Count overlapping positions with rows and columns
        blocked.clear();
        for (ll r : rows) {
            ll c = d - r;
            if (1 <= c && c <= n)
                blocked.insert({r, c});
        }
        for (ll c : cols) {
            ll r = d - c;
            if (1 <= r && r <= n)
                blocked.insert({r, c});
        }
        // Count overlaps with diag1 intersections
        for (ll od : diag1) {
            // Solve:
            // i + j = d
            // i - j = od
            // => i = (d + od)/2, j = (d - od)/2
            if ((d + od) % 2 == 0) {
                ll i = (d + od) / 2;
                ll j = (d - od) / 2;
                if (1 <= i && i <= n && 1 <= j && j <= n)
                    blocked.insert({i, j});
            }
        }
        total += (ll)blocked.size();
    }

    // Now subtract the exact number of pieces (they are occupied)
    total -= m;

    cout << total << '\n';
}