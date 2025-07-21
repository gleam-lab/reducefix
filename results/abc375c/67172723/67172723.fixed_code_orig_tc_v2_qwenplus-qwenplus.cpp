#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    double total = 0.0;
    int prev_x = 0, prev_y = 0;

    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        double dx = static_cast<double>(x - prev_x);
        double dy = static_cast<double>(y - prev_y);
        total += sqrt(dx * dx + dy * dy);
        prev_x = x;
        prev_y = y;
    }

    // Return to origin
    double dx = static_cast<double>(prev_x);
    double dy = static_cast<double>(prev_y);
    total += sqrt(dx * dx + dy * dy);

    // Print with sufficient precision
    cout.precision(15);
    cout << fixed << total << endl;

    return 0;
}