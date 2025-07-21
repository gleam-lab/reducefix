#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e9;

int main() {
    long long n, m;
    cin >> n >> m;
    
    vector<int> row(n + 1), col(n + 1);
    unordered_map<long long, int> up, down;
    
    for(int i = 1; i <= m; ++i) {
        long long x, y; 
        cin >> x >> y;
        
        row[x]++;
        col[y]++;
        
        long long diag1 = x - y;
        long long diag2 = x + y;
        
        up[diag1]++;
        down[diag2]++;
    }
    
    long long total_empty_squares = n * n;
    long long occupied_by_row = accumulate(row.begin(), row.end(), 0LL);
    long long occupied_by_col = accumulate(col.begin(), col.end(), 0LL);
    long long occupied_by_diag1 = accumulate(up.begin(), up.end(), 0LL, [](int sum, const auto& p){ return sum + p.second; });
    long long occupied_by_diag2 = accumulate(down.begin(), down.end(), 0LL, [](int sum, const auto& p){ return sum + p.second; });

    long long counted_twice = 0;
    for(auto [_, count] : up) {
        counted_twice += count * (count - 1) / 2;
    }

    for(auto [_, count] : down) {
        counted_twice += count * (count - 1) / 2;
    }

    total_empty_squares -= occupied_by_row + occupied_by_col + occupied_by_diag1 + occupied_by_diag2 - counted_twice;

    cout << total_empty_squares << endl;
    return 0;
}