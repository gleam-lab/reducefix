#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    double curX = 0.0, curY = 0.0;
    double totalCost = 0.0;

    for (int i = 0; i < N; ++i) {
        long long x, y;
        cin >> x >> y;

        double dx = curX - x;
        double dy = curY - y;
        totalCost += sqrt(dx * dx + dy * dy);

        curX = x;
        curY = y;
    }

    // Return to origin
    double dx = curX;
    double dy = curY;
    totalCost += sqrt(dx * dx + dy * dy);

    // Print with sufficient precision
    cout.precision(15);
    cout << fixed << totalCost << '\n';

    return 0;
}