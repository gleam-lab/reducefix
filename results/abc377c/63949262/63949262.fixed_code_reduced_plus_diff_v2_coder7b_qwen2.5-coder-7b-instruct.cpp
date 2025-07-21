#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M;
    cin >> N >> M;

    set<pair<long long, long long>> attacks;
    set<pair<long long, long long>> pieces;

    // Directions for knight moves
    vector<pair<int, int>> directions = {
        {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
        {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
    };

    for (long long i = 0; i < M; ++i) {
        long long x, y;
        cin >> x >> y;
        pieces.insert({x, y});

        // Mark all squares that can be attacked by this knight
        for (const auto& dir : directions) {
            long long nx = x + dir.first;
            long long ny = y + dir.second;
            if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
                attacks.insert({nx, ny});
            }
        }
    }

    // Calculate the number of valid squares
    long long valid_squares = N * N - attacks.size();

    cout << valid_squares << endl;

    return 0;
}