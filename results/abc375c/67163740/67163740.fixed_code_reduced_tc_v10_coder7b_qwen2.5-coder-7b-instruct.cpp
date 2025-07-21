#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

double calculateDistance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<double, double>> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    double totalCost = 0;
    double currentX = 0, currentY = 0;

    // Calculate the cost of moving from the origin to each point
    for (const auto& point : points) {
        totalCost += calculateDistance(currentX, currentY, point.first, point.second);
        currentX = point.first;
        currentY = point.second;
    }

    // Calculate the cost of returning to the origin
    totalCost += calculateDistance(currentX, currentY, 0, 0);

    // Output the result with high precision
    cout << fixed << setprecision(20) << totalCost << '\n';

    return 0;
}