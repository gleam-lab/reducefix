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

// Function to compute the number of squares attacked by diagonal d1: i - j
ll diag1_count(ll d, ll n) {
    ll abs_d = abs(d);
    return max(0LL, n - abs_d);
}

// Function to compute the number of squares attacked by diagonal d2: i + j
ll diag2_count(ll d, ll n) {
    if (d < 2 || d > 2 * n) return 0;
    if (d <= n + 1) return d - 1;
    else return 2 * n - d + 1;
}

void solve() {
    ll n, m;
    re(n, m);
    vector<pii> q(m);
    for (auto &[i, j] : q) {
        re(i, j);
    }

    set<ll> rows, cols;
    set<ll> diag1, diag2; // i-j and i+j

    for (auto [i, j] : q) {
        rows.insert(i);
        cols.insert(j);
        diag1.insert(i - j);
        diag2.insert(i + j);
    }

    // Total squares on board
    ll total_squares = n * n;

    // Subtract rows
    ll attacked_by_rows = rows.size() * n;

    // Subtract columns
    ll attacked_by_cols = cols.size() * n;

    // Add back overlap between rows and columns (double-counted)
    ll row_col_overlap = 0;
    for (auto r : rows) {
        for (auto c : cols) {
            row_col_overlap++;
        }
    }

    // Subtract diagonals of type i-j
    ll attacked_by_diag1 = 0;
    set<pll> diag1_intersections;
    for (auto d : diag1) {
        attacked_by_diag1 += diag1_count(d, n);

        // Check intersections with existing rows and cols
        for (auto r : rows) {
            ll c = r - d;
            if (1 <= c && c <= n) diag1_intersections.insert({r, c});
        }
        for (auto c : cols) {
            ll r = d + c;
            if (1 <= r && r <= n) diag1_intersections.insert({r, c});
        }
    }

    // Subtract diagonals of type i+j
    ll attacked_by_diag2 = 0;
    set<pll> diag2_intersections;
    for (auto d : diag2) {
        attacked_by_diag2 += diag2_count(d, n);

        // Check intersections with existing rows and cols
        for (auto r : rows) {
            ll c = d - r;
            if (1 <= c && c <= n) diag2_intersections.insert({r, c});
        }
        for (auto c : cols) {
            ll r = d - c;
            if (1 <= r && r <= n) diag2_intersections.insert({r, c});
        }
    }

    // Remove duplicates from diagonal intersections
    set<pll> diag_intersection;
    for (auto p : diag1_intersections) diag_intersection.insert(p);
    for (auto p : diag2_intersections) diag_intersection.insert(p);

    // Combine everything
    ll total_attacked = attacked_by_rows + attacked_by_cols + attacked_by_diag1 + attacked_by_diag2;
    ll overlaps = row_col_overlap + diag1_intersections.size() + diag2_intersections.size() + diag_intersection.size();

    // Final result
    ll ans = total_squares - (total_attacked - overlaps);
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    //cin >> t;
    while(t--) solve();
    return 0;
}