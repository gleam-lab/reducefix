#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <vector>
using namespace std;

struct Point {
    long long x, y;
};

double distance(const Point& p1, const Point& p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

int main() {
    int n;
    cin >> n;
    vector<Point> points(n);
    
    // Read all points
    for (int i = 0; i < n; ++i) {
        cin >> points[i].x >> points[i].y;
    }

    // Calculate the total cost
    double totalCost = 0.0;
    for (size_t i = 0; i < n - 1; ++i) {
        totalCost += distance(points[i], points[i + 1]);
    }
    totalCost += distance(points.back(), points.front()); // Return to origin

    // Print the result with high precision
    cout << setprecision(10) << totalCost << endl;

    return 0;
}