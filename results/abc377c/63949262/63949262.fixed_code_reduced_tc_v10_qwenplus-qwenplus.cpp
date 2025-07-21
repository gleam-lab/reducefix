#include <iostream>
#include <vector>
#include <set>
#include <tuple>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int64_t N;
    int M;
    cin >> N >> M;

    set<pair<int64_t, int64_t>> attacked_or_occupied;

    // The 8 possible attack positions relative to a piece
    vector<pair<int64_t, int64_t>> attack_offsets = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (int i = 0; i < M; ++i) {
        int64_t a, b;
        cin >> a >> b;

        // Add the current piece's position
        attacked_or_occupied.emplace(a, b);

        // Add all valid attack positions from this piece
        for (const auto& [dx, dy] : attack_offsets) {
            int64_t nx = a + dx;
            int64_t ny = b + dy;
            if (1 <= nx && nx <= N && 1 <= ny && ny <= N) {
                attacked_or_occupied.emplace(nx, ny);
            }
        }
    }

    // Total squares - attacked/occupied squares
    cout << (N * N - static_cast<int64_t>(attacked_or_occupied.size())) << endl;

    return 0;
}