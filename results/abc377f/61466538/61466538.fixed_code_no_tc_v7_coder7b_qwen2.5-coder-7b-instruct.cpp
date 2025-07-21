#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

const long long MOD = 1e9 + 7;

int main() {
    long long N, M;
    cin >> N >> M;
    
    unordered_set<long long> rows, cols, diags1, diags2;
    
    for(long long i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diags1.insert(a - b);
        diags2.insert(a + b);
    }
    
    long long total_squares = N * N;
    long long occupied_by_rows = rows.size() * N;
    long long occupied_by_cols = cols.size() * N;
    long long occupied_by_diags1 = diags1.size() * N;
    long long occupied_by_diags2 = diags2.size() * N;
    
    // Squares occupied by both rows and columns (overcounted)
    long long occupied_by_rows_and_cols = rows.size() * cols.size();
    
    // Squares occupied by both rows and diagonals1 (overcounted)
    long long occupied_by_rows_and_diags1 = rows.size() * diags1.size();
    
    // Squares occupied by both rows and diagonals2 (overcounted)
    long long occupied_by_rows_and_diags2 = rows.size() * diags2.size();
    
    // Squares occupied by both cols and diagonals1 (overcounted)
    long long occupied_by_cols_and_diags1 = cols.size() * diags1.size();
    
    // Squares occupied by both cols and diagonals2 (overcounted)
    long long occupied_by_cols_and_diags2 = cols.size() * diags2.size();
    
    // Squares occupied by diagonals1 and diagonals2 (overcounted)
    long long occupied_by_diags1_and_diags2 = diags1.size() * diags2.size();
    
    // Squares occupied by rows, cols, and diagonals1 (overcounted)
    long long occupied_by_rows_cols_and_diags1 = rows.size() * cols.size() * diags1.size();
    
    // Squares occupied by rows, cols, and diagonals2 (overcounted)
    long long occupied_by_rows_cols_and_diags2 = rows.size() * cols.size() * diags2.size();
    
    // Squares occupied by rows, diagonals1, and diagonals2 (overcounted)
    long long occupied_by_rows_diags1_and_diags2 = rows.size() * diags1.size() * diags2.size();
    
    // Squares occupied by cols, diagonals1, and diagonals2 (overcounted)
    long long occupied_by_cols_diags1_and_diags2 = cols.size() * diags1.size() * diags2.size();
    
    // Squares occupied by rows, cols, diagonals1, and diagonals2 (overcounted)
    long long occupied_by_rows_cols_diags1_and_diags2 = rows.size() * cols.size() * diags1.size() * diags2.size();
    
    // Applying inclusion-exclusion principle
    long long occupied_total = occupied_by_rows + occupied_by_cols + occupied_by_diags1 + occupied_by_diags2
                               - occupied_by_rows_and_cols - occupied_by_rows_and_diags1 - occupied_by_rows_and_diags2
                               - occupied_by_cols_and_diags1 - occupied_by_cols_and_diags2
                               + occupied_by_diags1_and_diags2
                               - occupied_by_rows_cols_and_diags1 - occupied_by_rows_cols_and_diags2
                               - occupied_by_rows_diags1_and_diags2 - occupied_by_cols_diags1_and_diags2
                               + occupied_by_rows_cols_diags1_and_diags2;
    
    long long safe_squares = total_squares - occupied_total;
    
    cout << safe_squares << endl;
    
    return 0;
}