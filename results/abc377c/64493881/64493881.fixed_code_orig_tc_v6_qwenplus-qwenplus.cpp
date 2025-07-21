#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int64_t N;
    int M;
    cin >> N >> M;

    // Define a hash function for pairs
    struct pair_hash {
        template <class T1, class T2>
        size_t operator()(const pair<T1, T2>& p) const {
            return hash<T1>()(p.first) ^ (hash<T2>()(p.second) << 16);
        }
    };

    unordered_set<pair<int64_t, int64_t>, pair_hash> attacked;

    for (int i = 0; i < M; ++i) {
        int64_t a, b;
        cin >> a >> b;

        // Add current piece position
        attacked.insert({a, b});

        // All 8 knight-style move directions
        vector<pair<int64_t, int64_t>> moves = {
            {a + 2, b + 1}, {a + 1, b + 2},
            {a - 1, b + 2}, {a - 2, b + 1},
            {a - 2, b - 1}, {a - 1, b - 2},
            {a + 1, b - 2}, {a + 2, b - 1}
        };

        for (auto& [x, y] : moves) {
            if (1 <= x && x <= N && 1 <= y && y <= N) {
                attacked.insert({x, y});
            }
        }
    }

    // The result is total cells minus attacked/occupied ones
    cout << (N * N - static_cast<int64_t>(attacked.size())) << endl;

    return 0;
}