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

    set<ll> rows, cols, diag1, diag2;
    set<pll> occupied;
    for (auto &[a, b] : q) {
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
        occupied.insert({a, b});
    }

    ll total = n * n;
    // Subtract rows and columns
    total -= (ll)rows.size() * n;
    total -= (ll)cols.size() * n;
    // Add back intersection of rows and columns
    total += (ll)rows.size() * (ll)cols.size();

    // Subtract diagonals
    for (ll d : diag1) {
        ll cnt;
        if (d >= 1 - n && d <= n - 1) {
            if (d <= 0) {
                cnt = n + d;
            } else {
                cnt = n - d;
            }
        } else {
            cnt = 0;
        }
        total -= cnt;
    }

    for (ll d : diag2) {
        ll cnt;
        if (d >= 2 && d <= 2 * n) {
            if (d <= n + 1) {
                cnt = d - 1;
            } else {
                cnt = 2 * n + 1 - d;
            }
        } else {
            cnt = 0;
        }
        total -= cnt;
    }

    // Add back overlaps between row/col and diagonals
    set<pll> visited;
    for (auto r : rows) {
        for (auto c : cols) {
            visited.insert({r, c});
        }
    }

    for (auto r : rows) {
        for (ll d : diag1) {
            pll p = {r, r - d};
            if (inBounds(p, n)) {
                visited.insert(p);
            }
        }
        for (ll d : diag2) {
            pll p = {r, d - r};
            if (inBounds(p, n)) {
                visited.insert(p);
            }
        }
    }

    for (auto c : cols) {
        for (ll d : diag1) {
            pll p = {c + d, c};
            if (inBounds(p, n)) {
                visited.insert(p);
            }
        }
        for (ll d : diag2) {
            pll p = {d - c, c};
            if (inBounds(p, n)) {
                visited.insert(p);
            }
        }
    }

    for (ll d1 : diag1) {
        for (ll d2 : diag2) {
            // Solve: i - j = d1, i + j = d2
            // => i = (d1 + d2)/2, j = (d2 - d1)/2
            if ((d1 + d2) % 2 != 0 || (d2 - d1) % 2 != 0) continue;
            pll p = {(d1 + d2) / 2, (d2 - d1) / 2};
            if (inBounds(p, n)) {
                visited.insert(p);
            }
        }
    }

    // Remove actual pieces from overlap count
    ll overlapCount = 0;
    for (auto p : visited) {
        if (occupied.count(p)) overlapCount++;
    }

    total += visited.size() - overlapCount;
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