#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int64_t N, M;
    cin >> N >> M;

    unordered_set<int64_t> attacked_or_occupied;
    // We'll use a hash to uniquely map (a,b) to an integer: (a << 32) | b
    // This is safe for N up to 1e9 since 32 bits are enough for both coordinates

    auto point_hash = [](int64_t x, int64_t y) {
        return (x << 32) | y;
    };

    vector<pair<int64_t, int64_t>> deltas = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (int64_t i = 0; i < M; ++i) {
        int64_t a, b;
        cin >> a >> b;

        // Mark the piece's position as occupied
        attacked_or_occupied.insert(point_hash(a, b));

        // Mark all potentially attacked positions
        for (auto [dx, dy] : deltas) {
            int64_t nx = a + dx;
            int64_t ny = b + dy;
            if (1 <= nx && nx <= N && 1 <= ny && ny <= N) {
                attacked_or_occupied.insert(point_hash(nx, ny));
            }
        }
    }

    // Total number of squares minus the number of attacked or occupied squares
    int64_t total_squares = N * N;
    int64_t forbidden = attacked_or_occupied.size();

    cout << (total_squares - forbidden) << endl;

    return 0;
}