#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    
    vector<pair<long long, long long>> pieces;
    for (long long i = 0; i < m; ++i) {
        long long a, b;
        cin >> a >> b;
        pieces.push_back({a, b});
    }
    
    bool row[1000000001] = {};
    bool col[1000000001] = {};
    bool diag1[2000000002] = {};  // a + b
    bool diag2[2000000002] = {};  // a - b
    
    for (auto& p : pieces) {
        row[p.first] = col[p.second] = true;
        diag1[p.first + p.second] = true;
        diag2[p.first - p.second] = true;
    }
    
    long long totalEmpty = n * n;
    
    // Count the number of rows, columns, and diagonals that are filled
    long long filledRows = 0, filledCols = 0, filledDiag1 = 0, filledDiag2 = 0;
    for (long long i = 1; i <= n; ++i) {
        filledRows += row[i];
        filledCols += col[i];
    }
    
    for (long long i = 1; i <= 2 * n; ++i) {
        filledDiag1 += diag1[i];
        filledDiag2 += diag2[i];
    }
    
    // Subtract filled rows, columns, and diagonals from total empties
    totalEmpty -= filledRows * n - filledCols * n;
    
    // Add back the intersections of filled rows and columns
    totalEmpty += filledRows * filledCols - filledDiag1;
    
    // Subtract the intersections of filled diagonals
    totalEmpty -= filledDiag1 + filledDiag2 - 2 * filledDiag1;
    
    cout << totalEmpty;
    return 0;
}