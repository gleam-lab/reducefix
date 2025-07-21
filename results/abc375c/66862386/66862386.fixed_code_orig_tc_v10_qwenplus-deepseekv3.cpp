#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    long double total_distance = 0.0;
    int prev_x = 0, prev_y = 0;

    for (int i = 0; i < N; ++i) {
        int x, y;
        cin >> x >> y;
        long double dx = x - prev_x;
        long double dy = y - prev_y;
        total_distance += sqrtl(dx * dx + dy * dy);
        prev_x = x;
        prev_y = y;
    }

    // Add the distance back to the origin
    long double dx = 0 - prev_x;
    long double dy = 0 - prev_y;
    total_distance += sqrtl(dx * dx + dy * dy);

    // Output with sufficient precision (20 decimal places)
    cout << fixed << setprecision(20) << total_distance << endl;

    return 0;
}