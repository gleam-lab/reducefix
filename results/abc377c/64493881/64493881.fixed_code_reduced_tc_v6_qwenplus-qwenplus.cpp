#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int64_t N;
    int M;
    cin >> N >> M;

    unordered_set<int64_t> attacked;
    auto pack = [&](int x, int y) {
        return (int64_t)x * 1000000000 + y;
    };

    vector<pair<int, int>> knights;
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        knights.emplace_back(a, b);
    }

    // First mark all attacked squares
    for (const auto& [a, b] : knights) {
        static const array<array<int, 2>, 8> moves = {{
            {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
            {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
        }};
        
        for (const auto& [dx, dy] : moves) {
            int x = a + dx;
            int y = b + dy;
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                attacked.insert(pack(x, y));
            }
        }
    }

    // Then subtract all squares under attack and the knight positions themselves
    for (const auto& [a, b] : knights) {
        attacked.insert(pack(a, b));
    }

    cout << (N * N - static_cast<int64_t>(attacked.size())) << endl;
    return 0;
}