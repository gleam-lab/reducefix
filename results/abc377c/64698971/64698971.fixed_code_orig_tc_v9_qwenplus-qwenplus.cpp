#include <bits/stdc++.h>
using namespace std;

// Custom hash for pair<int, int>
struct pair_hash {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        auto h1 = hash<T1>{}(p.first);
        auto h2 = hash<T2>{}(p.second);
        return h1 ^ (h2 << 1); // Combine hashes
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    int M;
    cin >> N >> M;

    unordered_set<pair<int, int>, pair_hash> attacked;

    // The 8 L-shaped attack moves
    vector<pair<int, int>> directions = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (int i = 0; i < M; ++i) {
        int x, y;
        cin >> x >> y;

        // Check all 8 possible attack moves
        for (auto& dir : directions) {
            int nx = x + dir.first;
            int ny = y + dir.second;

            if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
                attacked.insert({nx, ny});
            }
        }
    }

    // Total squares: N*N
    // Subtract the number of attacked squares and already occupied ones
    cout << (N * N - (long long)attacked.size()) << endl;

    return 0;
}