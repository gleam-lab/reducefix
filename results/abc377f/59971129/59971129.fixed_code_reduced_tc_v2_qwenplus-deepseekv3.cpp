#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll N, M;
    cin >> N >> M;
    
    set<ll> rows, cols, diag1, diag2;
    set<pair<ll, ll>> pieces;
    
    for (int i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
        pieces.insert({a, b});
    }
    
    ll unsafe_rows = rows.size();
    ll unsafe_cols = cols.size();
    ll unsafe_diag1 = diag1.size();
    ll unsafe_diag2 = diag2.size();
    
    // Calculate the total number of squares under attack from rows, columns, and diagonals
    ll total_unsafe = 0;
    
    // Rows and columns
    total_unsafe += unsafe_rows * N + unsafe_cols * N - unsafe_rows * unsafe_cols;
    
    // Diagonals (i - j = constant)
    for (auto d : diag1) {
        ll i_minus_j = d;
        // The number of squares on the diagonal i - j = d is min(N, N - abs(d))
        ll cnt = N - abs(i_minus_j);
        if (i_minus_j >= 0) {
            cnt = min(N, N - i_minus_j);
        } else {
            cnt = min(N, N + i_minus_j);
        }
        total_unsafe += cnt;
    }
    
    // Diagonals (i + j = constant)
    for (auto d : diag2) {
        ll i_plus_j = d;
        // The number of squares on the diagonal i + j = d is min(N, d - 1) - max(1, d - N) + 1
        ll lower = max(1LL, i_plus_j - N);
        ll upper = min(N, i_plus_j - 1);
        ll cnt = upper - lower + 1;
        total_unsafe += cnt;
    }
    
    // Now, subtract the overlaps between diagonals and rows/columns
    // Also, subtract the intersections between diagonals themselves
    // But since M is small, we can iterate through all pieces and count the overlaps
    
    set<pair<ll, ll>> attacked;
    
    // Add all squares attacked by rows and columns
    for (auto r : rows) {
        for (ll j = 1; j <= N; ++j) {
            attacked.insert({r, j});
        }
    }
    for (auto c : cols) {
        for (ll i = 1; i <= N; ++i) {
            attacked.insert({i, c});
        }
    }
    
    // Add all squares attacked by diagonals
    for (auto d : diag1) {
        ll i_minus_j = d;
        ll i_start = max(1LL, 1 + i_minus_j);
        ll i_end = min(N, N + i_minus_j);
        for (ll i = i_start; i <= i_end; ++i) {
            ll j = i - i_minus_j;
            attacked.insert({i, j});
        }
    }
    for (auto d : diag2) {
        ll i_plus_j = d;
        ll i_start = max(1LL, i_plus_j - N);
        ll i_end = min(N, i_plus_j - 1);
        for (ll i = i_start; i <= i_end; ++i) {
            ll j = i_plus_j - i;
            attacked.insert({i, j});
        }
    }
    
    // The total unsafe squares is the size of the attacked set
    total_unsafe = attacked.size();
    
    // The answer is total squares (N*N) minus total_unsafe, but since existing pieces are already placed, they are not empty
    ll answer = N * N - total_unsafe - M + pieces.size();
    
    // But if the existing pieces are already counted in the attacked set, no need to subtract M
    // So the correct answer is N*N - total_unsafe
    // Because pieces are already in the attacked set (they attack themselves)
    answer = N * N - total_unsafe;
    
    cout << answer << endl;
    
    return 0;
}