#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct PairHash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &pair) const {
        auto hash1 = std::hash<T1>{}(pair.first);
        auto hash2 = std::hash<T2>{}(pair.second);
        return hash1 ^ hash2;
    }
};

int main() {
    long long n, m;
    cin >> n >> m;
    vector<vector<bool>> grid(n + 1, vector<bool>(n + 1, false));
    vector<pair<long long, long long>> pieces;
    pieces.reserve(m);
    queue<pair<long long, long long>> q;

    for (long long i = 0; i < m; ++i) {
        long long a, b;
        cin >> a >> b;
        grid[a][b] = true;
        pieces.emplace_back(a, b);
    }

    for (const auto& p : pieces) {
        q.push(p);
        grid[p.first][p.second] = true;
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (int i = 0; i < 8; ++i) {
                long long nx = x + 2 * ((i % 4) - (i / 2));
                long long ny = y + 2 * ((i / 2) - (i % 4));
                if (nx >= 1 && nx <= n && ny >= 1 && ny <= n && !grid[nx][ny]) {
                    grid[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }

    long long ans = 0;
    for (long long i = 1; i <= n; ++i) {
        for (long long j = 1; j <= n; ++j) {
            if (!grid[i][j]) {
                ans++;
            }
        }
    }

    cout << ans << endl;
    return 0;
}