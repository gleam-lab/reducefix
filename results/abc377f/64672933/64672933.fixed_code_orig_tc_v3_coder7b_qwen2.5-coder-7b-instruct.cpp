#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    i64 N, M;
    cin >> N >> M;
    
    vector<pair<i64, i64>> pieces(M);
    set<i64> rows, cols, diag1, diag2;
    
    for (i64 i = 0; i < M; ++i) {
        i64 a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }
    
    i64 total_empty_squares = N * N;
    
    for (const auto& [a, b] : pieces) {
        total_empty_squares -= (rows.size() - 1); // Remove current row
        total_empty_squares -= (cols.size() - 1); // Remove current column
        total_empty_squares -= (diag1.size() - 1); // Remove current diagonal 1
        total_empty_squares -= (diag2.size() - 1); // Remove current diagonal 2
        
        if (rows.find(a) != rows.end()) rows.erase(a);
        if (cols.find(b) != cols.end()) cols.erase(b);
        if (diag1.find(a + b) != diag1.end()) diag1.erase(a + b);
        if (diag2.find(a - b) != diag2.end()) diag2.erase(a - b);
        
        total_empty_squares++;
    }
    
    cout << total_empty_squares << endl;
    
    return 0;
}