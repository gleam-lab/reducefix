#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    long long curX = 0, curY = 0;   // Current position (origin)
    double total = 0.0;             // Total cost as double to accumulate square roots

    for (int i = 0; i < N; ++i) {
        long long x, y;
        cin >> x >> y;

        long long dx = curX - x;
        long long dy = curY - y;
        total += sqrt(dx * dx + dy * dy);  // Add the actual Euclidean distance

        curX = x; curY = y;
    }

    // Add the distance from the last point back to the origin
    total += sqrt(curX * curX + curY * curY);

    // Output with sufficient precision (at least 7 decimal places to meet 1e-6 error)
    cout << fixed << setprecision(15) << total << '\n';
    return 0;
}