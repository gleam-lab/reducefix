#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    i64 N, M;
    cin >> N >> M;
    vector<pair<i64, i64>> pieces(M);
    set<i64> rows, cols, diag1, diag2;
    
    for (int i = 0; i < M; ++i) {
        i64 a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }
    
    i64 total_attacked = 0;
    
    // Rows: each row attacks N squares, but overlaps with cols and diags
    total_attacked += rows.size() * N;
    
    // Cols: each col attacks N squares, overlaps with rows and diags
    total_attacked += cols.size() * N;
    
    // Diagonals (i+j): for each a+b, the number of squares is min(N, a+b-1) - max(1, a+b-N) + 1
    for (i64 d : diag1) {
        i64 start = max(1LL, d - N);
        i64 end = min(N, d - 1);
        total_attacked += (end - start + 1);
    }
    
    // Diagonals (i-j): for each a-b, the number of squares is min(N, N + a - b) - max(1, 1 + a - b) + 1
    for (i64 d : diag2) {
        i64 start = max(1LL, 1 + d);
        i64 end = min(N, N + d);
        total_attacked += (end - start + 1);
    }
    
    // Overlaps between rows and cols: each (row, col) intersection is counted twice
    total_attacked -= rows.size() * cols.size();
    
    // Overlaps between rows and diag1: for each row a, if (a + b) is in diag1, then (a, b) is in both
    // Similarly for other overlaps, but it's complex, so we use inclusion-exclusion
    // Instead, count the unique squares from all attacks
    set<pair<i64, i64>> attacked;
    
    for (auto [a, b] : pieces) {
        // Row a
        for (i64 j = 1; j <= N; ++j) {
            attacked.insert({a, j});
        }
        // Column b
        for (i64 i = 1; i <= N; ++i) {
            attacked.insert({i, b});
        }
        // Diagonal a + b
        i64 sum = a + b;
        i64 start_i = max(1LL, sum - N);
        i64 end_i = min(N, sum - 1);
        for (i64 i = start_i; i <= end_i; ++i) {
            i64 j = sum - i;
            attacked.insert({i, j});
        }
        // Diagonal a - b
        i64 diff = a - b;
        i64 start_i2 = max(1LL, 1 + diff);
        i64 end_i2 = min(N, N + diff);
        for (i64 i = start_i2; i <= end_i2; ++i) {
            i64 j = i - diff;
            attacked.insert({i, j});
        }
    }
    
    // The occupied pieces are already in 'attacked', so safe squares are N^2 - attacked.size()
    // But existing pieces are not empty, so they shouldn't be counted as safe
    i64 answer = N * N - attacked.size();
    
    cout << answer << endl;
    
    return 0;
}