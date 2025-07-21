#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    long double total = 0.0;
    long double prevX = 0.0, prevY = 0.0;
    long double finalX = 0.0, finalY = 0.0;

    for (int i = 0; i < N; ++i) {
        long double x, y;
        cin >> x >> y;

        if (i == 0) {
            // First point: from origin to first point
            total += sqrtl((x - prevX) * (x - prevX) + (y - prevY) * (y - prevY));
            prevX = x;
            prevY = y;
        } else {
            // From previous point to current point
            total += sqrtl((x - prevX) * (x - prevX) + (y - prevY) * (y - prevY));
            prevX = x;
            prevY = y;
        }

        // Store the last point for return to origin
        finalX = x;
        finalY = y;
    }

    // Return to origin from last point
    total += sqrtl(finalX * finalX + finalY * finalY);

    // Print with sufficient precision
    cout.precision(15);
    cout << fixed << total << endl;

    return 0;
}