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
        long long x, y;
        cin >> x >> y;

        double dx = curX - x;
        double dy = curY - y;
        total += sqrt(dx * dx + dy * dy);  // Correctly calculate the Euclidean distance

        curX = x; curY = y;
    }

    // Return to the origin
    total += sqrt(curX * curX + curY * curY);

    // Output the result with appropriate precision
    printf("%.10f\n", total);

    return 0;
}