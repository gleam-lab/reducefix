#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    set<pair<long long, long long>> ex;
    for(long long i = 0; i < m; ++i) {
        long long a, b;
        cin >> a >> b;
        ex.insert({a, b});
    }

    vector<vector<bool>> visited(n + 2, vector<bool>(n + 2, false));
    vector<pair<long long, long long>> moves = {{1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}};

    function<void(long long, long long)> dfs = [&](long long x, long long y) {
        if(x < 1 || x > n || y < 1 || y > n || visited[x][y]) return;
        visited[x][y] = true;
        for(auto& [dx, dy] : moves) {
            dfs(x + dx, y + dy);
        }
    };

    for(auto& [x, y] : ex) {
        dfs(x, y);
    }

    long long ans = 0;
    for(long long i = 1; i <= n; ++i) {
        for(long long j = 1; j <= n; ++j) {
            if(!visited[i][j]) ++ans;
        }
    }

    cout << ans << endl;
    return 0;
}