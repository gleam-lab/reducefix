#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

double EuclideanDistance(int x1, int y1, int x2, int y2) {
    return sqrt(static_cast<double>(pow(x2 - x1, 2) + pow(y2 - y1, 2)));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    
    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    double totalCost = 0.0;

    // Calculate the distance for each segment
    for (int i = 0; i < n; ++i) {
        totalCost += EuclideanDistance(points[i].first, points[i].second, 
                                      points[(i + 1) % n].first, points[(i + 1) % n].second);
    }

    cout << fixed << setprecision(12) << totalCost << '\n';

    return 0;
}