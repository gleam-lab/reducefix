#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M;
    cin >> N >> M;

    unordered_set<long long> attacked;
    unordered_set<long long> pieces;

    for (long long i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        pieces.insert((a - 1) * N + b - 1);

        // Generate all 8 possible attack positions
        vector<pair<long long, long long>> moves = {
            {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
            {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
        };

        for (auto [dx, dy] : moves) {
            long long x = a + dx;
            long long y = b + dy;
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                attacked.insert((x - 1) * N + y - 1);
            }
        }
    }

    // Total squares minus:
    // 1. Squares already occupied by pieces
    // 2. Squares under attack (but not already occupied)
    long long total = N * N - pieces.size();
    long long unsafe = 0;

    for (auto pos : attacked) {
        if (pieces.find(pos) == pieces.end()) {
            unsafe++;
        }
    }

    cout << total - unsafe << endl;

    return 0;
}