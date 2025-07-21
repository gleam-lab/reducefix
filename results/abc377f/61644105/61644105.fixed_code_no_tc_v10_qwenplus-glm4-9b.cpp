#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;

    vector<pair<long long, long long>> positions(M);
    for (int i = 0; i < M; ++i) {
        long long x, y;
        cin >> x >> y;
        positions[i] = {x, y};
    }

    // Sort positions to use binary search later
    sort(positions.begin(), positions.end());
    const auto& pos = positions;

    // Initialize
    long long free_squares = N * N - M; // Start with total squares minus occupied ones

    // Check rows and columns
    for (int i = 0; i < M; ++i) {
        long long x = pos[i].first;
        long long y = pos[i].second;

        // Check if the current row or column is already free
        if (binary_search(pos.begin(), pos.begin() + i, make_pair(x, LLONG_MAX)) ||
            binary_search(pos.begin() + i + 1, pos.end(), make_pair(x, LLONG_MIN)) ||
            binary_search(pos.begin(), pos.begin() + i, make_pair(LLONG_MAX, y)) ||
            binary_search(pos.begin() + i + 1, pos.end(), make_pair(LLONG_MIN, y))) {
            free_squares--;
        }

        // Check diagonals
        {
            // Primary diagonal (x + y)
            long long diag1 = x + y;
            if (diag1 > 1 && (binary_search(pos.begin() + i + 1, pos.end(), make_pair(diag1, LLONG_MIN)) ||
                            binary_search(pos.begin(), pos.begin() + i, make_pair(diag1, LLONG_MAX)))) {
                free_squares--;
            }

            // Secondary diagonal (x - y)
            long long diag2 = x - y;
            if (diag2 > 1 && (binary_search(pos.begin() + i + 1, pos.end(), make_pair(diag2, LLONG_MIN)) ||
                            binary_search(pos.begin(), pos.begin() + i, make_pair(diag2, LLONG_MAX)))) {
                free_squares--;
            }
        }
    }

    cout << free_squares << endl;
    return 0;
}