#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;

    // Directions in which a piece can move to capture another piece
    vector<pair<long long, long long>> directions = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    set<pair<long long, long long>> unsafe_squares;

    for (long long i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        --a, --b; // Convert 1-based index to 0-based index

        for (auto& dir : directions) {
            long long x = a + dir.first;
            long long y = b + dir.second;
            while (x >= 0 && x < N && y >= 0 && y < N) {
                unsafe_squares.insert({x, y});
                x += dir.first;
                y += dir.second;
            }
        }
    }

    long long total_squares = N * N;
    long long safe_squares = total_squares - unsafe_squares.size();

    cout << safe_squares << endl;

    return 0;
}