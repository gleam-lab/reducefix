#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;

double calculateDistance(int x1, int y1, int x2, int y2) {
    return sqrt(static_cast<double>((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    double totalCost = 0;
    int startX = 0, startY = 0;

    for (const auto& point : points) {
        totalCost += calculateDistance(startX, startY, point.first, point.second);
        startX = point.first;
        startY = point.second;
    }

    // Return to the origin
    totalCost += calculateDistance(startX, startY, 0, 0);

    cout << fixed << setprecision(10) << totalCost << endl;
    return 0;
}