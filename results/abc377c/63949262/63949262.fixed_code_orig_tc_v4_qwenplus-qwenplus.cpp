// C - Avoid Knight Attack

#include <iostream>
#include <vector>
#include <set>
#include <tuple>
#include <unordered_set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    int M;
    cin >> N >> M;

    set<pair<long long, long long>> attacked_positions;
    set<pair<long long, long long>> existing_pieces;

    // Directions representing the 8 possible knight moves with (dx, dy)
    vector<pair<long long, long long>> directions = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        existing_pieces.insert({a, b});

        // Check all 8 positions that this piece can attack
        for (const auto& [dx, dy] : directions) {
            long long na = a + dx;
            long long nb = b + dy;
            if (1 <= na && na <= N && 1 <= nb && nb <= N) {
                attacked_positions.insert({na, nb});
            }
        }
    }

    // Remove positions already occupied by existing pieces from attacked positions
    for (const auto& pos : existing_pieces) {
        attacked_positions.erase(pos);
    }

    // Total safe positions = total grid size - existing pieces - attacked positions
    long long total_cells = N * (long long)N;
    long long used_positions = existing_pieces.size();
    long long threatened_positions = attacked_positions.size();

    cout << (total_cells - used_positions - threatened_positions) << endl;

    return 0;
}