#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    long long curX = 0, curY = 0;   // Current position (origin)
    double total = 0.0;             // Total cost as a double to accumulate square roots

    for (int i = 0; i < N; ++i) {
        long long x, y;
        cin >> x >> y;

        long long dx = curX - x;
        long long dy = curY - y;
        total += sqrt(dx * dx + dy * dy);  // Now with sqrt!

        curX = x; curY = y;
    }

    // Return to origin from the last point
    total += sqrt(curX * curX + curY * curY);

    // Output with sufficient precision (up to 10^-6 relative error)
    cout << fixed << setprecision(15) << total << '\n';
    return 0;
}