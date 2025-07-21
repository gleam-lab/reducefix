#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Point {
    long long x, y;
};

double distance(const Point& p1, const Point& p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Point> points(n);
    for(int i = 0; i < n; ++i) {
        cin >> points[i].x >> points[i].y;
    }

    double total_distance = 0;

    // Start from origin
    Point current = {0, 0};
    
    for(int i = 0; i < n; ++i) {
        total_distance += distance(current, points[i]);
        current = points[i];
    }

    // Return to origin
    total_distance += distance(current, {0, 0});

    cout << setprecision(10) << total_distance << endl;

    return 0;
}