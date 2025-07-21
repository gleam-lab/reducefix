#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    double total = 0.0;
    int curr_x = 0, curr_y = 0;
    int prev_x = 0, prev_y = 0;

    for (int i = 0; i < n; ++i) {
        cin >> curr_x >> curr_y;
        total += hypot(curr_x - prev_x, curr_y - prev_y);
        prev_x = curr_x;
        prev_y = curr_y;
    }

    // Return to origin
    total += hypot(0 - curr_x, 0 - curr_y);

    // Print with sufficient precision
    printf("%.15f\n", total);

    return 0;
}