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
    
    i64 total = N * N;
    i64 threatened = 0;
    
    // Squares threatened by rows
    threatened += rows.size() * N;
    
    // Squares threatened by columns
    threatened += cols.size() * N;
    
    // Squares threatened by diagonals i+j
    for (i64 d : diag1) {
        i64 min_xy = max(1LL, d - N);
        i64 max_xy = min(N, d - 1);
        if (max_xy >= min_xy) {
            threatened += (max_xy - min_xy + 1);
        }
    }
    
    // Squares threatened by diagonals i-j
    for (i64 d : diag2) {
        i64 min_xy = max(1LL, 1 - d);
        i64 max_xy = min(N, N - d);
        if (max_xy >= min_xy) {
            threatened += (max_xy - min_xy + 1);
        }
    }
    
    // Subtract overlaps between rows and columns (counted twice)
    threatened -= rows.size() * cols.size();
    
    // Subtract overlaps between rows and diag1 (counted twice)
    for (i64 r : rows) {
        for (i64 d : diag1) {
            i64 c = d - r;
            if (cols.count(c)) {
                threatened--;
            }
        }
    }
    
    // Subtract overlaps between rows and diag2 (counted twice)
    for (i64 r : rows) {
        for (i64 d : diag2) {
            i64 c = r - d;
            if (cols.count(c)) {
                threatened--;
            }
        }
    }
    
    // Subtract overlaps between columns and diag1 (counted twice)
    for (i64 c : cols) {
        for (i64 d : diag1) {
            i64 r = d - c;
            if (rows.count(r)) {
                threatened--;
            }
        }
    }
    
    // Subtract overlaps between columns and diag2 (counted twice)
    for (i64 c : cols) {
        for (i64 d : diag2) {
            i64 r = d + c;
            if (rows.count(r)) {
                threatened--;
            }
        }
    }
    
    // Subtract overlaps between diag1 and diag2 (counted twice)
    for (i64 d1 : diag1) {
        for (i64 d2 : diag2) {
            if ((d1 + d2) % 2 == 0) {
                i64 r = (d1 + d2) / 2;
                i64 c = (d1 - d2) / 2;
                if (rows.count(r) && cols.count(c)) {
                    threatened--;
                }
            }
        }
    }
    
    // Add back pieces that are counted multiple times in overlaps (inclusion-exclusion)
    threatened += M;
    
    // The answer is total squares minus threatened squares, but pieces are already placed and not empty
    i64 answer = total - threatened;
    cout << answer << "\n";
    
    return 0;
}