#include <bits/stdc++.h>
using namespace std;

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


bool inBounds(const int &a, const int &n) {
    return 1 <= a && a <= n;
}
//  F - Avoid Queen Attack
void solve() {
    int n, m; re(n, m);
    vector<pair<int, int>> q(m); FOR(i, 0, m) { re(q[i].fst, q[i].snd); }
    set<int> row, col, d1, d2;
    for(auto &[i, j] : q) {
        row.insert(i); col.insert(j); d1.insert(i - j); d2.insert(i + j);
    }
    int ans = n * n;
    ans -= static_cast<int>(row.size()) * n;
    ans -= static_cast<int>(col.size()) * n;
    ans += static_cast<int>(row.size()) * static_cast<int>(col.size());
    set<pair<int, int>> com;
    for(auto &d: d1) {
        com.clear();
        for(auto &r : row) {
            pair<int, int> ints = {r, r - d};
            if(inBounds(ints.first, n) && inBounds(ints.second, n)) com.insert(ints);
        }
        for(auto &c : col) {
            pair<int, int> ints = {c + d, c};
            if(inBounds(ints.first, n) && inBounds(ints.second, n)) com.insert(ints);
        }
        int cnt = n - abs(d);
        ans -= cnt;
        ans += com.size();
    }
    for(auto &d: d2) {
        com.clear();
        for(auto &r : row) {
            pair<int, int> ints = {r, d - r};
            if(inBounds(ints.first, n) && inBounds(ints.second, n)) com.insert(ints);
        }
        for(auto &c : col) {
            pair<int, int> ints = {d - c, c};
            if(inBounds(ints.first, n) && inBounds(ints.second, n)) com.insert(ints);
        }
        for(auto &od : d1) {
            // od = (i - j)
            // d = (i + j)
            int x = ((d % 2) + 2) % 2;
            int y = ((od % 2) + 2) % 2;
            if(x != y) continue;
            pair<int, int> ints = {(d + od) / 2, (d - od) / 2};
            if(inBounds(ints.first, n) && inBounds(ints.second, n)) com.insert(ints);
        }
        int cnt = d < n ? (d - 1) : (2 * n - d + 1);
        // cout << dbgs(d) << dbgs(cnt) << dbgs(com) << endl;
        ans -= cnt;
        ans += com.size();
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