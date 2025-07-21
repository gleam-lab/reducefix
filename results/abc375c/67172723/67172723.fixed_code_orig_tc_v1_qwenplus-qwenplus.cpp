#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    double total = 0;
    int prev_x = 0, prev_y = 0;
    int curr_x, curr_y;

    for (int i = 0; i < n; ++i) {
        cin >> curr_x >> curr_y;
        int dx = curr_x - prev_x;
        int dy = curr_y - prev_y;
        total += sqrt(static_cast<double>(dx * dx + dy * dy));
        prev_x = curr_x;
        prev_y = curr_y;
    }

    // Return to origin
    int dx = 0 - prev_x;
    int dy = 0 - prev_y;
    total += sqrt(static_cast<double>(dx * dx + dy * dy));

    printf("%.15f\n", total);
    return 0;
}