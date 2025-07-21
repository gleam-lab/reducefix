#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    set<pair<long long, long long>> ex;
    vector<vector<bool>> grid(n + 1, vector<bool>(n + 1, false));
    
    for (long long i = 0; i < m; ++i) {
        long long a, b;
        cin >> a >> b;
        ex.insert({a, b});
        grid[a][b] = true;
    }

    long long count = 0;
    vector<pair<int, int>> directions = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};

    for (long long i = 1; i <= n; ++i) {
        for (long long j = 1; j <= n; ++j) {
            if (!grid[i][j]) {
                bool valid = true;
                for (auto& dir : directions) {
                    long long x = i + dir.first;
                    long long y = j + dir.second;
                    if (x >= 1 && x <= n && y >= 1 && y <= n && ex.find({x, y}) != ex.end()) {
                        valid = false;
                        break;
                    }
                }
                if (valid) {
                    count++;
                }
            }
        }
    }

    cout << n * n - count << endl;
    return 0;
}