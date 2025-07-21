#include <bits/stdc++.h>
using namespace std;

int main() {
    double x, y, initialX = 0, initialY = 0, totalCost = 0;

    int N;
    cin >> N;
    vector<pair<double, double>> points(N + 1);

    // Read the coordinates and include the origin at the start and end
    points[0] = {initialX, initialY};
    for (int i = 1; i <= N; ++i) {
        cin >> x >> y;
        points[i] = {x, y};
    }
    points[N + 1] = {initialX, initialY};

    // Calculate the total cost
    for (int i = 1; i <= N + 1; ++i) {
        double a = points[i - 1].first;
        double b = points[i - 1].second;
        double c = points[i].first;
        double d = points[i].second;
        totalCost += sqrt((a - c) * (a - c) + (b - d) * (b - d));
    }

    // Output the total cost
    cout.precision(10);
    cout << fixed << totalCost << endl;

    return 0;
}