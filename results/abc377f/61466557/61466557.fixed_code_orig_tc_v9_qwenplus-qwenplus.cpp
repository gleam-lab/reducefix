#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define FOR(i, a, b) for (ll i = (a); i < (b); ++i)
#define pb push_back
#define eb emplace_back
#define ins insert
#define all(x) x.begin(), x.end()

bool inBounds(const pll &p, ll n) {
    return 1 <= p.first && p.first <= n && 1 <= p.second && p.second <= n;
}

// Function to read input
void re(ll &x) { cin >> x; }
void re(pll &p) { cin >> p.first >> p.second; }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M;
    re(N);
    re(M);

    vector<pll> pieces(M);
    set<pll> occupied;
    set<ll> rows, cols, diag1, diag2;

    for (ll i = 0; i < M; ++i) {
        re(pieces[i]);
        ll r = pieces[i].first, c = pieces[i].second;
        occupied.insert({r, c});
        rows.insert(r);
        cols.insert(c);
        diag1.insert(r - c);
        diag2.insert(r + c);
    }

    // Total number of cells
    ll total = N * N;

    // Remove all cells in attacked rows and columns
    total -= (ll)rows.size() * N;
    total -= (ll)cols.size() * N;

    // Add back the over-subtracted intersections of rows and columns
    total += (ll)(rows.size() * cols.size());

    // Now subtract attacked cells on diagonals of type (r - c)
    for (auto d : diag1) {
        ll cnt = N - abs(d);
        if (cnt > 0) {
            total -= cnt;
        }
    }

    // Now subtract attacked cells on diagonals of type (r + c)
    for (auto d : diag2) {
        ll cnt = (d >= 1 && d <= 2 * N) ? (d <= N ? d - 1 : 2 * N - d + 1) : 0;
        if (cnt > 0) {
            total -= cnt;
        }
    }

    // Add back over-subtracted intersections between rows/cols and diagonals
    // Rows × Diag1 → (r, r-d)
    for (auto r : rows) {
        for (auto d : diag1) {
            pll p(r, r - d);
            if (inBounds(p, N)) {
                if (occupied.find(p) == occupied.end()) {
                    total++;
                }
            }
        }
    }

    // Cols × Diag1 → (c + d, c)
    for (auto c : cols) {
        for (auto d : diag1) {
            pll p(c + d, c);
            if (inBounds(p, N)) {
                if (occupied.find(p) == occupied.end()) {
                    total++;
                }
            }
        }
    }

    // Rows × Diag2 → (r, d - r)
    for (auto r : rows) {
        for (auto d : diag2) {
            pll p(r, d - r);
            if (inBounds(p, N)) {
                if (occupied.find(p) == occupied.end()) {
                    total++;
                }
            }
        }
    }

    // Cols × Diag2 → (d - c, c)
    for (auto c : cols) {
        for (auto d : diag2) {
            pll p(d - c, c);
            if (inBounds(p, N)) {
                if (occupied.find(p) == occupied.end()) {
                    total++;
                }
            }
        }
    }

    // Also add back triple overlaps: row ∩ col ∩ diag
    for (auto p : occupied) {
        ll r = p.first, c = p.second;
        if (rows.count(r) && cols.count(c)) {
            total++; // added due to intersection of row and col
        }
        if (diag1.count(r - c)) {
            total++; // added due to diag1
        }
        if (diag2.count(r + c)) {
            total++; // added due to diag2
        }
    }

    // Subtract occupied cells (they are not valid)
    total -= (ll)occupied.size();

    cout << max(0LL, total) << '\n';
}