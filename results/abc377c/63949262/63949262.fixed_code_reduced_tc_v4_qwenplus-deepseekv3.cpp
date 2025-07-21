#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M;
    cin >> N >> M;

    set<pair<long long, long long>> dangerous;
    set<pair<long long, long long>> occupied;

    for (long long i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        occupied.insert({a, b});

        // Calculate all 8 possible attack positions
        vector<pair<long long, long long>> moves = {
            {a + 2, b + 1}, {a + 1, b + 2},
            {a - 1, b + 2}, {a - 2, b + 1},
            {a - 2, b - 1}, {a - 1, b - 2},
            {a + 1, b - 2}, {a + 2, b - 1}
        };

        for (const auto &move : moves) {
            long long x = move.first;
            long long y = move.second;
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                dangerous.insert({x, y});
            }
        }
    }

    // The total safe squares are N^2 minus dangerous squares and occupied squares
    // But occupied squares are already part of dangerous squares, so they are not counted twice
    long long total_squares = N * N;
    long long dangerous_count = dangerous.size() + occupied.size();

    // However, occupied squares that are also dangerous should not be double-counted
    // So we need to subtract the intersection of dangerous and occupied
    // But since occupied squares are not in dangerous unless they are under attack by another knight,
    // which is not the case here (each knight's own position is not in its attack squares)
    // So the total dangerous squares are the union of dangerous and occupied
    // Hence, dangerous_count = dangerous.size() + occupied.size() - intersection.size()
    // But intersection is zero because a knight's own position is not in its attack squares

    // So total safe squares = total_squares - (dangerous.size() + occupied.size())
    // But to avoid double-counting, we need to ensure that occupied squares are not in dangerous
    // So, total safe squares = total_squares - (dangerous.size() + occupied.size() - intersection)
    // But intersection is zero, so:
    long long safe_squares = total_squares - (dangerous.size() + occupied.size());

    cout << safe_squares << endl;

    return 0;
}