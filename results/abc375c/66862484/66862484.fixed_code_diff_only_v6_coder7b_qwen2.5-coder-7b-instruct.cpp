#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    double curX = 0, curY = 0;   // Current position (origin)
    double total = 0;             // Total cost

    for (int i = 0; i < N; ++i) {
        double x, y;
        cin >> x >> y;

        double dx = curX - x;
        double dy = curY - y;
        total += sqrt(dx * dx + dy * dy);  // Correctly calculate the Euclidean distance

        curX = x; curY = y;
    }

    // Return to the origin from the last point
    total += sqrt(curX * curX + curY * curY);

    /* --- Output ---
       Directly print the floating-point number as required. */
    printf("%.10f\n", total);
    return 0;
}