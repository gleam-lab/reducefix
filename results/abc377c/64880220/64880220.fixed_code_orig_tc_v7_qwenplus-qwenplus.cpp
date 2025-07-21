#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    int M;
    cin >> N >> M;

    unordered_set<long long> blocked;
    // 8 directions a piece can attack (knight-style moves)
    vector<pair<int, int>> dirs = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (int i = 0; i < M; ++i) {
        int x, y;
        cin >> x >> y;

        // Block current position
        blocked.insert((long long)x * N + y);

        // Block all threatened positions
        for (auto [dx, dy] : dirs) {
            int nx = x + dx;
            int ny = y + dy;
            if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
                blocked.insert((long long)nx * N + ny);
            }
        }
    }

    cout << N * N - (long long)blocked.size() << '\n';
}