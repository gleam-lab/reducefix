#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
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
    
    i64 total = 0;
    
    // Rows and columns
    total += rows.size() * N;
    total += cols.size() * N;
    
    // Diagonals (i + j = k)
    for (i64 k : diag1) {
        i64 lower = max(1LL, k - N);
        i64 upper = min(N, k - 1);
        if (lower <= upper) {
            total += upper - lower + 1;
        }
    }
    
    // Anti-diagonals (i - j = k)
    for (i64 k : diag2) {
        i64 lower = max(1LL, 1 + k);
        i64 upper = min(N, N + k);
        if (lower <= upper) {
            total += upper - lower + 1;
        }
    }
    
    // Intersections: row or column with a diagonal or anti-diagonal
    set<pair<i64, i64>> intersections;
    for (i64 a : rows) {
        for (i64 k : diag1) {
            i64 b = k - a;
            if (b >= 1 && b <= N) {
                intersections.insert({a, b});
            }
        }
        for (i64 k : diag2) {
            i64 b = a - k;
            if (b >= 1 && b <= N) {
                intersections.insert({a, b});
            }
        }
    }
    for (i64 b : cols) {
        for (i64 k : diag1) {
            i64 a = k - b;
            if (a >= 1 && a <= N) {
                intersections.insert({a, b});
            }
        }
        for (i64 k : diag2) {
            i64 a = b + k;
            if (a >= 1 && a <= N) {
                intersections.insert({a, b});
            }
        }
    }
    
    // Subtract the intersections
    total -= intersections.size();
    
    // Add back the pieces themselves (since they were subtracted multiple times)
    set<pair<i64, i64>> existing_pieces(pieces.begin(), pieces.end());
    total += existing_pieces.size();
    
    // The answer is N^2 - total_attacked_squares + existing_pieces (since existing pieces are not empty)
    i64 answer = N * N - total + existing_pieces.size();
    
    // However, existing pieces are already counted in total_attacked_squares, so no need to add them again.
    // Correct formula: answer = N^2 - (total - existing_pieces.size())
    answer = N * N - (total - existing_pieces.size());
    
    cout << answer << "\n";
    
    return 0;
}