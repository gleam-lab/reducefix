#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;

    // Set to store positions of existing pieces and attacked squares
    unordered_set<string> occupied;  // For fast lookup of (a,b) pairs

    // Helper lambda to generate a unique key for a position
    auto getKey = [](long long x, long long y) {
        return to_string(x) + "," + to_string(y);
    };

    // Vectors for knight-like moves
    vector<pair<long long, long long>> directions = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        string key = getKey(a, b);

        // Add this piece to occupied set if not already there
        if (occupied.find(key) == occupied.end()) {
            occupied.insert(key);
        }

        // Check all 8 directions from this piece
        for (auto [dx, dy] : directions) {
            long long nx = a + dx;
            long long ny = b + dy;

            // If the target square is within bounds, mark it as attacked
            if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
                string attackKey = getKey(nx, ny);
                if (occupied.find(attackKey) == occupied.end()) {
                    occupied.insert(attackKey);
                }
            }
        }
    }

    // Total number of squares is N*N
    // Subtract the number of occupied or attacked squares
    cout << N * N - (long long)occupied.size() << endl;

    return 0;
}