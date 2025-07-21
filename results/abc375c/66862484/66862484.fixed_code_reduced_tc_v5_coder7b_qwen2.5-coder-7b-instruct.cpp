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
        total += sqrt(dx * dx + dy * dy);  // Include square root!

        curX = x; curY = y;
    }

    // Return from the last point to the origin
    total += sqrt(curX * curX + curY * curY);

    /* --- Output ---
       Print the result with precision up to 10^-6. */
    printf("%.10f\n", total);

    return 0;
}