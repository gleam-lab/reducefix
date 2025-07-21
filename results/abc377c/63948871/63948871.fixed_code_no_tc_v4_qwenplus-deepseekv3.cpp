#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <tuple>

using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 N, M;
    cin >> N >> M;

    set<pair<i64, i64>> pieces;
    unordered_set<i64> attacked;

    // Helper function to mark attacked squares
    auto mark_attacked = [&](i64 i, i64 j) {
        vector<pair<i64, i64>> moves = {
            {i+2, j+1}, {i+1, j+2}, {i-1, j+2}, {i-2, j+1},
            {i-2, j-1}, {i-1, j-2}, {i+1, j-2}, {i+2, j-1}
        };

        for (auto [x, y] : moves) {
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                attacked.insert(x * N + y);
            }
        }
    };

    for (i64 k = 0; k < M; ++k) {
        i64 a, b;
        cin >> a >> b;
        pieces.insert({a, b});
        mark_attacked(a, b);
    }

    // Total squares = N*N
    // Safe squares = Total - occupied - attacked + (occupied AND attacked)
    // But we can't directly compute this because N is too large
    
    // Instead, we'll count:
    // safe_squares = N*N - M - (attacked.size() - intersection_size)
    // Where intersection_size is number of pieces that are in attacked positions
    
    i64 intersection_size = 0;
    for (auto [a, b] : pieces) {
        if (attacked.count(a * N + b)) {
            intersection_size++;
        }
    }

    i64 safe_squares = N * N - M - (attacked.size() - intersection_size);
    cout << safe_squares << '\n';

    return 0;
}