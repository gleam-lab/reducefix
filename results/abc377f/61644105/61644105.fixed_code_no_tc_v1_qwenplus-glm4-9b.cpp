#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

int main() {
    long long n, m;
    std::cin >> n >> m;
    
    std::set<long long> rows, cols, main_diag, anti_diag;
    
    for (long long i = 0; i < m; ++i) {
        long long a, b;
        std::cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        main_diag.insert(a + b);
        anti_diag.insert(a - b);
    }
    
    // Total number of empty cells is n*n
    long long total = n * n;
    
    // Subtract cells in each unique row, column, main diagonal, and anti-diagonal
    total -= rows.size(); // Subtract occupied rows
    total -= cols.size(); // Subtract occupied columns
    total -= main_diag.size(); // Subtract occupied main diagonals
    total -= anti_diag.size(); // Subtract occupied anti-diagonals
    
    // Subtract intersections of occupied rows and columns, main diagonals, and anti-diagonals
    std::set<long long> intersect_rows_cols;
    std::set<long long> intersect_main_diag;
    std::set<long long> intersect_anti_diag;
    
    for (auto& r : rows) {
        for (auto& c : cols) {
            intersect_rows_cols.insert(r + c);
            intersect_main_diag.insert(r - c);
            intersect_anti_diag.insert(r + c);
            intersect_anti_diag.insert(r - c);
        }
    }
    
    total += intersect_rows_cols.size(); // Add back cells that were subtracted twice
    total += intersect_main_diag.size(); // Add back cells that were subtracted twice
    total += intersect_anti_diag.size(); // Add back cells that were subtracted twice
    
    std::cout << total << std::endl;
    
    return 0;
}