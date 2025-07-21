#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;

    // Set to store all positions that are either occupied or threatened
    unordered_set<string> blocked;

    // Directions where a piece can attack
    vector<pair<long long, long long>> directions = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (long long i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;

        // Mark current position as occupied
        string pos_key = to_string(a) + "," + to_string(b);
        blocked.insert(pos_key);

        // Mark all threatened positions by this piece
        for (auto [dx, dy] : directions) {
            long long x = a + dx;
            long long y = b + dy;
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                string key = to_string(x) + "," + to_string(y);
                blocked.insert(key);
            }
        }
    }

    // Total number of cells is N*N
    // Subtract the number of blocked (occupied or threatened) cells
    cout << N * N - (long long)blocked.size() << endl;

    return 0;
}