#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
using ll = long long;

struct Point {
    int x, y;
};

ll calculate_distance(const Point& p1, const Point& p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<Point> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].x >> points[i].y;
    }

    ll total_distance = 0;

    // Calculate the distance between consecutive points and add to the total distance
    for (int i = 0; i < n; ++i) {
        if (i < n - 1) {
            total_distance += calculate_distance(points[i], points[i + 1]);
        }
    }

    // Return to the origin, calculate the distance only once
    total_distance += calculate_distance(points[n - 1], {0, 0});
    // Multiply by 2 to account for the return trip to each point
    total_distance *= 2;

    // Print the total distance with required precision
    cout << fixed << setprecision(10) << total_distance << endl;

    return 0;
}