#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    long long curX = 0, curY = 0;   // Current position (origin)
    double total = 0.0;             // Total cost as double for square root

    for (int i = 0; i < N; ++i) {
        long long x, y;
        cin >> x >> y;

        long long dx = curX - x;
        long long dy = curY - y;
        total += sqrt(dx * dx + dy * dy);  // Add actual distance

        curX = x; curY = y;
    }

    // Add distance from last point back to origin
    total += sqrt(curX * curX + curY * curY);

    // Output with sufficient precision (up to 10^-6 error allowed)
    cout << fixed << setprecision(12) << total << '\n';
    return 0;
}