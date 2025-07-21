#include <iostream>
#include <vector>
using namespace std;

long long countCapture(int n, int m, vector<pair<int, int>>& pieces) {
    vector<int> rows(n + 1, 0), cols(n + 1, 0), diag1(2 * n + 1, 0), diag2(2 * n + 1, 0);
    
    for (auto& p : pieces) {
        rows[p.first]++;
        cols[p.second]++;
        diag1[p.first + p.second]++;
        diag2[p.first - p.second]++;
    }
    
    // Total number of squares minus captured squares
    long long total = n * n;
    
    // Subtract squares captured by full rows and columns
    for (int i = 1; i <= n; ++i) {
        total -= rows[i];
        total -= cols[i];
        total -= diag1[i];
        total -= diag2[i];
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
    
    cout << countCapture(n, m, pieces) << endl;
    return 0;
}