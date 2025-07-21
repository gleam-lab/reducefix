#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    set<pair<int, int>> captured;
    set<pair<int, int>> pieces;

    vector<pair<int, int>> moves = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        pieces.insert({a, b});

        for (auto move : moves) {
            int x = a + move.first;
            int y = b + move.second;
            if (x >= 0 && x < N && y >= 0 && y < N) {
                captured.insert({x, y});
            }
        }
    }

    // The total safe squares are N^2 - (number of squares captured or occupied)
    long long total_squares = (long long)N * N;
    long long unsafe_squares = captured.size();

    // We need to count pieces that are in the captured set but not already occupied
    for (auto piece : pieces) {
        if (captured.count(piece)) {
            unsafe_squares--;
        }
    }

    // The safe squares are total_squares - unsafe_squares - M (since M squares are already occupied)
    cout << total_squares - unsafe_squares - M << endl;

    return 0;
}