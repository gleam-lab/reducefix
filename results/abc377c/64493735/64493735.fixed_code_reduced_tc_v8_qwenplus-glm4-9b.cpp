#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 1000000000;
const int MAX_M = 200000;
const int MAXCapt = 32; // Maximum capture distance based on the problem statement

int N, M;
vector<int> capturedSquares[MAX_N + 1]; // Store captured squares in 1D array for memory efficiency

void markCapturedSquares() {
    for (int i = 1; i <= M; ++i) {
        int a, b;
        cin >> a >> b;

        // Mark all squares that the piece can capture
        for (int dx = -2; dx <= 2; dx++) {
            for (int dy = -2; dy <= 2; dy++) {
                if (dx == 0 && dy == 0) continue; // Skip the piece's own square
                if (dx == 0) dy = -dy; // Ensure dx and dy are not both zero for direct diagonal moves
                int nx = a + dx, ny = b + dy;
                if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
                    capturedSquares[nx].push_back(ny);
                }
            }
        }
    }
}

int main() {
    cin >> N >> M;
    markCapturedSquares();

    int safeSquares = 0;
    // Count all unmarked squares
    for (int i = 1; i <= N; ++i) {
        int count = 0;
        for (const int& y : capturedSquares[i]) {
            count++;
            if (count > MAXCapt) break; // More captures than possible, stop processing
        }
        safeSquares += N - count; // Add unmarked squares in this row
    }

    cout << safeSquares << endl;
    return 0;
}