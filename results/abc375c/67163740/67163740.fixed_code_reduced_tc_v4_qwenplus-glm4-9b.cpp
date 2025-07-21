#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
using ll = long long;

struct Point {
    ll x, y;
};

ll dist(const Point& a, const Point& b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<Point> points(n + 1);

    points[0].x = 0;
    points[0].y = 0;

    for (int i = 1; i <= n; ++i) {
        cin >> points[i].x >> points[i].y;
    }

    ll total_cost = 0;
    for (int i = 1; i <= n; ++i) {
        total_cost += dist(points[i - 1], points[i]);
    }
    total_cost += dist(points[n], points[0]);

    cout << fixed << setprecision(12) << total_cost << endl;

    return 0;
}