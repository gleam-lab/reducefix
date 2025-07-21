#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

const int MAX_M = 2000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N;
    int M;
    cin >> N >> M;

    set<pii> occupied;
    set<ll> rows, cols, diag1, diag2;

    for (int i = 0; i < M; ++i) {
        ll r, c;
        cin >> r >> c;
        occupied.emplace(r, c);
        rows.insert(r);
        cols.insert(c);
        diag1.insert(r - c);      // For anti-diagonal (row - col)
        diag2.insert(r + c);      // For diagonal (row + col)
    }

    // Total dangerous squares
    set<pii> dangerous;

    // Add all squares in the same row
    for (ll r : rows) {
        for (ll c = 1; c <= N; ++c) {
            if (!occupied.count({r, c}))
                dangerous.insert({r, c});
        }
    }

    // Add all squares in the same column
    for (ll c : cols) {
        for (ll r = 1; r <= N; ++r) {
            if (!occupied.count({r, c}))
                dangerous.insert({r, c});
        }
    }

    // Add all squares in the same anti-diagonal (r - c)
    for (ll d : diag1) {
        // Iterate over all possible (r,c) such that r - c = d
        // This is a line from (max(1, d+1), max(1-d, 1)) to (min(N, N+d), min(N-d, N))
        ll r_start = max(1LL, d + 1);
        ll r_end = min(N, N + d);
        for (ll r = r_start; r <= r_end; ++r) {
            ll c = r - d;
            if (1 <= c && c <= N && !occupied.count({r, c}))
                dangerous.insert({r, c});
        }
    }

    // Add all squares in the same diagonal (r + c)
    for (ll s : diag2) {
        // Iterate over all possible (r,c) such that r + c = s
        // r ranges from max(1, s - N) to min(N, s - 1)
        ll r_start = max(1LL, s - N);
        ll r_end = min(N, s - 1);
        for (ll r = r_start; r <= r_end; ++r) {
            ll c = s - r;
            if (1 <= c && c <= N && !occupied.count({r, c}))
                dangerous.insert({r, c});
        }
    }

    // Total number of empty squares
    ll total_empty = N * N - M;

    // Dangerous squares have already been counted
    ll safe_count = total_empty - dangerous.size();

    cout << safe_count << endl;

    return 0;
}