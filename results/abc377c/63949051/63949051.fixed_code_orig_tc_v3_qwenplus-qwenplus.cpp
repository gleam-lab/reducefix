// C++ code to solve the problem of determining how many squares a knight cannot attack on a large board.

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    int M;
    cin >> N >> M;

    set<pair<int, int>> attacked_squares;
    set<pair<int, int>> occupied;

    const vector<pair<int, int>> knight_moves = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        occupied.insert({a, b});
        for (auto [dx, dy] : knight_moves) {
            int x = a + dx;
            int y = b + dy;
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                attacked_squares.insert({x, y});
            }
        }
    }

    // Remove already occupied squares from attacked squares
    for (auto p : occupied) {
        attacked_squares.erase(p);
    }

    // Total squares = N*N
    // Available empty squares = total - occupied - attacked
    cout << (unsigned long long)(N * 1ULL * N) - occupied.size() - attacked_squares.size() << "\n";

    return 0;
}