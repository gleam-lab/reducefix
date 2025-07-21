#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;

    // Set to store positions with pieces or under attack
    unordered_set<string> attacked_or_occupied;

    // Function to hash (i,j) into a unique string
    auto key = [](long long x, long long y) {
        return to_string(x) + "," + to_string(y);
    };

    vector<pair<long long, long long>> directions = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (long long i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;

        // Add current piece position
        attacked_or_occupied.insert(key(a, b));

        // Add all 8 possible attack positions
        for (auto [dx, dy] : directions) {
            long long x = a + dx;
            long long y = b + dy;
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                attacked_or_occupied.insert(key(x, y));
            }
        }
    }

    // Total number of squares that are either occupied or under attack
    long long total_attacked_or_occupied = attacked_or_occupied.size();

    // Compute the answer
    cout << (N * N - total_attacked_or_occupied) << endl;

    return 0;
}