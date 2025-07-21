#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

double euclideanDistance(int x1, int y1, int x2, int y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> x(n + 1), y(n + 1);
    x[0] = 0;
    y[0] = 0;

    for (int i = 1; i <= n; ++i) {
        cin >> x[i] >> y[i];
    }

    double totalCost = 0.0;

    for (int i = 1; i <= n; ++i) {
        totalCost += euclideanDistance(x[i - 1], y[i - 1], x[i], y[i]);
    }

    totalCost += euclideanDistance(x[n], y[n], x[0], y[0]);

    cout << fixed << setprecision(12) << totalCost << endl;

    return 0;
}