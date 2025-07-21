#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int64_t N;
    int M;
    cin >> N >> M;

    unordered_set<int64_t> attacked;
    auto hash = [&](int64_t x, int64_t y) {
        return x * 1000000007 + y;
    };

    vector<pair<int64_t, int64_t>> knights;
    for (int i = 0; i < M; ++i) {
        int64_t a, b;
        cin >> a >> b;
        knights.emplace_back(a, b);
    }

    // The 8 possible knight moves
    const array<array<int64_t, 2>, 8> moves = {{
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    }};

    // First add all knight positions and attacked squares to the set
    for (auto [a, b] : knights) {
        attacked.insert(hash(a, b));
        for (const auto& [dx, dy] : moves) {
            int64_t x = a + dx;
            int64_t y = b + dy;
            if (1 <= x && x <= N && 1 <= y && y <= N) {
                attacked.insert(hash(x, y));
            }
        }
    }

    // Subtract number of attacked squares from total squares
    cout << (N * N - static_cast<int64_t>(attacked.size())) << endl;

    return 0;
}