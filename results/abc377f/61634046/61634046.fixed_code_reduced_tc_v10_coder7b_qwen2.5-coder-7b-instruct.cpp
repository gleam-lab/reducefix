#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 1e9 + 10;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> row(n + 1), col(n + 1);
    vector<vector<int>> up(2, vector<int>(n + 1)), down(2, vector<int>(n + 1));
    
    set<pair<int, int>> rows, cols, ups, downs;
    
    for(int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        row[y] = x;
        col[x] = y;
        
        int d = (x + y) & 1;
        up[d][y - x] = 1;
        down[d][x + y] = 1;
        
        rows.insert({x, y});
        cols.insert({y, x});
        ups.insert({y - x, x});
        downs.insert({x + y, x});
    }
    
    sort(row.begin() + 1, row.end());
    sort(col.begin() + 1, col.end());
    sort(up[0].begin(), up[0].end());
    sort(up[1].begin(), up[1].end());
    sort(down[0].begin(), down[0].end());
    sort(down[1].begin(), down[1].end());
    
    int unique_rows = unique(row.begin() + 1, row.end()) - row.begin();
    int unique_cols = unique(col.begin() + 1, col.end()) - col.begin();
    int unique_ups = unique(up[0].begin(), up[0].end()) - up[0].begin();
    int unique_downs = unique(down[0].begin(), down[0].end()) - down[0].begin();
    
    long long total_empty_squares = n * n;
    
    for(int i = 1; i <= unique_rows; ++i) {
        for(int j = 1; j <= unique_cols; ++j) {
            if(rows.count({row[i], j}) == 0 && cols.count({j, col[j]}) == 0) {
                int d = (row[i] + j) & 1;
                if(ups.count({row[i] - j, row[i]}) == 0 && downs.count({row[i] + j, row[i]}) == 0) {
                    total_empty_squares--;
                }
            }
        }
    }
    
    cout << total_empty_squares << endl;
    return 0;
}