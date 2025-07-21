#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

const double EPS = 1e-9;

bool almostEqual(double a, double b) {
    return fabs(a - b) < EPS;
}

double euclidDistance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

int main() {
    int n; cin >> n;
    vector<pair<double, double>> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }
    
    double totalDistance = 0.0;
    for (int i = 0; i < n; ++i) {
        totalDistance += euclidDistance(points[i].first, points[i].second, points[(i + 1) % n].first, points[(i + 1) % n].second);
    }
    
    cout << fixed << setprecision(12) << totalDistance << endl;
    return 0;
}