#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;

    // Set to store positions with pieces
    unordered_set<string> piece_positions;
    // Set to store positions under attack
    unordered_set<string> attacked_positions;

    // Directions a piece can attack
    vector<pair<long long, long long>> directions = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (long long i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        string key = to_string(a) + "," + to_string(b);
        piece_positions.insert(key);

        // For each direction, mark the square that would be attacked
        for (auto [dx, dy] : directions) {
            long long x = a + dx;
            long long y = b + dy;
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                string attacked_key = to_string(x) + "," + to_string(y);
                attacked_positions.insert(attacked_key);
            }
        }
    }

    // Count how many squares are either occupied or under attack
    long long total_unsafe = piece_positions.size() + attacked_positions.size();

    // Total number of safe empty squares
    long long total_squares = N * N;
    long long safe_empty_squares = total_squares - total_unsafe;

    cout << safe_empty_squares << endl;

    return 0;
}