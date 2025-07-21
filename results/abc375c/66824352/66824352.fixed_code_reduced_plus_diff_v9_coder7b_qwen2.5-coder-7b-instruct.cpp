#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

double calculateDistance(int x1, int y1, int x2, int y2) {
    return sqrt(static_cast<double>(pow(x2 - x1, 2) + pow(y2 - y1, 2)));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<pair<int, int>> points(n);

    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    double totalCost = 0;

    // Calculate the cost of moving from one point to another
    for (size_t i = 1; i < points.size(); ++i) {
        totalCost += calculateDistance(points[i - 1].first, points[i - 1].second,
                                       points[i].first, points[i].second);
    }

    // Add the cost of returning to the origin
    totalCost += calculateDistance(points[0].first, points[0].second, 0, 0);

    cout << fixed << setprecision(10) << totalCost << endl;

    return 0;
}