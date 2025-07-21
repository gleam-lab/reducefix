#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e9;
const int MAX_M = 1e3;

int main() {
    long long n, m;
    cin >> n >> m;
    
    vector<pair<int, int>> pieces(m);
    for(int i = 0; i < m; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
    }
    
    set<int> rows, cols, diagonals1, diagonals2;
    for(auto& p : pieces) {
        rows.insert(p.first);
        cols.insert(p.second);
        diagonals1.insert(p.first - p.second);
        diagonals2.insert(p.first + p.second);
    }
    
    long long total_squares = n * n;
    long long occupied_squares = rows.size() + cols.size() + diagonals1.size() + diagonals2.size();
    long long double_counted_squares = 0;
    
    for(auto& p : pieces) {
        if(rows.count(p.first)) --occupied_squares;
        if(cols.count(p.second)) --occupied_squares;
        if(diagonals1.count(p.first - p.second)) --occupied_squares;
        if(diagonals2.count(p.first + p.second)) --occupied_squares;
        
        double_counted_squares++;
    }
    
    cout << total_squares - occupied_squares + double_counted_squares / 2 << endl;
    return 0;
}