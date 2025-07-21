#include <bits/stdc++.h>
using namespace std;

// Custom hash for pair<int, int>
struct PairHash {
    size_t operator()(const pair<int, int>& p) const {
        return hash<long long>()(static_cast<long long>(p.first) * 1000000000 + p.second);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    int M;
    cin >> N >> M;

    unordered_set<pair<int, int>, PairHash> threatened;

    vector<pair<int, int>> knight_moves = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        threatened.insert({a, b});
        for (auto [dx, dy] : knight_moves) {
            int x = a + dx;
            int y = b + dy;
            if (1 <= x && x <= N && 1 <= y && y <= N) {
                threatened.insert({x, y});
            }
        }
    }

    // Total cells: N * N
    cout << (N * N - threatened.size()) << '\n';

    return 0;
}