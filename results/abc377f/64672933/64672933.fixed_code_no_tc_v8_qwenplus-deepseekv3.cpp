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
    
    i64 unsafe = 0;
    
    // Squares in same rows
    unsafe += rows.size() * N;
    // Squares in same columns
    unsafe += cols.size() * N;
    // Squares in same diag1 (a + b)
    for (i64 s : diag1) {
        i64 min_x = max(1LL, s - N);
        i64 max_x = min(N, s - 1);
        if (max_x >= min_x) {
            unsafe += (max_x - min_x + 1);
        }
    }
    // Squares in same diag2 (a - b)
    for (i64 d : diag2) {
        i64 min_x = max(1LL, 1 + d);
        i64 max_x = min(N, N + d);
        if (max_x >= min_x) {
            unsafe += (max_x - min_x + 1);
        }
    }
    
    // Subtract overlaps between rows and columns
    unsafe -= rows.size() * cols.size();
    // Subtract overlaps between rows and diag1
    for (i64 r : rows) {
        for (i64 s : diag1) {
            i64 c = s - r;
            if (cols.count(c)) {
                unsafe--;
            }
        }
    }
    // Subtract overlaps between rows and diag2
    for (i64 r : rows) {
        for (i64 d : diag2) {
            i64 c = r - d;
            if (cols.count(c)) {
                unsafe--;
            }
        }
    }
    // Subtract overlaps between columns and diag1
    for (i64 c : cols) {
        for (i64 s : diag1) {
            i64 r = s - c;
            if (rows.count(r)) {
                unsafe--;
            }
        }
    }
    // Subtract overlaps between columns and diag2
    for (i64 c : cols) {
        for (i64 d : diag2) {
            i64 r = d + c;
            if (rows.count(r)) {
                unsafe--;
            }
        }
    }
    // Subtract overlaps between diag1 and diag2
    for (i64 s : diag1) {
        for (i64 d : diag2) {
            if ((s + d) % 2 == 0) {
                i64 r = (s + d) / 2;
                i64 c = (s - d) / 2;
                if (rows.count(r) && cols.count(c)) {
                    unsafe--;
                }
            }
        }
    }
    
    // Subtract the original pieces themselves (they were added multiple times)
    unsafe -= M;
    
    i64 total = N * N;
    i64 safe = total - unsafe;
    cout << safe << "\n";
    
    return 0;
}