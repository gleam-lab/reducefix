#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M;
    cin >> N >> M;

    unordered_set<long long> attacked;
    auto pack = [&](int x, int y) {
        return (long long)x * (long long)1e9 + y;
    };

    vector<pair<int, int>> knights;
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        knights.emplace_back(a, b);
        attacked.insert(pack(a, b));
    }

    // The 8 possible moves of a knight in chess
    const array<array<int, 2>, 8> knight_moves = {{
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    }};

    for (const auto& [a, b] : knights) {
        for (const auto& [dx, dy] : knight_moves) {
            int x = a + dx;
            int y = b + dy;
            if (1 <= x && x <= N && 1 <= y && y <= N) {
                attacked.insert(pack(x, y));
            }
        }
    }

    cout << (N * N - (long long)attacked.size()) << endl;
    return 0;
}