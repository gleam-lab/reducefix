#include <bits/stdc++.h>
using namespace std;

// Custom hash struct for pair<int, int>
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

    unordered_set<pair<int, int>, PairHash> attacked_or_occupied;

    // Knight-style attack moves
    vector<pair<int, int>> directions{
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        int x = a - 1;  // Convert to 0-based index
        int y = b - 1;

        // Add the occupied square itself
        attacked_or_occupied.emplace(x, y);

        // Mark all 8 possible attack positions if within bounds
        for (const auto& [dx, dy] : directions) {
            int nx = x + dx;
            int ny = y + dy;
            if (0 <= nx && nx < N && 0 <= ny && ny < N) {
                attacked_or_occupied.emplace(nx, ny);
            }
        }
    }

    // Total number of squares on the board is N*N
    // Subtract the count of attacked/occupied cells
    cout << N * N - static_cast<long long>(attacked_or_occupied.size()) << "\n";
}