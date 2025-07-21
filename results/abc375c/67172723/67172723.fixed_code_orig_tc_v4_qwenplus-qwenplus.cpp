#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int curr_x = 0, curr_y = 0;
    double total_cost = 0;

    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        total_cost += hypot(x - curr_x, y - curr_y);
        curr_x = x;
        curr_y = y;
    }

    // Return to origin from the last point
    total_cost += hypot(0 - curr_x, 0 - curr_y);

    printf("%.10f\n", total_cost);
    return 0;
}