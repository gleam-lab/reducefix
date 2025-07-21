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

    set<pair<i64, i64>> attacked;
    set<pair<i64, i64>> pieces;

    for (i64 i = 0; i < M; ++i) {
        i64 a, b;
        cin >> a >> b;
        pieces.insert({a, b});
        
        // All 8 possible attack positions
        vector<pair<i64, i64>> moves = {
            {a + 2, b + 1},
            {a + 1, b + 2},
            {a - 1, b + 2},
            {a - 2, b + 1},
            {a - 2, b - 1},
            {a - 1, b - 2},
            {a + 1, b - 2},
            {a + 2, b - 1}
        };

        for (const auto& move : moves) {
            i64 x = move.first;
            i64 y = move.second;
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                attacked.insert({x, y});
            }
        }
    }

    // The total safe squares are N*N minus the squares under attack and the original pieces
    i64 total_safe = N * N - attacked.size() - pieces.size();
    
    // But we need to ensure that none of the original pieces are in the attacked set
    // So, subtract the pieces that are also in attacked
    for (const auto& piece : pieces) {
        if (attacked.count(piece)) {
            total_safe += 1; // Because it was subtracted twice (once in attacked.size() and once in pieces.size())
        }
    }

    cout << total_safe << endl;

    return 0;
}