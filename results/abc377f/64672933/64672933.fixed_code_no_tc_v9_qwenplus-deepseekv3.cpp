#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    i64 N, M;
    cin >> N >> M;
    vector<array<i64, 2>> pieces(M);
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
    
    i64 unsafe_rows = rows.size() * N;
    i64 unsafe_cols = cols.size() * N;
    
    i64 unsafe_diag1 = 0;
    for (auto s : diag1) {
        i64 min_xy = max(1LL, s - N);
        i64 max_xy = min(N, s - 1);
        if (max_xy >= min_xy) {
            unsafe_diag1 += max_xy - min_xy + 1;
        }
    }
    
    i64 unsafe_diag2 = 0;
    for (auto d : diag2) {
        i64 min_xy = max(1LL, 1 - d);
        i64 max_xy = min(N, N - d);
        if (max_xy >= min_xy) {
            unsafe_diag2 += max_xy - min_xy + 1;
        }
    }
    
    i64 unsafe_rows_cols = rows.size() * cols.size();
    
    i64 unsafe_rows_diag1 = 0;
    for (auto r : rows) {
        for (auto s : diag1) {
            i64 c = s - r;
            if (c >= 1 && c <= N) {
                unsafe_rows_diag1++;
            }
        }
    }
    
    i64 unsafe_rows_diag2 = 0;
    for (auto r : rows) {
        for (auto d : diag2) {
            i64 c = r - d;
            if (c >= 1 && c <= N) {
                unsafe_rows_diag2++;
            }
        }
    }
    
    i64 unsafe_cols_diag1 = 0;
    for (auto c : cols) {
        for (auto s : diag1) {
            i64 r = s - c;
            if (r >= 1 && r <= N) {
                unsafe_cols_diag1++;
            }
        }
    }
    
    i64 unsafe_cols_diag2 = 0;
    for (auto c : cols) {
        for (auto d : diag2) {
            i64 r = d + c;
            if (r >= 1 && r <= N) {
                unsafe_cols_diag2++;
            }
        }
    }
    
    i64 unsafe_diag1_diag2 = 0;
    for (auto s : diag1) {
        for (auto d : diag2) {
            if ((s + d) % 2 == 0) {
                i64 r = (s + d) / 2;
                i64 c = (s - d) / 2;
                if (r >= 1 && r <= N && c >= 1 && c <= N) {
                    unsafe_diag1_diag2++;
                }
            }
        }
    }
    
    i64 unsafe_rows_cols_diag1 = 0;
    for (auto r : rows) {
        for (auto c : cols) {
            if (diag1.count(r + c)) {
                unsafe_rows_cols_diag1++;
            }
        }
    }
    
    i64 unsafe_rows_cols_diag2 = 0;
    for (auto r : rows) {
        for (auto c : cols) {
            if (diag2.count(r - c)) {
                unsafe_rows_cols_diag2++;
            }
        }
    }
    
    i64 unsafe_rows_diag1_diag2 = 0;
    for (auto r : rows) {
        for (auto s : diag1) {
            i64 c = s - r;
            if (c >= 1 && c <= N && diag2.count(r - c)) {
                unsafe_rows_diag1_diag2++;
            }
        }
    }
    
    i64 unsafe_cols_diag1_diag2 = 0;
    for (auto c : cols) {
        for (auto s : diag1) {
            i64 r = s - c;
            if (r >= 1 && r <= N && diag2.count(r - c)) {
                unsafe_cols_diag1_diag2++;
            }
        }
    }
    
    i64 unsafe_all = 0;
    for (auto r : rows) {
        for (auto c : cols) {
            if (diag1.count(r + c) && diag2.count(r - c)) {
                unsafe_all++;
            }
        }
    }
    
    i64 total_unsafe = unsafe_rows + unsafe_cols + unsafe_diag1 + unsafe_diag2 
                     - unsafe_rows_cols - unsafe_rows_diag1 - unsafe_rows_diag2 
                     - unsafe_cols_diag1 - unsafe_cols_diag2 - unsafe_diag1_diag2 
                     + unsafe_rows_cols_diag1 + unsafe_rows_cols_diag2 
                     + unsafe_rows_diag1_diag2 + unsafe_cols_diag1_diag2 
                     - unsafe_all;
    
    i64 total_pieces = M;
    i64 safe_squares = N * N - total_unsafe + total_pieces;
    
    cout << safe_squares << "\n";
    
    return 0;
}