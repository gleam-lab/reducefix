#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;

    // Set to store positions with pieces or threatened positions
    unordered_set<string> occupied_or_threatened;

    // Function to hash a position (i,j) into a string for the set
    auto pos_key = [](long long i, long long j) {
        return to_string(i) + "," + to_string(j);
    };

    vector<pair<long long, long long>> directions = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (long long i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;

        // Mark the piece's position
        occupied_or_threatened.insert(pos_key(a, b));

        // Mark all threatened positions by this piece
        for (auto [dx, dy] : directions) {
            long long x = a + dx;
            long long y = b + dy;
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                occupied_or_threatened.insert(pos_key(x, y));
            }
        }
    }

    // Total number of squares: N*N
    // Subtract the number of occupied or threatened squares
    long long total_squares = N * N;
    long long blocked = occupied_or_threatened.size();

    cout << total_squares - blocked << endl;

    return 0;
}