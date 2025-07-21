#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    long long curX = 0, curY = 0;   // Current position (origin)
    double total = 0;              // Total cost (double)

    for (int i = 0; i < N; ++i) {
        long long x, y;
        cin >> x >> y;

        long long dx = curX - x;
        long long dy = curY - y;
        total += sqrt(dx * dx + dy * dy);  // Correctly calculate the Euclidean distance

        curX = x; curY = y;
    }

    // Return to the origin from the last point
    total += sqrt(curX * curX + curY * curY);

    /* --- Output ---
       Print the total cost directly using printf for better precision */
    printf("%.6f\n", total);
    return 0;
}