#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N;
    int M;
    cin >> N >> M;

    unordered_set<long long> attacked;
    // Use a hash function for (a, b) -> single integer to represent coordinates
    // We use 64-bit int: assume that a and b are both <= 1e9 which fits in 32 bits each

    vector<pair<int, int>> directions = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;

        // Insert the position itself as occupied
        long long pos = (a - 1LL) * N + (b - 1LL);
        attacked.insert(pos);

        // Generate all positions that can be attacked from (a,b)
        for (auto [dx, dy] : directions) {
            long long x = a + dx;
            long long y = b + dy;
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                long long attacked_pos = (x - 1LL) * N + (y - 1LL);
                attacked.insert(attacked_pos);
            }
        }
    }

    // Total number of cells is N*N
    // Subtract number of attacked or occupied cells
    cout << N * N - (long long)attacked.size() << endl;

    return 0;
}