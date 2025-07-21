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
    vector<pll> q(m); FOR(i, 0, m) { re(q[i].fst, q[i].snd); }

    set<ll> row, col;
    set<ll> diag1, diag2;

    for (auto [a, b] : q) {
        row.insert(a);
        col.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
    }

    // Total squares
    ll total = n * n;

    // Subtract rows and columns
    ll attacked_by_row = static_cast<ll>(row.size()) * n;
    ll attacked_by_col = static_cast<ll>(col.size()) * n;

    // Inclusion-exclusion for overlapping cells
    set<pair<ll, ll>> overlap_cells;
    for (ll r : row) {
        for (ll c : col) {
            overlap_cells.insert({r, c});
        }
    }

    ll overlaps = overlap_cells.size();

    // So far: attacked = row_attack + col_attack - overlaps
    ll attacked_rows_cols = attacked_by_row + attacked_by_col - overlaps;

    // Now handle diagonals

    // Diagonal 1: i - j = d
    ll attacked_diag1 = 0;
    set<pair<ll, ll>> diag1_overlap;
    for (ll d : diag1) {
        // Number of squares on this diagonal: depends on d
        ll count;
        if (d >= 0) {
            count = min(n - d, n);
        } else {
            count = min(n + d, n);
        }

        // Subtract the piece itself
        attacked_diag1 += count;

        // Find intersections with rows and columns
        for (ll r : row) {
            ll c = r - d;
            if (1 <= c && c <= n) {
                diag1_overlap.insert({r, c});
            }
        }
        for (ll c : col) {
            ll r = c + d;
            if (1 <= r && r <= n) {
                diag1_overlap.insert({r, c});
            }
        }
    }

    // Diagonal 2: i + j = s
    ll attacked_diag2 = 0;
    set<pair<ll, ll>> diag2_overlap;
    for (ll s : diag2) {
        ll count;
        if (s <= n + 1) {
            count = s - 1;
        } else {
            count = 2 * n + 1 - s;
        }

        attacked_diag2 += count;

        // Find intersections with rows and columns
        for (ll r : row) {
            ll c = s - r;
            if (1 <= c && c <= n) {
                diag2_overlap.insert({r, c});
            }
        }
        for (ll c : col) {
            ll r = s - c;
            if (1 <= r && r <= n) {
                diag2_overlap.insert({r, c});
            }
        }

        // Also find intersection with diag1
        for (ll d : diag1) {
            // Solve:
            // i + j = s
            // i - j = d
            ll i = (s + d) / 2;
            ll j = (s - d) / 2;
            if ((s + d) % 2 == 0 && (s - d) % 2 == 0 && 1 <= i && i <= n && 1 <= j && j <= n) {
                diag2_overlap.insert({i, j});
            }
        }
    }

    // Remove overlapping cells between diagonals
    ll diag_overlaps = diag1_overlap.size() + diag2_overlap.size();

    // Total attacked cells = rows + cols + diag1 + diag2 - overlaps
    ll total_attacked = attacked_rows_cols + attacked_diag1 + attacked_diag2 - diag_overlaps;

    // Subtract already occupied cells
    total_attacked -= m;

    // Final answer
    cout << n * n - total_attacked << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    //cin >> t;
    while(t--) solve();
    return 0;
}