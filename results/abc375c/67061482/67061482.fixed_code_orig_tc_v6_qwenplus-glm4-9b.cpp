#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<pair<double, double>> coordinates;
    double x, y, currentX = 0.0, currentY = 0.0, totalCost = 0.0;

    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        coordinates.push_back({x, y});
    }

    // Calculate the cost of moving from the origin to each point and back to the origin
    for (const auto& point : coordinates) {
        totalCost += sqrt(pow(currentX - point.first, 2) + pow(currentY - point.second, 2));
        currentX = point.first;
        currentY = point.second;
    }

    // Return to the origin and add the final distance
    totalCost += sqrt(pow(currentX - 0.0, 2) + pow(currentY - 0.0, 2));

    cout.precision(9);
    cout << fixed << totalCost << endl;

    return 0;
}