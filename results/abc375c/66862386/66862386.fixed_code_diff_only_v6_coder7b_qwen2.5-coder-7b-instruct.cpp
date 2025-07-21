#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    long double x = 0, y = 0;
    long double total_cost = 0;

    for(int i = 0; i < n; i++) {
        int next_x, next_y;
        cin >> next_x >> next_y;

        // Calculate the Euclidean distance from current position to the next point
        long double dx = next_x - x;
        long double dy = next_y - y;
        total_cost += sqrt(dx * dx + dy * dy);

        // Update the current position
        x = next_x;
        y = next_y;
    }

    // Return to the origin
    total_cost += sqrt(x * x + y * y);

    cout << total_cost << endl;

    return 0;
}