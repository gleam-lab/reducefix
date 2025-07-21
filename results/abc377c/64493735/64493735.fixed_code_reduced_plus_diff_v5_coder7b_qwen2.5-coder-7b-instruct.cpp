#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M;
    cin >> N >> M;

    // Define the directions a piece can capture another piece
    vector<pair<int, int>> directions = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    unordered_set<long long> captured;

    for (long long i = 0; i < M; ++i) {
        long long x, y;
        cin >> x >> y;
        
        // Mark all cells that can be captured from (x, y)
        for (const auto& dir : directions) {
            long long nx = x + dir.first;
            long long ny = y + dir.second;
            if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
                captured.insert(nx * N + ny);
            }
        }
    }

    // Total number of cells minus the number of captured cells
    cout << N * N - captured.size() << endl;

    return 0;
}