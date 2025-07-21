#include <iostream>
#include <unordered_set>
#include <vector>
#include <utility>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int64_t N;
    int M;
    cin >> N >> M;

    // Directions that a piece can attack (8 directions)
    const vector<pair<int64_t, int64_t>> directions = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    unordered_set<int64_t> attacked_positions;
    vector<pair<int64_t, int64_t>> pieces(M);

    for (int i = 0; i < M; ++i) {
        int64_t a, b;
        cin >> a >> b;
        pieces[i] = {a, b};

        // Mark all positions this piece can attack
        for (const auto& [dx, dy] : directions) {
            int64_t x = a + dx;
            int64_t y = b + dy;
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                attacked_positions.insert(x * (N + 1) + y); // unique key for (x,y)
            }
        }

        // Also include the piece's own position as occupied (to avoid duplicates)
        attacked_positions.insert(a * (N + 1) + b);
    }

    // Total number of squares not under attack or already occupied by other pieces
    int64_t total_squares = N * N;
    int64_t forbidden = attacked_positions.size();
    
    cout << (total_squares - forbidden) << '\n';

    return 0;
}