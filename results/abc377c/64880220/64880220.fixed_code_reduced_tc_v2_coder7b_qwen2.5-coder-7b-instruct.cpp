#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, m;
    cin >> n >> m;
    set<pair<long long, long long>> ex;

    for (long long i = 0; i < m; ++i) {
        long long a, b;
        cin >> a >> b;
        ex.insert({a, b});
    }

    long long ans = n * n - m;
    vector<vector<bool>> visited(n + 1, vector<bool>(n + 1, false));
    vector<pair<long long, long long>> directions = {{1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}};

    auto isValid = [&](long long x, long long y) {
        return x >= 1 && x <= n && y >= 1 && y <= n && !visited[x][y] && !ex.count({x, y});
    };

    for (const auto& [a, b] : ex) {
        visited[a][b] = true;
        for (const auto& [dx, dy] : directions) {
            long long x = a + dx, y = b + dy;
            if (isValid(x, y)) {
                --ans;
                visited[x][y] = true;
            }
        }
    }

    cout << ans << endl;
    return 0;
}