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
        pll pos;
        re(pos.first, pos.second);
        pieces.insert(pos);
        rows.insert(pos.first);
        cols.insert(pos.second);
        diag1.insert(pos.first - pos.second);
        diag2.insert(pos.first + pos.second);
    }

    // Total squares: row attack + col attack + diag1 attack + diag2 attack - overlaps
    ll total = n * n;
    ll attacked = 0;

    // Count unique attacked positions
    set<pll> attackedPositions;

    // Rows
    for (ll r : rows) {
        for (ll c = 1; c <= n; ++c) {
            if (pieces.find({r, c}) == pieces.end())
                attackedPositions.insert({r, c});
        }
    }

    // Columns
    for (ll c : cols) {
        for (ll r = 1; r <= n; ++r) {
            if (pieces.find({r, c}) == pieces.end())
                attackedPositions.insert({r, c});
        }
    }

    // Diagonal 1: i - j
    for (ll d : diag1) {
        // Intersection with grid boundaries
        ll min_i = max(1LL, d + 1);
        ll max_i = min(n, n + d);

        for (ll i = min_i; i <= max_i; ++i) {
            ll j = i - d;
            if (1 <= j && j <= n) {
                if (pieces.find({i, j}) == pieces.end())
                    attackedPositions.insert({i, j});
            }
        }
    }

    // Diagonal 2: i + j
    for (ll s : diag2) {
        // Intersection with grid boundaries
        ll min_i = max(1LL, s - n);
        ll max_i = min(n, s - 1);

        for (ll i = min_i; i <= max_i; ++i) {
            ll j = s - i;
            if (1 <= j && j <= n) {
                if (pieces.find({i, j}) == pieces.end())
                    attackedPositions.insert({i, j});
            }
        }
    }

    // Empty squares not under attack
    ll safeSquares = n * n - (ll)pieces.size() - (ll)attackedPositions.size();

    cout << safeSquares << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    //cin >> t;
    while(t--) solve();
    return 0;
}