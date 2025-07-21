#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

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

// Function to count non-attacked cells
void solve() {
    ll n, m; re(n, m);
    vector<pii> q(m); FOR(i, 0, m) { re(q[i].fst, q[i].snd); }
    
    unordered_set<ll> row, col, d1, d2;
    for(auto &[i, j] : q) {
        row.insert(i); col.insert(j); d1.insert(i - j); d2.insert(i + j);
    }
    
    ll ans = n * n;
    ans -= static_cast<ll>(row.size()) * n;
    ans -= static_cast<ll>(col.size()) * n;
    ans += static_cast<ll>(row.size()) * static_cast<ll>(col.size());
    
    for(auto &d : d1) {
        ll cnt = 0;
        for(auto &r : row) {
            if(inBounds({r, r - d}, n)) cnt++;
        }
        for(auto &c : col) {
            if(inBounds({c + d, c}, n)) cnt++;
        }
        ans -= cnt;
    }
    
    for(auto &d : d2) {
        ll cnt = 0;
        for(auto &r : row) {
            if(inBounds({r, d - r}, n)) cnt++;
        }
        for(auto &c : col) {
            if(inBounds({d - c, c}, n)) cnt++;
        }
        ans -= cnt;
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