#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    set<pair<int, int>> capturedSquares;

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--; // Convert to zero-based index

        // Check all possible capture positions for the current piece
        for (int dx = -2; dx <= 2; ++dx) {
            for (int dy = -2; dy <= 2; ++dy) {
                if (dx != 0 || dy != 0) { // Skip checking the piece itself
                    int x = a + dx;
                    int y = b + dy;
                    if (x >= 0 && x < N && y >= 0 && y < N) {
                        capturedSquares.insert({x, y});
                    }
                }
            }
        }
    }

    // Output the number of empty squares
    cout << N * N - capturedSquares.size() << endl;

    return 0;
}