#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    double curX = 0, curY = 0;   // Current position (origin)
    double total = 0;           // Total cost

    for (int i = 0; i < N; ++i) {
        double x, y;
        cin >> x >> y;

        double dx = curX - x;
        double dy = curY - y;
        total += std::hypot(dx, dy);  // Correctly compute the Euclidean distance

        curX = x; 
        curY = y;
    }

    // Return to the origin from the last point
    total += std::hypot(curX, curY);

    // Print the result with high precision
    printf("%.15f\n", total);

    return 0;
}