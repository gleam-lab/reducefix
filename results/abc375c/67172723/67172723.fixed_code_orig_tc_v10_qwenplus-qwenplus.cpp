#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    double total = 0.0;
    int curr_x = 0, curr_y = 0;
    int next_x, next_y;

    for (int i = 0; i < n; ++i) {
        cin >> next_x >> next_y;
        total += hypot(static_cast<double>(next_x - curr_x), static_cast<double>(next_y - curr_y));
        curr_x = next_x;
        curr_y = next_y;
    }

    // Return to origin
    total += hypot(static_cast<double>(-curr_x), static_cast<double>(-curr_y));

    // Output with sufficient precision
    printf("%.15f\n", total);

    return 0;
}