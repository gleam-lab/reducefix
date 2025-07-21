#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    int n, x = 0, y = 0;
    double max_dist = 0, total_distance = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int xi, yi;
        cin >> xi >> yi;
        double dist = sqrt((xi - x) * (xi - x) + (yi - y) * (yi - y));
        x = xi;
        y = yi;
        max_dist = max(max_dist, dist);
        total_distance += dist;
    }
    // Add the distance from the origin to the farthest point and back
    // because all other points are visited at least once and will be smaller
    double answer = 2 * max_dist + total_distance - max_dist * max_dist;
    cout << setprecision(10) << fixed << answer << endl;
    return 0;
}