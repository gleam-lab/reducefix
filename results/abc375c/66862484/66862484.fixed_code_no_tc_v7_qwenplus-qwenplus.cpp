#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    double total = 0.0;  // Use double for floating-point calculations

    long long prevX = 0, prevY = 0;  // Start at the origin

    for (int i = 0; i < N; ++i) {
        long long x, y;
        cin >> x >> y;

        long long dx = x - prevX;
        long long dy = y - prevY;

        total += sqrt(static_cast<double>(dx * dx + dy * dy));

        prevX = x;
        prevY = y;
    }

    // Return to the origin
    long long dx = -prevX;
    long long dy = -prevY;
    total += sqrt(static_cast<double>(dx * dx + dy * dy));

    // Print with sufficient precision
    cout.precision(15);
    cout << fixed << total << '\n';

    return 0;
}