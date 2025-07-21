#include <iostream>
#include <cmath>
using namespace std;

void solve() {
    int n;
    cin >> n;
    double x = 0.0, y = 0.0, total_distance = 0.0;

    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        // Calculate distance from current point (x, y) to the new point (a, b)
        double distance = sqrt((x - a) * (x - a) + (y - b) * (y - b));
        // Add distance to total
        total_distance += distance;
        // Update current point to new point
        x = a;
        y = b;
    }
    // Add distance back to the origin
    total_distance += sqrt(x * x + y * y);

    // Print the total distance
    cout << total_distance << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}