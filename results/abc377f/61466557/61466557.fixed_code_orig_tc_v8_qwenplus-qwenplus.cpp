#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
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

template <class T, class U> inline void chmin(T& a, U&& b) { if (b < a) { a = b; } }
template <class T, class U> inline void chmax(T& a, U&& b) { if (a < b) { a = b; } }

bool inBounds(const pll &p, ll n) {
    return p.first >= 1 && p.first <= n && p.second >= 1 && p.second <= n;
}

// F - Avoid Queen Attack
void solve() {
    ll N, M;
    re(N, M);
    set<pll> pieces;
    set<ll> rows, cols, diag1, diag2;

    for (ll i = 0; i < M; ++i) {
        ll a, b;
        re(a, b);
        pieces.insert({a, b});
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
    }

    // Total squares attacked by rows and columns
    ll attacked = (ll)rows.size() * N + (ll)cols.size() * N - (ll)rows.size() * (ll)cols.size();

    // Now handle diagonals carefully
    set<pll> visited;
    for (ll d : diag1) {
        ll cnt = N - abs(d);
        attacked += cnt;
        // Add intersections with rows and cols
        for (ll r : rows) {
            ll c = r - d;
            pll pos = {r, c};
            if (inBounds(pos, N)) {
                if (visited.count(pos) == 0) {
                    visited.insert(pos);
                }
            }
        }
        for (ll c : cols) {
            ll r = c + d;
            pll pos = {r, c};
            if (inBounds(pos, N)) {
                if (visited.count(pos) == 0) {
                    visited.insert(pos);
                }
            }
        }
    }

    for (ll d : diag2) {
        ll cnt = (d <= N) ? (d - 1) : (2 * N - d + 1);
        attacked += cnt;
        // Add intersections with rows and cols
        for (ll r : rows) {
            ll c = d - r;
            pll pos = {r, c};
            if (inBounds(pos, N)) {
                if (visited.count(pos) == 0) {
                    visited.insert(pos);
                }
            }
        }
        for (ll c : cols) {
            ll r = d - c;
            pll pos = {r, c};
            if (inBounds(pos, N)) {
                if (visited.count(pos) == 0) {
                    visited.insert(pos);
                }
            }
        }
    }

    // Subtract overcounted intersections
    attacked -= (ll)visited.size();

    // Also count the actual occupied squares
    ll totalOccupied = 0;
    for (pll p : pieces) {
        if (inBounds(p, N)) totalOccupied++;
    }

    ll ans = N * N - attacked - totalOccupied;
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}