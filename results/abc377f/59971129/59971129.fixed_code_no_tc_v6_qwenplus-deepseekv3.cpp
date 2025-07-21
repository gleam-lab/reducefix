#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll N, M;
    cin >> N >> M;

    set<ll> rows, cols, diag1, diag2;
    set<pair<ll, ll>> occupied;

    for (int i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
        occupied.insert({a, b});
    }

    ll forbidden = 0;

    // Forbidden due to rows and columns
    forbidden += rows.size() * N + cols.size() * (N - rows.size());

    // Forbidden due to diagonals (a - b)
    for (auto d : diag1) {
        ll start_row, start_col;
        if (d >= 0) {
            start_row = 1 + d;
            start_col = 1;
        } else {
            start_row = 1;
            start_col = 1 - d;
        }
        ll count = min(N - start_row + 1, N - start_col + 1);
        forbidden += count;
    }

    // Forbidden due to anti-diagonals (a + b)
    for (auto s : diag2) {
        ll start_row, start_col;
        if (s <= N + 1) {
            start_row = 1;
            start_col = s - 1;
        } else {
            start_row = s - N;
            start_col = N;
        }
        ll count = min(N - start_row + 1, start_col);
        forbidden += count;
    }

    // Subtract overlaps between rows/columns and diagonals/anti-diagonals
    // Also subtract already occupied squares
    ll total_squares = N * N;
    ll safe_squares = total_squares - forbidden - M;
    
    cout << safe_squares << endl;

    return 0;
}