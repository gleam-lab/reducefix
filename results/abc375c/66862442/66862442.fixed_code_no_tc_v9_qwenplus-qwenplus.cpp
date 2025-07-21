#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    double curX = 0.0, curY = 0.0;
    double total_cost = 0.0;

    for (int i = 0; i < N; ++i) {
        double x, y;
        cin >> x >> y;

        double dx = curX - x;
        double dy = curY - y;
        total_cost += sqrt(dx * dx + dy * dy);

        curX = x;
        curY = y;
    }

    // Return to origin
    total_cost += sqrt(curX * curX + curY * curY);

    // Print with sufficient precision
    cout << fixed << setprecision(15) << total_cost << '\n';

    return 0;
}