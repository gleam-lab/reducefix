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
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define ROF(i, a, b) for (int i = (b)-1; i >= (a); --i)

template<typename T> void re(T &x) { cin >> x; }
template<typename T, typename... U> void re(T &t, U&... u) { re(t); re(u...); }
template<typename T> void re(V<T> &x) { for(auto &a : x) re(a); }

template <typename T, typename V> ostream& operator<<(ostream& out, const pair<T, V> x) { out << "{" << x.first << " : " << x.second << "}"; return out; }
template <typename T> ostream& operator<<(ostream& out, const set<T> x) { for (auto& it : x) out << it << " "; return out; }
template <typename T> ostream& operator<<(ostream& out, const multiset<T> x) { for (auto& it : x) out << it << " "; return out; }
template <typename T, typename V> ostream& operator<<(ostream& out, const map<T, V> x) { for (auto& it : x) out << "[" << it.first << "] = " << it.second << "\n"; return out; }
template <typename T> ostream& operator<<(ostream& out, const V<T> x) {
    if (!x.empty()) {
        for (int i = 0; i < x.size() - 1; ++i) out << x[i] << " ";
        out << x.back();
    }
    return out;
}

template <class T, class U> inline void chmin(T& a, U&& b) { if (b < a) a = b; }
template <class T, class U> inline void chmax(T& a, U&& b) { if (a < b) a = b; }

bool inBounds(const pll &p, ll n) {
    return 1 <= p.first && p.first <= n && 1 <= p.second && p.second <= n;
}

// F - Avoid Queen Attack
void solve() {
    ll n, m;
    re(n, m);
    set<pll> pieces;
    set<ll> rows, cols, diag1, diag2;

    FOR(i, 0, m) {
        ll a, b;
        re(a, b);
        pieces.insert({a, b});
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
    }

    // Total squares: n*n
    // Subtract squares attacked by row/column/diagonal
    ll ans = n * n;

    // Rows and columns directly
    ans -= (ll)rows.size() * n;
    ans -= (ll)cols.size() * n;
    ans += (ll)rows.size() * (ll)cols.size(); // Overlap between row and column attacks

    // Diagonal 1: a - b
    for (ll d : diag1) {
        ll cnt;
        if (n + d <= n) {
            // Positive offset
            cnt = n - abs(d);
        } else {
            cnt = 2 * n - abs(d);
        }
        ans -= cnt;

        set<pll> overlap;
        for (ll r : rows) {
            pll p = {r, r - d};
            if (inBounds(p, n)) overlap.insert(p);
        }
        for (ll c : cols) {
            pll p = {c + d, c};
            if (inBounds(p, n)) overlap.insert(p);
        }

        ans += overlap.size();
    }

    // Diagonal 2: a + b
    for (ll d : diag2) {
        ll cnt;
        if (d <= n + 1)
            cnt = d - 1;
        else
            cnt = 2 * n - d + 1;
        ans -= cnt;

        set<pll> overlap;
        for (ll r : rows) {
            pll p = {r, d - r};
            if (inBounds(p, n) && p.second >= 1 && p.second <= n)
                overlap.insert(p);
        }
        for (ll c : cols) {
            pll p = {d - c, c};
            if (inBounds(p, n) && p.first >= 1 && p.first <= n)
                overlap.insert(p);
        }

        // Intersections with other diagonals
        for (ll od : diag1) {
            // Solve:
            // i + j = d
            // i - j = od
            // => i = (d + od) / 2
            // => j = (d - od) / 2
            if ((d + od) % 2 == 0) {
                pll p = {(d + od) / 2, (d - od) / 2};
                if (inBounds(p, n))
                    overlap.insert(p);
            }
        }

        ans += overlap.size();
    }

    // Subtract already occupied squares
    ans -= m;

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    //cin >> t;
    while(t--) solve();
    return 0;
}