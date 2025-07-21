#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> moves = {{0, 0}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
    set<pair<int, int>> occupied;

    // Reading occupied squares
    for (int i = 0; i < M; ++i) {
        int r, c;
        cin >> r >> c;
        occupied.insert({r - 1, c - 1});
    }

    long long freeSquares = N * N; // Total squares
    long long captured = 0; // Squares that can be captured by any of the occupied pieces

    // Check each occupied piece and calculate the number of squares it captures
    for (const auto& p : occupied) {
        for (const auto& m : moves) {
            int captured_r = p.first + m.first;
            int captured_c = p.second + m.second;
            // Check if the captured square is within bounds
            if (captured_r >= 0 && captured_r < N && captured_c >= 0 && captured_c < N) {
                captured++;
            } else {
                // If the capture goes out of bounds, calculate the number of squares it can still capture
                int limit_r = min(max(0, p.first - m.first), N - 1);
                int limit_c = min(max(0, p.second - m.second), N - 1);
                captured += (limit_r + 1) * (limit_c + 1);
            }
        }
    }

    // The answer is the total squares minus the captured squares
    cout << freeSquares - captured << endl;

    return 0;
}