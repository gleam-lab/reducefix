#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

double euclideanDistance(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    
    vector<pair<int, int>> points(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    // Add the starting point again to close the loop
    points[n] = points[0];

    double totalCost = 0.0;
    for (int i = 0; i < n; ++i) {
        totalCost += euclideanDistance(points[i].first, points[i].second, points[i + 1].first, points[i + 1].second);
    }

    cout << fixed << setprecision(12) << totalCost << endl;

    return 0;
}