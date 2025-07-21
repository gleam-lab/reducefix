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

bool inBounds(const int &i, const int &j, const int &n) {
    return 1 <= i && i <= n && 1 <= j && j <= n;
}

// Function to count non-capturable squares
int countNonCapturableSquares(const int &n, const int &m, const V<pair<int, int>> &q) {
    set<int> rows, cols, diag1, diag2;
    
    // Populate sets with occupied positions
    for (const auto &[i, j] : q) {
        rows.insert(i);
        cols.insert(j);
        diag1.insert(i - j);
        diag2.insert(i + j);
    }
    
    // Calculate total non-capturable squares
    int non_capturable = n * n;
    non_capturable -= rows.size() * n;
    non_capturable -= cols.size() * n;
    non_capturable += rows.size() * cols.size();
    
    // Adjust for diagonal captures
    for (const auto &d : diag1) {
        int cnt = min(n, abs(d));
        non_capturable -= cnt;
    }
    for (const auto &d : diag2) {
        int cnt = min(n, abs(d));
        non_capturable -= cnt;
    }
    
    return non_capturable;
}

void solve() {
    int n, m; re(n, m);
    V<pair<int, int>> q(m); FOR(i, 0, m) { re(q[i].fst, q[i].snd); }
    int result = countNonCapturableSquares(n, m, q);
    cout << result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    //cin >> t;
    while(t--) solve();
    return 0;
}