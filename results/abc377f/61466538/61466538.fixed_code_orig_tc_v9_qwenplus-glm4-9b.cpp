#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

// Directions for row, column, and diagonals
const vector<tuple<int, int>> DIRECTIONS = {
    {1, 0}, {-1, 0}, {0, 1}, {0, -1}, // Up, Down, Right, Left
    {1, 1}, {1, -1}, {-1, 1}, {-1, -1} // Diagonal (top-left to bottom-right)
};

int main() {
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> pieces(M);
    for (int i = 0; i < M; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
    }

    set<pair<int, int>> invalidPositions;
    for (int i = 0; i < M; ++i) {
        auto [x, y] = pieces[i];
        for (auto [dx, dy] : DIRECTIONS) {
            int nx = x, ny = y;
            while (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
                invalidPositions.insert({nx, ny});
                nx += dx;
                ny += dy;
            }
        }
    }

    // Calculate the number of valid positions
    long long validPositions = N * N - invalidPositions.size();
    cout << validPositions << endl;
    return 0;
}