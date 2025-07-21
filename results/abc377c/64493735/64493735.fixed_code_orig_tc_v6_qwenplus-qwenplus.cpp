#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int64_t N;
    int M;
    cin >> N >> M;

    unordered_set<int64_t> attacked;
    unordered_set<int64_t> occupied;

    auto add_attack = [&](int64_t x, int64_t y) {
        if (x >= 1 && x <= N && y >= 1 && y <= N) {
            attacked.insert((x - 1) * N + (y - 1));
        }
    };

    auto is_valid = [&](int64_t x, int64_t y) {
        return x >= 1 && x <= N && y >= 1 && y <= N;
    };

    vector<pair<int64_t, int64_t>> moves = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (int i = 0; i < M; ++i) {
        int64_t a, b;
        cin >> a >> b;
        occupied.insert((a - 1) * N + (b - 1));

        for (const auto& [dx, dy] : moves) {
            int64_t na = a + dx;
            int64_t nb = b + dy;
            if (is_valid(na, nb)) {
                add_attack(na, nb);
            }
        }
    }

    // Remove positions that are occupied by original pieces from attacked set
    for (const auto& pos : occupied) {
        if (attacked.count(pos)) {
            attacked.erase(pos);
        }
    }

    int64_t total = N * N;
    int64_t result = total - occupied.size() - attacked.size();
    cout << result << endl;

    return 0;
}