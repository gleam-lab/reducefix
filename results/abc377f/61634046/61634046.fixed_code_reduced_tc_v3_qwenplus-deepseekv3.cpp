#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N, M;
    cin >> N >> M;
    
    unordered_set<int64_t> rows, cols, diag1, diag2;
    for (int i = 0; i < M; ++i) {
        int64_t a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }
    
    int64_t total = N * N;
    
    int64_t dangerous_rows = rows.size() * N;
    int64_t dangerous_cols = cols.size() * N;
    int64_t dangerous_diag1 = 0;
    for (auto d : diag1) {
        int64_t min_sum = 2;
        int64_t max_sum = 2 * N;
        if (d < min_sum || d > max_sum) continue;
        int64_t len;
        if (d <= N + 1) {
            len = d - 1;
        } else {
            len = 2 * N - d + 1;
        }
        dangerous_diag1 += len;
    }
    int64_t dangerous_diag2 = 0;
    for (auto d : diag2) {
        int64_t min_diff = -(N - 1);
        int64_t max_diff = N - 1;
        if (d < min_diff || d > max_diff) continue;
        int64_t len;
        if (d <= 0) {
            len = N + d;
        } else {
            len = N - d;
        }
        dangerous_diag2 += len;
    }
    
    int64_t dangerous_row_col = rows.size() * cols.size();
    
    int64_t dangerous_row_diag1 = 0;
    for (auto r : rows) {
        for (auto d : diag1) {
            int64_t c = d - r;
            if (1 <= c && c <= N) {
                dangerous_row_diag1++;
            }
        }
    }
    
    int64_t dangerous_row_diag2 = 0;
    for (auto r : rows) {
        for (auto d : diag2) {
            int64_t c = r - d;
            if (1 <= c && c <= N) {
                dangerous_row_diag2++;
            }
        }
    }
    
    int64_t dangerous_col_diag1 = 0;
    for (auto c : cols) {
        for (auto d : diag1) {
            int64_t r = d - c;
            if (1 <= r && r <= N) {
                dangerous_col_diag1++;
            }
        }
    }
    
    int64_t dangerous_col_diag2 = 0;
    for (auto c : cols) {
        for (auto d : diag2) {
            int64_t r = d + c;
            if (1 <= r && r <= N) {
                dangerous_col_diag2++;
            }
        }
    }
    
    int64_t dangerous_diag1_diag2 = 0;
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            int64_t r = (d1 + d2) / 2;
            int64_t c = (d1 - d2) / 2;
            if ((d1 + d2) % 2 == 0 && (d1 - d2) % 2 == 0 && 1 <= r && r <= N && 1 <= c && c <= N) {
                dangerous_diag1_diag2++;
            }
        }
    }
    
    int64_t dangerous_row_col_diag1 = 0;
    for (auto r : rows) {
        for (auto c : cols) {
            if (diag1.find(r + c) != diag1.end()) {
                dangerous_row_col_diag1++;
            }
        }
    }
    
    int64_t dangerous_row_col_diag2 = 0;
    for (auto r : rows) {
        for (auto c : cols) {
            if (diag2.find(r - c) != diag2.end()) {
                dangerous_row_col_diag2++;
            }
        }
    }
    
    int64_t dangerous_row_diag1_diag2 = 0;
    for (auto r : rows) {
        for (auto d1 : diag1) {
            int64_t c = d1 - r;
            if (1 <= c && c <= N && diag2.find(r - c) != diag2.end()) {
                dangerous_row_diag1_diag2++;
            }
        }
    }
    
    int64_t dangerous_col_diag1_diag2 = 0;
    for (auto c : cols) {
        for (auto d1 : diag1) {
            int64_t r = d1 - c;
            if (1 <= r && r <= N && diag2.find(r - c) != diag2.end()) {
                dangerous_col_diag1_diag2++;
            }
        }
    }
    
    int64_t dangerous_row_col_diag1_diag2 = 0;
    for (auto r : rows) {
        for (auto c : cols) {
            if (diag1.find(r + c) != diag1.end() && diag2.find(r - c) != diag2.end()) {
                dangerous_row_col_diag1_diag2++;
            }
        }
    }
    
    int64_t dangerous_total = dangerous_rows + dangerous_cols + dangerous_diag1 + dangerous_diag2
                            - dangerous_row_col - dangerous_row_diag1 - dangerous_row_diag2 - dangerous_col_diag1 - dangerous_col_diag2 - dangerous_diag1_diag2
                            + dangerous_row_col_diag1 + dangerous_row_col_diag2 + dangerous_row_diag1_diag2 + dangerous_col_diag1_diag2
                            - dangerous_row_col_diag1_diag2;
    
    int64_t safe = total - dangerous_total;
    cout << safe << endl;
    
    return 0;
}