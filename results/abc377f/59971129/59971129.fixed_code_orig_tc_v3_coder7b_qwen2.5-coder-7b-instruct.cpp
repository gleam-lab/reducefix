#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    long long n, m;
    cin >> n >> m;
    
    set<long long> rows, cols, diags, antidiags;
    vector<vector<bool>> grid(n + 1, vector<bool>(n + 1, false));
    
    for (long long k = 1; k <= m; ++k) {
        long long a, b;
        cin >> a >> b;
        
        rows.insert(a);
        cols.insert(b);
        diags.insert(a + b);
        antidiags.insert(a - b);
        
        grid[a][b] = true;
    }
    
    long long ans = 0;
    for (long long i = 1; i <= n; ++i) {
        for (long long j = 1; j <= n; ++j) {
            if (!grid[i][j]) {
                bool can_capture = 
                    rows.find(i) != rows.end() ||
                    cols.find(j) != cols.end() ||
                    diags.find(i + j) != diags.end() ||
                    antidiags.find(i - j) != antidiags.end();
                
                if (!can_capture) {
                    ++ans;
                }
            }
        }
    }
    
    cout << ans << '\n';
    return 0;
}