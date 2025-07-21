#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

long long solve(int n, int m, vector<pair<int, int>>& pieces) {
    unordered_set<int> rows, cols, diags1, diags2;
    
    for (auto& p : pieces) {
        int a = p.first, b = p.second;
        rows.insert(a);
        cols.insert(b);
        
        // Diagonal a+b
        diags1.insert(a + b);
        // Diagonal a-b
        diags2.insert(a - b);
    }
    
    // Calculate the number of squares not in any of the affected rows, columns, or diagonals
    long long total = 0;
    total += n * n; // All squares
    
    // Subtract the squares in affected rows and columns
    total -= rows.size() * n; // Affected by rows
    total -= cols.size() * n; // Affected by columns
    
    // Subtract the squares in affected diagonals
    total -= diags1.size() * n; // Affected by diagonal a+b
    total -= diags2.size() * n; // Affected by diagonal a-b
    
    // Add back the intersections (over-counted squares)
    // Intersections in rows and columns
    total += rows.size() * cols.size();
    // Intersections between rows and diagonals
    for (int r : rows) {
        total -= diags1.count(r) + diags2.count(r);
    }
    // Intersections between columns and diagonals
    for (int c : cols) {
        total -= diags1.count(c) + diags2.count(c);
    }
    
    return total;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> pieces(m);
    for (int i = 0; i < m; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
    }
    
    cout << solve(n, m, pieces) << endl;
    return 0;
}