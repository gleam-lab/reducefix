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
    vector<pii> q(m);
    FOR(i, 0, m) {
        re(q[i].first, q[i].second);
    }

    set<ll> row, col, diag1, diag2;
    set<pll> occupied;
    for (auto &[i, j] : q) {
        row.insert(i);
        col.insert(j);
        diag1.insert(i - j);
        diag2.insert(i + j);
        occupied.insert({i, j});
    }

    ll total = n * n;
    ll attacked = 0;

    // Rows and columns
    attacked += (ll)row.size() * n;
    attacked += (ll)col.size() * n;
    // Subtract overlap of rows and columns
    for (auto r : row) {
        for (auto c : col) {
            if (occupied.find({r, c}) != occupied.end()) continue;
            attacked--;
        }
    }

    // Diagonal 1: i - j
    for (auto d : diag1) {
        ll cnt;
        if (d >= -(n - 1) && d <= n - 1) {
            if (abs(d) < n) {
                cnt = n - abs(d);
            } else {
                cnt = 2 * n - 1 - abs(d);
            }
            attacked += cnt;
        }
        // Subtract overlaps with row and column attacks
        set<pll> diag_points;
        for (auto r : row) {
            ll c = r - d;
            if (1 <= c && c <= n) {
                diag_points.insert({r, c});
            }
        }
        for (auto c : col) {
            ll r = c + d;
            if (1 <= r && r <= n) {
                diag_points.insert({r, c});
            }
        }
        attacked -= diag_points.size();
    }

    // Diagonal 2: i + j
    for (auto d : diag2) {
        ll cnt;
        if (d >= 2 && d <= 2 * n) {
            if (d <= n + 1) {
                cnt = d - 1;
            } else {
                cnt = 2 * n + 1 - d;
            }
            attacked += cnt;
        }
        // Subtract overlaps with row and column attacks
        set<pll> diag_points;
        for (auto r : row) {
            ll c = d - r;
            if (1 <= c && c <= n) {
                diag_points.insert({r, c});
            }
        }
        for (auto c : col) {
            ll r = d - c;
            if (1 <= r && r <= n) {
                diag_points.insert({r, c});
            }
        }
        // Subtract overlaps with diagonal 1
        for (auto od : diag1) {
            ll x = (d + od) / 2;
            ll y = (d - od) / 2;
            if (inBounds({x, y}, n)) {
                diag_points.insert({x, y});
            }
        }
        attacked -= diag_points.size();
    }

    // Total squares that are not attacked and are empty
    ll ans = n * n - attacked - m;
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    while (t--) solve();
    return 0;
}