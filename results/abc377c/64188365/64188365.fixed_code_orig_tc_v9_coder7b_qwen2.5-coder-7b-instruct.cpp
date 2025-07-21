#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

long long power(long long x, long long y) {
    long long res = 1;
    while (y > 0) {
        if (y & 1)
            res = (res * x) % MOD;
        y >>= 1;
        x = (x * x) % MOD;
    }
    return res;
}

int main() {
    long long n, m;
    cin >> n >> m;
    
    set<pair<long long, long long>> s;
    vector<vector<int>> board(n, vector<int>(n, 0));
    
    for (int i = 0; i < m; ++i) {
        long long a, b;
        cin >> a >> b;
        --a, --b;
        s.insert({a, b});
        board[a][b] = 1;
        
        for (int dx = -2; dx <= 2; ++dx) {
            for (int dy = -2; dy <= 2; ++dy) {
                if (abs(dx) + abs(dy) == 3 && a + dx >= 0 && a + dx < n && b + dy >= 0 && b + dy < n) {
                    s.insert({a + dx, b + dy});
                    board[a + dx][b + dy] = 1;
                }
            }
        }
    }
    
    long long total_squares = n * n;
    long long empty_squares = total_squares - s.size();
    
    cout << empty_squares << endl;
    
    return 0;
}