#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    i64 N, M;
    cin >> N >> M;
    vector<array<i64, 2>> pieces(M);
    unordered_set<i64> rows, cols, sum_diags, diff_diags;
    for (int i = 0; i < M; ++i) {
        i64 a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
        rows.insert(a);
        cols.insert(b);
        sum_diags.insert(a + b);
        diff_diags.insert(a - b);
    }
    
    i64 total_attacked = 0;
    
    // Rows and columns
    i64 unique_rows = rows.size();
    i64 unique_cols = cols.size();
    total_attacked += unique_rows * N + unique_cols * N - unique_rows * unique_cols;
    
    // Sum diagonals (i + j = k)
    i64 unique_sum = sum_diags.size();
    for (i64 k : sum_diags) {
        i64 min_ij = max(1LL, k - N);
        i64 max_ij = min(N, k - 1);
        if (max_ij < min_ij) continue;
        total_attacked += (max_ij - min_ij + 1);
    }
    
    // Difference diagonals (i - j = k)
    i64 unique_diff = diff_diags.size();
    for (i64 k : diff_diags) {
        i64 min_i = max(1LL, 1 + k);
        i64 max_i = min(N, N + k);
        if (max_i < min_i) continue;
        total_attacked += (max_i - min_i + 1);
    }
    
    // Subtract intersections between rows, columns, and diagonals
    // Intersection of row and sum diagonal: (a, k - a)
    for (i64 a : rows) {
        for (i64 k : sum_diags) {
            i64 b = k - a;
            if (b >= 1 && b <= N) {
                total_attacked--;
            }
        }
    }
    
    // Intersection of row and difference diagonal: (a, a - k)
    for (i64 a : rows) {
        for (i64 k : diff_diags) {
            i64 b = a - k;
            if (b >= 1 && b <= N) {
                total_attacked--;
            }
        }
    }
    
    // Intersection of column and sum diagonal: (k - b, b)
    for (i64 b : cols) {
        for (i64 k : sum_diags) {
            i64 a = k - b;
            if (a >= 1 && a <= N) {
                total_attacked--;
            }
        }
    }
    
    // Intersection of column and difference diagonal: (b + k, b)
    for (i64 b : cols) {
        for (i64 k : diff_diags) {
            i64 a = b + k;
            if (a >= 1 && a <= N) {
                total_attacked--;
            }
        }
    }
    
    // Intersection of sum and difference diagonals: ( (k1 + k2)/2, (k1 - k2)/2 )
    for (i64 k1 : sum_diags) {
        for (i64 k2 : diff_diags) {
            if ((k1 + k2) % 2 != 0) continue;
            i64 a = (k1 + k2) / 2;
            i64 b = (k1 - k2) / 2;
            if (a >= 1 && b >= 1 && a <= N && b <= N) {
                total_attacked--;
            }
        }
    }
    
    // Add back intersections that were subtracted three times
    for (i64 a : rows) {
        for (i64 b : cols) {
            if (sum_diags.count(a + b) && diff_diags.count(a - b)) {
                total_attacked += 2; // because it was subtracted three times
            }
        }
    }
    
    // Subtract the original M pieces, as they were counted in rows, cols, and diagonals
    total_attacked -= M;
    
    i64 safe_squares = N * N - total_attacked;
    cout << safe_squares << "\n";
    
    return 0;
}