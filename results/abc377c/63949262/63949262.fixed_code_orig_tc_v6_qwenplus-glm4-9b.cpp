#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 1000000000; // Maximum grid size
bool captured[MAX_N][MAX_N]; // 2D array to mark captured squares

// Function to mark the capturing range of a piece
void captureRange(int x, int y) {
    // Implement capturing logic here, ensuring it doesn't go out of bounds
    // Example:
    if (x + 2 < MAX_N && y + 1 < MAX_N) captured[x + 2][y + 1] = true;
    // Add other capturing conditions...
}

int main() {
    int N, M;
    cin >> N >> M;

    // Initialize the captured array
    for (int i = 0; i < N; ++i) fill(captured[i], captured[i] + N, false);

    // Read existing pieces and mark their capturing areas
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--; // Convert to 0-based index
        captureRange(a, b);
    }

    // Count the number of empty squares
    long long emptyCount = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (!captured[i][j]) {
                ++emptyCount;
            }
        }
    }

    // Output the result
    cout << emptyCount << endl;

    return 0;
}