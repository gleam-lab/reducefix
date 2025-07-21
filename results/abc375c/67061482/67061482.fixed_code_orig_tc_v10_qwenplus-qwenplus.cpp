#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    double total = 0.0;
    double prev_x = 0.0, prev_y = 0.0;

    for (int i = 0; i < N; ++i) {
        double x, y;
        cin >> x >> y;
        total += hypot(x - prev_x, y - prev_y);
        prev_x = x;
        prev_y = y;
    }

    // Return to origin
    total += hypot(prev_x, prev_y);

    // Print with sufficient precision
    cout.precision(15);
    cout << fixed << total << endl;

    return 0;
}