#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)
#define all(a) (a).begin(), (a).end()

void re(ll &x) { cin >> x; }
void re(int &x) { cin >> x; }
void re(pll &x) { cin >> x.first >> x.second; }

template <typename T, typename... U>
void re(T &t, U &...u) {
    re(t);
    re(u...);
}

template <typename T>
void re(vector<T> &v) {
    for (auto &x : v)
        re(x);
}

bool inBounds(const pll &p, ll n) {
    return p.first >= 1 && p.first <= n && p.second >= 1 && p.second <= n;
}

void solve() {
    ll N, M;
    re(N, M);
    vector<pll> pieces(M);
    re(pieces);

    unordered_set<ll> rows, cols;
    unordered_set<ll> diag1, diag2; // i-j and i+j

    for (auto [r, c] : pieces) {
        rows.insert(r);
        cols.insert(c);
        diag1.insert(r - c);
        diag2.insert(r + c);
    }

    ll total = N * N;
    // Subtract rows
    total -= (ll)rows.size() * N;
    // Subtract columns
    total -= (ll)cols.size() * N;
    // Add back intersections of rows and columns
    ll overlap_row_col = 0;
    for (auto r : rows) {
        for (auto c : cols) {
            if (r >= 1 && r <= N && c >= 1 && c <= N) {
                overlap_row_col++;
            }
        }
    }
    total += overlap_row_col;

    // Subtract diagonal 1 (i-j)
    for (auto d : diag1) {
        ll cnt;
        // Number of cells on diagonal i-j = d
        if (d >= -(N - 1) && d <= N - 1) {
            if (N + d <= N)
                cnt = N - abs(d);
            else
                cnt = 2 * N - 1 - abs(d);
        } else {
            continue;
        }

        set<pll> overlaps;
        for (auto r : rows) {
            ll c = r - d;
            if (c >= 1 && c <= N)
                overlaps.insert({r, c});
        }
        for (auto c : cols) {
            ll r = c + d;
            if (r >= 1 && r <= N)
                overlaps.insert({r, c});
        }
        total -= cnt;
        total += overlaps.size();
    }

    // Subtract diagonal 2 (i+j)
    for (auto d : diag2) {
        ll cnt;
        if (d >= 2 && d <= 2 * N) {
            if (d <= N + 1)
                cnt = d - 1;
            else
                cnt = 2 * N + 1 - d;
        } else {
            continue;
        }

        set<pll> overlaps;
        for (auto r : rows) {
            ll c = d - r;
            if (c >= 1 && c <= N)
                overlaps.insert({r, c});
        }
        for (auto c : cols) {
            ll r = d - c;
            if (r >= 1 && r <= N)
                overlaps.insert({r, c});
        }

        // Intersections with other diagonals
        for (auto od : diag1) {
            ll i = (d + od) / 2;
            ll j = (d - od) / 2;
            if ((d + od) % 2 == 0 && (d - od) % 2 == 0) {
                pll pt(i, j);
                if (inBounds(pt, N))
                    overlaps.insert(pt);
            }
        }

        total -= cnt;
        total += overlaps.size();
    }

    cout << total << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}