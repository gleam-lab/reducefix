#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
using ll = long long;

const double PI = 3.14159265358979323846;

struct Point {
    double x, y;
};

double distance(Point a, Point b) {
    // Calculate the Euclidean distance between two points
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main() {
    int n;
    cin >> n;
    vector<Point> points(n);
    Point origin = {0.0, 0.0};

    // Read all points
    for (int i = 0; i < n; ++i) {
        cin >> points[i].x >> points[i].y;
    }

    // Initialize total distance with the distance from the origin to the first point
    double total_distance = distance(origin, points[0]);

    // Accumulate the total distance for the journey to the last point
    for (int i = 1; i < n; ++i) {
        total_distance += distance(points[i - 1], points[i]);
    }

    // Add the distance back to the origin
    total_distance += distance(points[n - 1], origin);

    // Output the total distance
    cout << fixed << setprecision(15) << total_distance << endl;

    return 0;
}