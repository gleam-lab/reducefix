#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct Point {
    long long x, y;
};

bool compare(const Point& a, const Point& b) {
    double angleA = atan2(a.y, a.x);
    double angleB = atan2(b.y, b.x);
    if (angleA < angleB) return true;
    if (angleA > angleB) return false;
    return a.x < b.x; // If angles are the same, sort by x-coordinate
}

int main() {
    int N;
    cin >> N;

    vector<Point> points(N);
    for (int i = 0; i < N; ++i) {
        cin >> points[i].x >> points[i].y;
    }

    sort(points.begin(), points.end(), compare);

    long double totalDistance = 0;
    long long lastX = 0, lastY = 0;

    for (int i = 0; i < N; ++i) {
        long long dx = points[i].x - lastX;
        long long dy = points[i].y - lastY;
        totalDistance += sqrt(dx * dx + dy * dy);
        lastX = points[i].x;
        lastY = points[i].y;
    }

    // Add the distance back to the origin
    long long dx = -lastX;
    long long dy = -lastY;
    totalDistance += sqrt(dx * dx + dy * dy);

    cout.precision(10);
    cout << fixed << totalDistance << endl;

    return 0;
}