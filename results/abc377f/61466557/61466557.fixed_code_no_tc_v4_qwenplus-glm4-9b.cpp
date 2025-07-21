#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    
    vector<pair<long long, long long>> pieces(m);
    for (long long i = 0; i < m; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
    }
    
    long long total_empty_squares = n * n;
    
    // Count the number of pieces in each row, column, and diagonal
    vector<long long> rows(n + 1, 0), cols(n + 1, 0), diag1(n * 2 + 1, 0), diag2(n * 2 + 1, 0);
    
    for (auto& p : pieces) {
        rows[p.first]++;
        cols[p.second]++;
        diag1[p.first + p.second]++;
        diag2[p.first - p.second + n]++;
    }
    
    // Calculate the number of squares that are attacked by each row, column, and diagonal
    for (long long i = 1; i <= n; ++i) {
        total_empty_squares -= rows[i];
        total_empty_squares -= cols[i];
        total_empty_squares -= diag1[i];
        total_empty_squares -= diag2[i];
    }
    
    cout << total_empty_squares << endl;
    
    return 0;
}