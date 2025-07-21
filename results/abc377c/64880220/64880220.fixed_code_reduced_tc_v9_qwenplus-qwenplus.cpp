#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M;
    cin >> N >> M;

    // Set to store all positions that are either occupied by a piece or can be attacked
    unordered_set<string> forbidden;

    // All 8 possible attack positions from a knight in chess
    vector<pair<long long, long long>> directions = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (long long i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;

        // Mark the position itself as occupied
        forbidden.insert(to_string(a) + "," + to_string(b));

        // Mark all attackable positions from this piece
        for (auto [dx, dy] : directions) {
            long long x = a + dx;
            long long y = b + dy;
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                forbidden.insert(to_string(x) + "," + to_string(y));
            }
        }
    }

    // The total number of squares is N*N
    // Subtract the number of forbidden squares to get the answer
    cout << N * N - (long long)forbidden.size() << endl;

    return 0;
}