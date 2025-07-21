#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M;
    cin >> N >> M;

    unordered_set<long long> occupied;
    vector<pair<int, int>> directions = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        occupied.insert((a - 1) * N + (b - 1)); // Using a single number to represent the cell (0-based)

        for (const auto& dir : directions) {
            long long x = a + dir.first;
            long long y = b + dir.second;
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                occupied.insert((x - 1) * N + (y - 1));
            }
        }
    }

    cout << N * N - occupied.size() << endl;
    return 0;
}