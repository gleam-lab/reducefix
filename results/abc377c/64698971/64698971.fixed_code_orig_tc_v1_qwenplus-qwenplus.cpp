#include <bits/stdc++.h>
using namespace std;

// Custom hash specialization for pair<int, int>
struct PairHash {
    size_t operator()(const pair<int, int>& p) const {
        return hash<long long>()((static_cast<long long>(p.first) << 32) | p.second);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    int M;
    cin >> N >> M;

    unordered_set<pair<int, int>, PairHash> blocked;

    // All 8 knight-like move directions
    vector<pair<int, int>> moves = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (int i = 0; i < M; ++i) {
        int x, y;
        cin >> x >> y;
        // Convert to 0-based index
        x--; y--;
        blocked.insert({x, y});
        for (auto [dx, dy] : moves) {
            int nx = x + dx;
            int ny = y + dy;
            if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                blocked.insert({nx, ny});
            }
        }
    }

    // Total number of cells: N*N
    // Subtract the number of blocked cells
    cout << (N * NLL - (long long)blocked.size()) << '\n';
}