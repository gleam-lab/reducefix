#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct Point {
    long long x, y;
};

double distance(const Point &p1, const Point &p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

int main() {
    int n;
    cin >> n;
    vector<Point> points(n);
    for(int i = 0; i < n; ++i) {
        cin >> points[i].x >> points[i].y;
    }

    // Calculate the total distance
    double totalDistance = 0;
    for(int i = 0; i < n - 1; ++i) {
        totalDistance += distance(points[i], points[i+1]);
    }
    totalDistance += distance(points.back(), {0, 0}); // Return to the origin

    cout << fixed << setprecision(10) << totalDistance << endl;
    return 0;
}