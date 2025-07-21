#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    ll N, M;
    cin >> N >> M;
    set<ll> rows, cols, diag1, diag2;
    set<pair<ll, ll>> pieces;

    for (int i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        pieces.insert({a, b});
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
    }

    ll threatened = 0;

    // Rows and columns
    threatened += rows.size() * N;
    threatened += cols.size() * N;

    // Diagonals (a - b = constant)
    for (auto d : diag1) {
        // The number of squares on the diagonal a - b = d
        ll count;
        if (d >= 0) {
            count = N - d;
        } else {
            count = N + d;
        }
        threatened += count;
    }

    // Anti-diagonals (a + b = constant)
    for (auto d : diag2) {
        // The number of squares on the anti-diagonal a + b = d
        ll count;
        if (d <= N + 1) {
            count = d - 1;
        } else {
            count = 2 * N - d + 1;
        }
        threatened += count;
    }

    // Now subtract the overlaps between rows, columns, diag1, diag2
    // For each piece, it is counted in row, column, diag1, and diag2: 4 times
    // So subtract 3 for each piece (since it was counted 4 times, should only be once)
    threatened -= 3 * M;

    // Additionally, the intersections between rows and columns, rows and diags, etc.
    // Have to add back the squares that were subtracted multiple times
    // For example, intersections between row and column: for each (a_k, b_k), it was subtracted once as row and once as column, but these are the same square
    // So for each piece, intersections are:
    // row-col: already counted
    // row-diag1: if (a_k - b_k) is in diag1, then the square is (a_k, a_k - d), but only if it's in the grid
    // Similarly for other combinations

    // To handle these, we can use inclusion-exclusion principle, but it's complex for all pairs
    // Instead, for each piece, check how many of the four sets (row, col, diag1, diag2) it belongs to
    // For each piece, it's counted in all four, so subtract 3 to correct
    // Then, the intersections between any two sets (row-col, row-diag1, etc.) are the pieces themselves unless they share a square outside the pieces

    // However, it's easier to compute the distinct squares covered by rows, cols, diag1, diag2
    // We can use inclusion-exclusion for these four sets

    // But for large N and M, it's impractical to iterate all possible squares
    // So instead, we compute the total distinct squares:
    // total = |rows|*N + |cols|*N - |rows|*|cols| (row-col intersections)
    // + sum_(d in diag1) (count diag1 squares not in rows or cols)
    // + sum_(d in diag2) (count diag2 squares not in rows or cols)
    // But this is also complex

    // Alternative approach: compute the set of all threatened squares
    // Since M is up to 1e3, we can iterate all pieces and collect all squares they threaten, then count distinct squares

    set<pair<ll, ll>> threatened_squares;
    for (auto piece : pieces) {
        ll a = piece.first;
        ll b = piece.second;
        // Row a
        for (ll j = 1; j <= N; ++j) {
            threatened_squares.insert({a, j});
        }
        // Column b
        for (ll i = 1; i <= N; ++i) {
            threatened_squares.insert({i, b});
        }
        // Diagonal a - b = i - j => j = i - (a - b)
        ll d1 = a - b;
        ll i_min = max(1LL, 1LL + d1);
        ll i_max = min(N, N + d1);
        for (ll i = i_min; i <= i_max; ++i) {
            ll j = i - d1;
            threatened_squares.insert({i, j});
        }
        // Anti-diagonal a + b = i + j => j = (a + b) - i
        ll d2 = a + b;
        ll i_min2 = max(1LL, d2 - N);
        ll i_max2 = min(N, d2 - 1);
        for (ll i = i_min2; i <= i_max2; ++i) {
            ll j = d2 - i;
            threatened_squares.insert({i, j});
        }
    }

    ll total_threatened = threatened_squares.size();
    ll total_safe = N * N - total_threatened;

    cout << total_safe << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}