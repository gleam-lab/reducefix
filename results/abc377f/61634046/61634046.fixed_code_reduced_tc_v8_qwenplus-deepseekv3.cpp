#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;
    
    unordered_set<long long> rows, cols, diags, anti_diags;
    set<pair<long long, long long>> pieces;
    
    for (long long i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        pieces.insert({a, b});
        rows.insert(a);
        cols.insert(b);
        diags.insert(a + b);
        anti_diags.insert(a - b);
    }
    
    long long total_squares = N * N;
    long long attacked_squares = 0;
    
    // Calculate squares attacked by rows
    attacked_squares += rows.size() * N;
    
    // Calculate squares attacked by columns
    attacked_squares += cols.size() * N;
    
    // Calculate squares attacked by diagonals (a + b)
    for (long long d : diags) {
        long long min_a = max(1LL, d - N);
        long long max_a = min(N, d - 1);
        if (max_a >= min_a) {
            attacked_squares += (max_a - min_a + 1);
        }
    }
    
    // Calculate squares attacked by anti-diagonals (a - b)
    for (long long d : anti_diags) {
        long long min_a = max(1LL, 1 + d);
        long long max_a = min(N, N + d);
        if (max_a >= min_a) {
            attacked_squares += (max_a - min_a + 1);
        }
    }
    
    // Subtract overlaps between rows and columns
    attacked_squares -= rows.size() * cols.size();
    
    // Subtract overlaps between rows and diagonals
    for (long long r : rows) {
        for (long long d : diags) {
            long long b = d - r;
            if (b >= 1 && b <= N) {
                if (pieces.count({r, b}) == 0) {
                    attacked_squares--;
                }
            }
        }
    }
    
    // Subtract overlaps between rows and anti-diagonals
    for (long long r : rows) {
        for (long long d : anti_diags) {
            long long b = r - d;
            if (b >= 1 && b <= N) {
                if (pieces.count({r, b}) == 0) {
                    attacked_squares--;
                }
            }
        }
    }
    
    // Subtract overlaps between columns and diagonals
    for (long long c : cols) {
        for (long long d : diags) {
            long long a = d - c;
            if (a >= 1 && a <= N) {
                if (pieces.count({a, c}) == 0) {
                    attacked_squares--;
                }
            }
        }
    }
    
    // Subtract overlaps between columns and anti-diagonals
    for (long long c : cols) {
        for (long long d : anti_diags) {
            long long a = d + c;
            if (a >= 1 && a <= N) {
                if (pieces.count({a, c}) == 0) {
                    attacked_squares--;
                }
            }
        }
    }
    
    // Subtract overlaps between diagonals and anti-diagonals
    for (long long d1 : diags) {
        for (long long d2 : anti_diags) {
            long long a = (d1 + d2) / 2;
            long long b = (d1 - d2) / 2;
            if (a >= 1 && a <= N && b >= 1 && b <= N) {
                if (pieces.count({a, b}) == 0) {
                    attacked_squares--;
                }
            }
        }
    }
    
    // Add back squares where all four conditions meet (they were subtracted too many times)
    for (auto p : pieces) {
        long long a = p.first;
        long long b = p.second;
        if (rows.count(a) && cols.count(b) && diags.count(a + b) && anti_diags.count(a - b)) {
            attacked_squares++;
        }
    }
    
    long long safe_squares = total_squares - attacked_squares;
    cout << safe_squares << endl;
    
    return 0;
}