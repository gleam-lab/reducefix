#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

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

bool inBounds(const pii &a, const ll n) {
    return 1 <= a.fst && a.fst <= n && 1 <= a.snd && a.snd <= n;
}

// Function to count the number of valid positions
ll countValidPositions(const ll n, const V<pii> &pieces) {
    set<ll> rows, cols, diag1, diag2;
    for (const auto &p : pieces) {
        rows.insert(p.fst);
        cols.insert(p.snd);
        diag1.insert(p.fst - p.snd);
        diag2.insert(p.fst + p.snd);
    }

    ll totalPositions = n * n;
    ll invalidByRow = rows.size() * n;
    ll invalidByCol = cols.size() * n;
    ll invalidByDiag1 = diag1.size() * n;
    ll invalidByDiag2 = diag2.size() * n;

    ll overcountedByRowsAndCols = rows.size() * cols.size();
    ll overcountedByDiags = 0;

    for (const auto &d1 : diag1) {
        set<pii> intersections;
        for (const auto &r : rows) {
            pii intersection = {r, r - d1};
            if (inBounds(intersection, n)) {
                intersections.insert(intersection);
            }
        }
        for (const auto &c : cols) {
            pii intersection = {c + d1, c};
            if (inBounds(intersection, n)) {
                intersections.insert(intersection);
            }
        }
        overcountedByDiags += n - abs(d1) - intersections.size();
    }

    for (const auto &d2 : diag2) {
        set<pii> intersections;
        for (const auto &r : rows) {
            pii intersection = {r, d2 - r};
            if (inBounds(intersection, n)) {
                intersections.insert(intersection);
            }
        }
        for (const auto &c : cols) {
            pii intersection = {d2 - c, c};
            if (inBounds(intersection, n)) {
                intersections.insert(intersection);
            }
        }
        overcountedByDiags += d2 < n ? (d2 - 1) - intersections.size() : (2 * n - d2) - intersections.size();
    }

    ll validPositions = totalPositions - (invalidByRow + invalidByCol + invalidByDiag1 + invalidByDiag2 - overcountedByRowsAndCols - overcountedByDiags);
    return validPositions;
}

void solve() {
    ll n, m; re(n, m);
    V<pii> pieces(m); FOR(i, 0, m) { re(pieces[i].fst, pieces[i].snd); }
    ll result = countValidPositions(n, pieces);
    cout << result << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    while (t--) solve();
    return 0;
}