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
    return 1 <= a.fst && a.fst <= n && 1 <= a.a.snd && a.snd <= n;
}

// F - Avoid Queen Attack
void solve() {
    ll n, m; re(n, m);
    vector<pll> q(m); FOR(i, 0, m) { re(q[i].fst, q[i].snd); }

    set<ll> row, col;
    set<ll> diag1, diag2;

    for (auto [i, j] : q) {
        row.insert(i);
        col.insert(j);
        diag1.insert(i - j);
        diag2.insert(i + j);
    }

    // Total squares: N^2
    ll ans = n * n;

    // Subtract squares attacked by queens in rows and columns
    ans -= static_cast<ll>(row.size()) * n;
    ans -= static_cast<ll>(col.size()) * n;
    // Add back intersections (double counted)
    ans += static_cast<ll>(row.size()) * static_cast<ll>(col.size());

    // Subtract squares attacked on the diagonals

    // Diag1: i - j = d
    for (ll d : diag1) {
        ll cnt = n - max(1LL, d + 1) + 1;
        if (d >= -(n-1) && d <= n-1) {
            ans -= cnt;
        }
    }

    // Diag2: i + j = d
    for (ll d : diag2) {
        ll cnt = d <= n ? d - 1 : 2 * n - d + 1;
        if (d >= 2 && d <= 2 * n) {
            ans -= cnt;
        }
    }

    // Now add back squares that were subtracted multiple times due to overlap

    // Set of positions already occupied or attacked uniquely
    set<pll> attacked;

    for (auto [i, j] : q) {
        attacked.insert({i, j});
    }

    // Add back overlapping points between row, col, and diagonals
    for (auto r : row) {
        for (auto c : col) {
            attacked.insert({r, c});
        }
    }

    for (auto [i, j] : q) {
        ll d1 = i - j;
        ll d2 = i + j;

        // Intersections with other diagonals
        for (auto od1 : diag1) {
            if (od1 == d1) continue;
            ll x = (d2 + od1) / 2;
            ll y = (d2 - od1) / 2;
            if ((d2 + od1) % 2 == 0 && (d2 - od1) % 2 == 0 && x >= 1 && x <= n && y >= 1 && y <= n) {
                attacked.insert({x, y});
            }
        }

        for (auto od2 : diag2) {
            if (od2 == d2) continue;
            ll x = (d2 + od2) / 2;
            ll y = (od2 - d2) / 2;
            if ((d2 + od2) % 2 == 0 && (od2 - d2) % 2 == 0 && x >= 1 && x <= n && y >= 1 && y <= n) {
                attacked.insert({x, y});
            }
        }
    }

    // Add back over-subtracted intersecting points
    ans += attacked.size();

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