#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;

    set<pair<int, int>> pieces;
    set<pair<int, int>> invalid_positions;

    for (long long i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        pieces.emplace(a, b);

        // Check all possible capture positions
        vector<pair<int, int>> capture_positions = {
            {a + 2, b + 1}, {a + 1, b + 2}, {a - 1, b + 2},
            {a - 2, b + 1}, {a - 2, b - 1}, {a - 1, b - 2},
            {a + 1, b - 2}, {a + 2, b - 1}
        };

        for (const auto& pos : capture_positions) {
            int x = pos.first, y = pos.second;
            if (x > 0 && x <= N && y > 0 && y <= N) {
                invalid_positions.emplace(x, y);
            }
        }
    }

    // Calculate the number of valid positions
    long long valid_positions = N * N;
    for (const auto& pos : invalid_positions) {
        valid_positions--;
    }

    cout << valid_positions << endl;

    return 0;
}