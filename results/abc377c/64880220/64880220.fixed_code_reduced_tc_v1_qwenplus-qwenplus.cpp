#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M;
    cin >> N >> M;

    // Set to store all positions that are either occupied or threatened
    unordered_set<uint64_t> blocked;

    // Directions for threatened positions
    const array<array<int, 2>, 8> directions = {{
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    }};

    for (long long i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;

        // Block the position itself
        uint64_t pos = (static_cast<uint64_t>(a) << 32) | b;
        blocked.insert(pos);

        // Block all threatened positions around this piece
        for (const auto& dir : directions) {
            long long na = a + dir[0];
            long long nb = b + dir[1];

            if (1 <= na && na <= N && 1 <= nb && nb <= N) {
                uint64_t npos = (static_cast<uint64_t>(na) << 32) | nb;
                blocked.insert(npos);
            }
        }
    }

    // The number of available positions is total squares minus blocked squares
    cout << (uint64_t(N) * uint64_t(N) - blocked.size()) << endl;

    return 0;
}