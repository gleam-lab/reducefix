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

bool inBounds(const pll &a, const ll n) {
    return 1 <= a.fst && a.fst <= n && 1 <= a.snd && a.snd <= n;
}

// F - Avoid Queen Attack
void solve() {
    ll n, m;
    re(n, m);
    vector<pii> q(m);
    FOR(i, 0, m) {
        re(q[i].fst, q[i].snd);
    }

    set<ll> row, col, d1, d2;
    set<pll> occupied;
    for (auto &[i, j] : q) {
        row.insert(i);
        col.insert(j);
        d1.insert(i - j);
        d2.insert(i + j);
        occupied.insert({i, j});
    }

    ll ans = n * n;
    ans -= static_cast<ll>(row.size()) * n;
    ans -= static_cast<ll>(col.size()) * n;
    ans += static_cast<ll>(row.size()) * static_cast<ll>(col.size());

    // Handle diagonal1 (i - j = d)
    for (auto &d : d1) {
        ll cnt;
        if (n - abs(d) > 0)
            cnt = n - abs(d);
        else
            cnt = 0;
        ans -= cnt;
    }

    // Handle diagonal2 (i + j = d)
    for (auto &d : d2) {
        ll cnt;
        if (d >= 1 && d <= 2 * n) {
            if (d <= n + 1)
                cnt = d - 1;
            else
                cnt = 2 * n + 1 - d;
        } else {
            cnt = 0;
        }
        ans -= cnt;
    }

    // Now add back overlaps: squares that were subtracted multiple times

    // Add back overlaps between rows and columns
    ll overlap_row_col = 0;
    for (auto r : row) {
        for (auto c : col) {
            if (occupied.count({r, c}) == 0)
                overlap_row_col++;
        }
    }
    ans += overlap_row_col;

    // Add back overlaps between rows and d1
    for (auto d : d1) {
        for (auto r : row) {
            ll c = r - d;
            if (1 <= c && c <= n) {
                if (!occupied.count({r, c})) {
                    ans++;
                }
            }
        }
    }

    // Add back overlaps between rows and d2
    for (auto d : d2) {
        for (auto r : row) {
            ll c = d - r;
            if (1 <= c && c <= n) {
                if (!occupied.count({r, c})) {
                    ans++;
                }
            }
        }
    }

    // Add back overlaps between cols and d1
    for (auto d : d1) {
        for (auto c : col) {
            ll r = c + d;
            if (1 <= r && r <= n) {
                if (!occupied.count({r, c})) {
                    ans++;
                }
            }
        }
    }

    // Add back overlaps between cols and d2
    for (auto d : d2) {
        for (auto c : col) {
            ll r = d - c;
            if (1 <= r && r <= n) {
                if (!occupied.count({r, c})) {
                    ans++;
                }
            }
        }
    }

    // Add back overlaps between d1 and d2
    for (auto d1_val : d1) {
        for (auto d2_val : d2) {
            // Solve:
            // i - j = d1_val
            // i + j = d2_val
            ll i = (d1_val + d2_val) / 2;
            ll j = (d2_val - d1_val) / 2;
            if ((d1_val + d2_val) % 2 == 0 && (d2_val - d1_val) % 2 == 0 &&
                1 <= i && i <= n && 1 <= j && j <= n) {
                if (!occupied.count({i, j})) {
                    ans++;
                }
            }
        }
    }

    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    //cin >> t;
    while(t--) solve();
    return 0;
}