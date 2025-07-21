#include <iostream>
#include <vector>
#include <set>
#include <utility>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M;
    cin >> N >> M;

    set<pair<long long, long long>> existing_pieces;
    set<pair<long long, long long>> attacked_squares;

    for (long long i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        existing_pieces.insert({a, b});

        // Calculate all 8 possible attack positions
        vector<pair<long long, long long>> moves = {
            {a + 2, b + 1}, {a + 1, b + 2},
            {a - 1, b + 2}, {a - 2, b + 1},
            {a - 2, b - 1}, {a - 1, b - 2},
            {a + 1, b - 2}, {a + 2, b - 1}
        };

        for (const auto& move : moves) {
            long long x = move.first;
            long long y = move.second;
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                attacked_squares.insert({x, y});
            }
        }
    }

    // Total squares is N*N
    // Safe squares are total squares minus squares under attack minus existing pieces
    // But existing pieces are already included in the attacked squares if they are under attack by others
    // So safe squares = N*N - (attacked_squares.size() + existing_pieces.size() - count of existing pieces that are in attacked_squares)
    // Wait, no. The existing pieces are placed squares, and they are not empty. So they cannot be used for placing new pieces.
    // The attacked squares include squares that are empty and can be attacked by existing pieces.
    // So the safe squares are N*N - (number of existing pieces) - (number of attacked squares that are not existing pieces)

    // So:
    long long total_squares = N * N;
    long long existing_count = existing_pieces.size();
    long long attacked_count = 0;

    // To avoid counting existing pieces in attacked_squares, we need to subtract them if they are in attacked_squares
    // So the actual unsafe squares are (attacked_squares.size() + existing_count) minus the intersection.
    // The intersection is the number of existing pieces that are in attacked_squares.

    long long intersection = 0;
    for (const auto& piece : existing_pieces) {
        if (attacked_squares.find(piece) != attacked_squares.end()) {
            intersection++;
        }
    }

    long long unsafe_squares = attacked_squares.size() + existing_count - intersection;
    long long safe_squares = total_squares - unsafe_squares;

    cout << safe_squares << endl;

    return 0;
}