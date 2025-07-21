#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

struct Point {
    long long x, y;
    double dist_to_origin;
};

int main() {
    int n;
    cin >> n;

    vector<Point> points(n + 1); // +1 to include the origin in the vector

    // Calculate distance from origin and store it
    points[0].x = 0;
    points[0].y = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> points[i].x >> points[i].y;
        points[i].dist_to_origin = sqrt(points[i].x * points[i].x + points[i].y * points[i].y);
    }

    double total_cost = 0.0;

    // Calculate the total cost to travel from the origin to each point and back
    for (int i = 1; i <= n; ++i) {
        total_cost += points[i].dist_to_origin; // distance to each point
        if (i < n) {
            total_cost += sqrt((points[i].x - points[i + 1].x) * (points[i].x - points[i + 1].x) + (points[i].y - points[i + 1].y) * (points[i].y - points[i + 1].y));
        }
    }

    // Set precision and print the result
    cout << fixed << setprecision(12) << total_cost << endl;

    return 0;
}