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
    set<pll> occupied;
    set<ll> rows, cols, diag1, diag2;

    for (int i = 0; i < m; ++i) {
        pll pos;
        re(pos.fst, pos.snd);
        occupied.insert(pos);
        rows.insert(pos.fst);
        cols.insert(pos.snd);
        diag1.insert(pos.fst - pos.snd);
        diag2.insert(pos.fst + pos.snd);
    }

    ll total = n * n;
    // Subtract rows and columns
    total -= rows.size() * n;
    total -= cols.size() * n;
    total += rows.size() * cols.size(); // Overlap of row and column

    // For each diagonal of type i-j, count how many squares are attacked not already covered by rows or cols
    set<pll> attacked;

    for (ll d : diag1) {
        for (ll r : rows) {
            pll p = {r, r - d};
            if (inBounds(p, n)) attacked.insert(p);
        }
        for (ll c : cols) {
            pll p = {c + d, c};
            if (inBounds(p, n)) attacked.insert(p);
        }
        ll diag_len = (d >= -(n-1) && d <= n-1) ? (n - abs(d)) : 0;
        total -= diag_len;
    }

    for (ll d : diag2) {
        for (ll r : rows) {
            pll p = {r, d - r};
            if (inBounds(p, n)) attacked.insert(p);
        }
        for (ll c : cols) {
            pll p = {d - c, c};
            if (inBounds(p, n)) attacked.insert(p);
        }
        for (ll od : diag1) {
            ll i = (d + od);
            ll j = (d - od);
            if (i % 2 == 0 && j % 2 == 0) {
                i /= 2;
                j /= 2;
                pll p = {i, j};
                if (inBounds(p, n)) attacked.insert(p);
            }
        }
        ll diag_len;
        if (d >= 1 && d <= n)
            diag_len = d;
        else if (d > n && d <= 2*n)
            diag_len = 2*n - d + 1;
        else
            diag_len = 0;
        total -= diag_len;
    }

    // Add back overlaps
    total += attacked.size();

    // Remove the pieces themselves from count since they're not empty
    total -= m;

    cout << total << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    while(t--) solve();
    return 0;
}