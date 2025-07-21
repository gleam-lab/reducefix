#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    double total = 0.0;
    long long curX = 0, curY = 0;   // Current position starts at origin

    for (int i = 0; i < N; ++i) {
        long long x, y;
        cin >> x >> y;

        long long dx = curX - x;
        long long dy = curY - y;
        total += sqrt(dx * dx + dy * dy);  // Add the actual distance

        curX = x;
        curY = y;
    }

    // Add the distance from the last point back to the origin
    total += sqrt(curX * curX + curY * curY);

    // Print the result with sufficient precision
    cout << fixed << setprecision(15) << total << '\n';

    return 0;
}