#include <iostream>
using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    long long ans = n * n; // Total number of squares

    for (long long i = 0; i < m; ++i) {
        long long a, b;
        cin >> a >> b;
        // Calculate the range of squares that can be captured by the piece at (a, b)
        long long start_row = max(1LL, a - 2), end_row = min(n, a + 2);
        long long start_col = max(1LL, b - 2), end_col = min(n, b + 2);

        if (start_row <= end_row && start_col <= end_col) {
            // Calculate the number of squares that can be captured within this range
            long long capture_count = 0;
            for (long long row = start_row; row <= end_row; ++row) {
                for (long long col = start_col; col <= end_col; ++col) {
                    // Check if the square is on the diagonal of the "L" shape
                    if (abs(row - a) + abs(col - b) == 3) {
                        ++capture_count;
                    }
                }
            }
            // Subtract the number of captured squares from the total solvable squares
            ans -= capture_count;
        }
    }

    cout << ans << endl;
    return 0;
}