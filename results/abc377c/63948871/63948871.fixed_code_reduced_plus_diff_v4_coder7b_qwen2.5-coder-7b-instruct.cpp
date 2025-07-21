#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    int piece_num;
    cin >> piece_num;

    set<pair<int, int>> anti_dup;
    vector<vector<bool>> board(N, vector<bool>(N, false));

    FOR_U(i, 0, piece_num, 1) {
        int x, y;
        cin >> x >> y;
        --x, --y; // Adjust for zero-based indexing

        anti_dup.insert({x, y});

        // Check all possible moves of a knight
        if (x + 2 < N && y + 1 < N) anti_dup.insert({x + 2, y + 1});
        if (x + 1 < N && y + 2 < N) anti_dup.insert({x + 1, y + 2});
        if (x - 1 >= 0 && y + 2 < N) anti_dup.insert({x - 1, y + 2});
        if (x - 2 >= 0 && y + 1 < N) anti_dup.insert({x - 2, y + 1});
        if (x - 2 >= 0 && y - 1 >= 0) anti_dup.insert({x - 2, y - 1});
        if (x - 1 >= 0 && y - 2 >= 0) anti_dup.insert({x - 1, y - 2});
        if (x + 1 < N && y - 2 >= 0) anti_dup.insert({x + 1, y - 2});
        if (x + 2 < N && y - 1 >= 0) anti_dup.insert({x + 2, y - 1});
    }

    int valid_positions = 0;
    FOR_U(i, 0, N, 1) {
        FOR_U(j, 0, N, 1) {
            if (!board[i][j] && !anti_dup.count({i, j})) {
                ++valid_positions;
            }
        }
    }

    cout << valid_positions << endl;

    return 0;
}