#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pll = pair<ll, ll>;

ll N, M;
set<ll> rows, cols;
set<ll> diag1, diag2; // diag1: i-j, diag2: i+j

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    for (ll i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
    }

    ll total_attacked = 0;

    // Rows and columns
    total_attacked += (ll)rows.size() * N; // all squares in attacked rows
    total_attacked += (ll)cols.size() * N; // all squares in attacked columns

    // Diagonals (diag1: i-j)
    for (ll d : diag1) {
        ll count = min(N, N + d) - max(1LL, 1LL + d) + 1;
        total_attacked += count;
    }

    // Anti-diagonals (diag2: i+j)
    for (ll s : diag2) {
        if (s < 2 || s > 2 * N) continue;
        ll count = min(s - 1, 2 * N + 1 - s) - max(s - N, 1LL) + 1;
        total_attacked += count;
    }

    // Subtract overlaps

    // Row-Column intersections (pieces already counted once, now subtract overcount)
    for (ll r : rows) {
        for (ll c : cols) {
            total_attacked -= 1; // square (r,c) was counted in both row and column
        }
    }

    // Row-Diag1 intersections
    for (ll r : rows) {
        for (ll d : diag1) {
            ll c = r - d;
            if (1 <= c && c <= N) {
                total_attacked -= 1; // square (r,c) was counted in row and diag1
            }
        }
    }

    // Row-Diag2 intersections
    for (ll r : rows) {
        for (ll s : diag2) {
            ll c = s - r;
            if (1 <= c && c <= N) {
                total_attacked -= 1; // square (r,c) was counted in row and diag2
            }
        }
    }

    // Col-Diag1 intersections
    for (ll c : cols) {
        for (ll d : diag1) {
            ll r = d + c;
            if (1 <= r && r <= N) {
                total_attacked -= 1; // square (r,c) was counted in col and diag1
            }
        }
    }

    // Col-Diag2 intersections
    for (ll c : cols) {
        for (ll s : diag2) {
            ll r = s - c;
            if (1 <= r && r <= N) {
                total_attacked -= 1; // square (r,c) was counted in col and diag2
            }
        }
    }

    // Diag1-Diag2 intersections (the actual pieces)
    for (ll d : diag1) {
        for (ll s : diag2) {
            ll r = (s + d) / 2;
            ll c = s - r;
            if (1 <= r && r <= N && 1 <= c && c <= N && (r - c) == d && (r + c) == s) {
                total_attacked -= 1; // square (r,c) was counted in diag1 and diag2
            }
        }
    }

    // Add back triple overlaps if needed
    // In this problem, we only have M <= 1e3, so we can check each piece explicitly

    ll total_pieces = N * N;
    ll available = total_pieces - total_attacked;

    cout << available << endl;

    return 0;
}