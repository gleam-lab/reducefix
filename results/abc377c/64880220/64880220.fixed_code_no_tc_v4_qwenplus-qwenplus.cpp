#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;

    // Set to store all positions that are either occupied by a piece or can be attacked
    unordered_set<string> blocked;

    // Lambda to convert (x, y) to a unique string key for the set
    auto to_key = [](long long x, long long y) {
        return to_string(x) + "," + to_string(y);
    };

    vector<pair<long long, long long>> attack_offsets = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (long long i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;

        // Block the position with the piece itself
        blocked.insert(to_key(a, b));

        // Block all positions that this piece can attack
        for (auto [dx, dy] : attack_offsets) {
            long long x = a + dx;
            long long y = b + dy;
            if (1 <= x && x <= N && 1 <= y && y <= N) {
                blocked.insert(to_key(x, y));
            }
        }
    }

    // Total number of squares is N*N
    // Subtract the number of blocked squares to get the answer
    cout << (N * N - (long long)blocked.size()) << endl;

    return 0;
}