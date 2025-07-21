#include <iostream>
#include <set>
#include <utility>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    set<pair<int, int>> captured_squares;

    for (int i = 0; i < M; ++i) {
        int x, y;
        cin >> x >> y;
        x--; y--; // Convert to 0-based indexing

        // Check all possible capture positions
        for (int dx = -2; dx <= 2; dx++) {
            for (int dy = -2; dy <= 2; dy++) {
                if (dx == 0 && dy == 0) continue; // Skip the current position
                int nx = x + dx;
                int ny = y + dy;
                if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                    captured_squares.insert({nx, ny});
                }
            }
        }
    }

    // Calculate the number of uncaptureable squares
    long long total_squares = N * N;
    long long capture_count = captured_squares.size();
    cout << total_squares - capture_count << endl;

    return 0;
}