#include <iostream>
#include <vector>
#include <set>

using namespace std;

#define v(type) vector<type>
#define p(ate, bte) pair<ate, bte>

int main() {
    long long N, M;
    cin >> N >> M;

    set<p(long long, long long>> occupied;
    long long totalSquares = N * N;
    long long validSquares = totalSquares;

    for (long long i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        occupied.insert({a, b});

        // Check squares that can be captured
        // All movements are relative to the piece's position
        vector<pair<long long, long long>> moves = {
            {2, 1}, {1, 2}, {1, -2}, {2, -1},
            {-2, 1}, {-1, 2}, {-1, -2}, {-2, -1}
        };

        for (const auto& move : moves) {
            long long nx = a + move.first;
            long long ny = b + move.second;
            if (1 <= nx && nx <= N && 1 <= ny && ny <= N) {
                occupied.insert({nx, ny});
            }
        }
    }

    // Calculate the number of valid squares
    for (const auto& pos : occupied) {
        long long a = pos.first;
        long long b = pos.second;
        validSquares -= 8; // Each occupied piece blocks 8 squares from being placed
    }

    cout << validSquares << endl;

    return 0;
}