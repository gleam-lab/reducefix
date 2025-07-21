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
    ll n, m; cin >> n >> m;
    vector<pll> q(m);
    for(int i = 0; i < m; ++i) {
        cin >> q[i].first >> q[i].second;
    }

    set<ll> row, col;
    set<ll> diag1, diag2;

    for(auto [i, j] : q) {
        row.insert(i);
        col.insert(j);
        diag1.insert(i - j);
        diag2.insert(i + j);
    }

    ll total = n * n;

    // Remove rows and columns
    total -= (ll)row.size() * n;
    total -= (ll)col.size() * n;
    total += (ll)row.size() * (ll)col.size(); // Overlap: squares on both attacked row and column

    // Remove diagonal 1 (i - j)
    for(ll d : diag1) {
        ll count;
        if (d >= -(n - 1) && d <= n - 1) {
            count = n - abs(d);
        } else {
            count = 0;
        }

        total -= count;
        // Add back intersections with attacked rows or columns
        set<pll> intersections;
        for(ll r : row) {
            ll c = r - d;
            if (c >= 1 && c <= n) {
                intersections.insert({r, c});
            }
        }
        for(ll c : col) {
            ll r = c + d;
            if (r >= 1 && r <= n) {
                intersections.insert({r, c});
            }
        }

        total += intersections.size();
    }

    // Remove diagonal 2 (i + j)
    for(ll d : diag2) {
        ll count;
        if (d >= 2 && d <= 2 * n) {
            if (d <= n + 1) {
                count = d - 1;
            } else {
                count = 2 * n - d + 1;
            }
        } else {
            count = 0;
        }

        total -= count;

        // Add back intersections with attacked rows or columns or other diagonals
        set<pll> intersections;
        for(ll r : row) {
            ll c = d - r;
            if (c >= 1 && c <= n) {
                intersections.insert({r, c});
            }
        }
        for(ll c : col) {
            ll r = d - c;
            if (r >= 1 && r <= n) {
                intersections.insert({r, c});
            }
        }
        for(ll od : diag1) {
            // Solve for intersection of two diagonals: i-j=od and i+j=d
            if((d + od) % 2 == 0) {
                ll r = (d + od) / 2;
                ll c = (d - od) / 2;
                if(r >= 1 && r <= n && c >= 1 && c <= n) {
                    intersections.insert({r, c});
                }
            }
        }

        total += intersections.size();
    }

    cout << total << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    //cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}