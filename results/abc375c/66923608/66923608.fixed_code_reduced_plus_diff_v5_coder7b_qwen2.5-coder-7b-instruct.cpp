#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Function to calculate Euclidean distance between two points
double euclideanDistance(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    // Edge case: If there are no points or only one point, the cost is zero
    if (n <= 1) {
        cout << "0.000000000000" << endl;
        return 0;
    }

    vector<pair<ll, ll>> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    // Calculate the total cost of visiting all points in order and returning to the origin
    double totalCost = 0;
    for (int i = 0; i < n - 1; ++i) {
        totalCost += euclideanDistance(points[i].first, points[i].second, points[i + 1].first, points[i + 1].second);
    }
    totalCost += euclideanDistance(points[n - 1].first, points[n - 1].second, points[0].first, points[0].second);

    // Print the result with high precision
    cout << fixed << setprecision(12) << totalCost << endl;

    return 0;
}