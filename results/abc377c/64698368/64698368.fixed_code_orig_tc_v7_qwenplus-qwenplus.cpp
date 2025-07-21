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
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    int M;
    cin >> N >> M;

    unordered_set<pair<int, int>, pair_hash> forbidden;

    // These are all the relative positions a knight-like move can attack
    vector<pair<int, int>> offsets = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (int i = 0; i < M; ++i) {
        int x, y;
        cin >> x >> y;
        --x; --y; // convert to 0-based index

        // Mark the current piece position as occupied
        forbidden.insert({x, y});

        // Mark all reachable positions from this piece
        for (auto [dx, dy] : offsets) {
            int nx = x + dx;
            int ny = y + dy;
            if (0 <= nx && nx < N && 0 <= ny && ny < N) {
                forbidden.insert({nx, ny});
            }
        }
    }

    // Total number of squares: N*N
    // Subtract the number of forbidden/occupied positions
    cout << (N * 1LL * N) - forbidden.size() << '\n';

    return 0;
}