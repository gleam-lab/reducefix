#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

int main() {
    ll N, M;
    cin >> N >> M;

    set<pll> occupied;
    set<ll> rows, cols, diag1, diag2;

    for (ll i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        occupied.insert({a, b});
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
    }

    // Total empty squares = total - occupied
    ll total_empty = N * N - M;

    // Squares under attack
    set<pll> attacked;

    // Add all squares in the same row and column of each piece
    for (const auto& p : occupied) {
        ll r = p.first, c = p.second;
        // Row
        for (ll j = 1; j <= N; ++j) {
            if (j != c) attacked.insert({r, j});
        }
        // Column
        for (ll i = 1; i <= N; ++i) {
            if (i != r) attacked.insert({i, c});
        }
    }

    // Add diagonals
    for (const auto& d : diag1) {
        // Diagonal a - b = d
        ll start_row = max(1LL, d + 1);
        ll end_row = min(N, N + d);
        for (ll r = start_row; r <= end_row; ++r) {
            ll c = r - d;
            attacked.insert({r, c});
        }
    }

    for (const auto& d : diag2) {
        // Anti-diagonal a + b = d
        ll start_row = max(1LL, d - N);
        ll end_row = min(N, d - 1);
        for (ll r = start_row; r <= end_row; ++r) {
            ll c = d - r;
            if (c >= 1 && c <= N) {
                attacked.insert({r, c});
            }
        }
    }

    // Remove occupied from attacked to avoid double counting
    for (const auto& p : occupied) {
        attacked.erase(p);
    }

    // The number of safe positions is total empty - attacked and not occupied
    ll safe_positions = total_empty - attacked.size();

    cout << safe_positions;

    return 0;
}