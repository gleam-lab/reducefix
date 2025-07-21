#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;
    
    unordered_set<long long> rows, cols, diag1, diag2;
    
    for (long long i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }
    
    long long total_empty_cells = N * N;
    long long captured_cells = 0;
    
    // Count captured cells in rows
    for (long long i = 1; i <= N; ++i) {
        captured_cells += rows.count(i);
    }
    
    // Count captured cells in columns
    for (long long j = 1; j <= N; ++j) {
        captured_cells += cols.count(j);
    }
    
    // Count captured cells in diagonals i+j
    for (long long d = 2; d <= 2 * N; ++d) {
        captured_cells += diag1.count(d);
    }
    
    // Count captured cells in diagonals i-j
    for (long long d = -N + 1; d <= N - 1; ++d) {
        captured_cells += diag2.count(d);
    }
    
    // Subtract captured cells from total cells
    long long safe_cells = total_empty_cells - captured_cells;
    
    cout << safe_cells << endl;
    
    return 0;
}