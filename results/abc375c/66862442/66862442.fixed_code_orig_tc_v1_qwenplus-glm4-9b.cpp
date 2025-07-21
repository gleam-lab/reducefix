#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    double curX = 0.0, curY = 0.0, totalCost = 0.0;

    for (int i = 0; i < N; ++i) {
        double x, y;
        cin >> x >> y;
        totalCost += sqrt((curX - x) * (curX - x) + (curY - y) * (curY - y));
        curX = x;
        curY = y;
    }
    totalCost += sqrt(curX * curX + curY * curY); // Add the distance back to the origin

    // Set precision and fixed format for the output
    cout << fixed << setprecision(10) << totalCost << '\n';

    return 0;
}