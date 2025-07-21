#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    double total = 0.0;
    int prev_x = 0, prev_y = 0;
    int curr_x, curr_y;

    for (int i = 0; i < n; ++i) {
        cin >> curr_x >> curr_y;
        total += hypot(curr_x - prev_x, curr_y - prev_y);
        prev_x = curr_x;
        prev_y = curr_y;
    }

    // Return to origin
    total += hypot(0 - prev_x, 0 - prev_y);

    cout.precision(15);
    cout << fixed << total << endl;

    return 0;
}