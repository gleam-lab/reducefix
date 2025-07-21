#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    
    // If there are no points, the total cost is 0
    if (n == 0) {
        cout << "0" << endl;
        return 0;
    }

    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    double totalCost = 0.0;
    int startX = 0, startY = 0;

    for (const auto& point : points) {
        totalCost += sqrt(pow(startX - point.first, 2) + pow(startY - point.second, 2));
        startX = point.first;
        startY = point.second;
    }

    // Add the cost to return to the origin
    totalCost += sqrt(pow(startX, 2) + pow(startY, 2));

    cout << setprecision(10) << totalCost << endl;

    return 0;
}