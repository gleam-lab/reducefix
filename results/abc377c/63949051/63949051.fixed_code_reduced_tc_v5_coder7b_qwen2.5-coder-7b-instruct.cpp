#include <iostream>
#include <vector>
#include <set>
#include <utility>

using namespace std;

const vector<pair<int, int>> knight_moves = {
    {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
    {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    cin >> N;

    long long M;
    cin >> M;

    set<pair<long long, long long>> pieces;
    for (long long i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        pieces.insert({a, b});
    }

    long long total_empty_squares = N * N;
    long long occupied_squares = 0;

    for (const auto& piece : pieces) {
        for (const auto& move : knight_moves) {
            long long new_x = piece.first + move.first;
            long long new_y = piece.second + move.second;
            if (new_x >= 1 && new_x <= N && new_y >= 1 && new_y <= N) {
                occupied_squares++;
            }
        }
    }

    // Subtract each piece itself as it is also counted in the moves
    occupied_squares -= M;

    out(total_empty_squares - occupied_squares);

    return 0;
}