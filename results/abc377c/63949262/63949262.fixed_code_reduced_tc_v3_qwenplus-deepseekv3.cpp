#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M;
    cin >> N >> M;

    set<pair<long long, long long>> unsafe_squares;
    vector<pair<long long, long long>> pieces(M);

    for (long long i = 0; i < M; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
        unsafe_squares.insert(pieces[i]);
    }

    for (const auto &piece : pieces) {
        long long i = piece.first;
        long long j = piece.second;

        // All 8 possible knight moves
        const vector<pair<long long, long long>> moves = {
            {i + 2, j + 1},
            {i + 1, j + 2},
            {i - 1, j + 2},
            {i - 2, j + 1},
            {i - 2, j - 1},
            {i - 1, j - 2},
            {i + 1, j - 2},
            {i + 2, j - 1}
        };

        for (const auto &move : moves) {
            long long x = move.first;
            long long y = move.second;
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                unsafe_squares.insert({x, y});
            }
        }
    }

    long long total_squares = N * N;
    long long unsafe_count = unsafe_squares.size();
    long long safe_count = total_squares - unsafe_count;

    cout << safe_count << endl;

    return 0;
}