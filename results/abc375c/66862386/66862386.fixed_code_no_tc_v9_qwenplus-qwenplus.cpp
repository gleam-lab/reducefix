#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    long double total = 0.0;
    int curr_x = 0, curr_y = 0;

    for (int i = 0; i < n; ++i) {
        int next_x, next_y;
        cin >> next_x >> next_y;

        int dx = next_x - curr_x;
        int dy = next_y - curr_y;
        total += sqrtl(static_cast<long double>(dx * dx + dy * dy));

        curr_x = next_x;
        curr_y = next_y;
    }

    // Return to origin
    total += sqrtl(static_cast<long double>(curr_x * curr_x + curr_y * curr_y));

    cout << fixed << setprecision(15) << total << '\n';

    return 0;
}