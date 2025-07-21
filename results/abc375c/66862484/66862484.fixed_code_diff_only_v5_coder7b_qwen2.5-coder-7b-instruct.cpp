#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    double curX = 0, curY = 0;   // Current position (origin)
    double total = 0;             // Total cost (double type)

    for (int i = 0; i < N; ++i) {
        double x, y;
        cin >> x >> y;

        double dx = curX - x;
        double dy = curY - y;
        total += sqrt(dx * dx + dy * dy);  // Include square root!

        curX = x; curY = y;
    }

    // Return from the last point to the origin
    total += sqrt(curX * curX + curY * curY);

    // Output the result with precision up to 6 decimal places
    printf("%.6f\n", total);

    return 0;
}