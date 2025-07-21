#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<long long, long long>> points(N);
    long long startX = 0, startY = 0;
    for (int i = 0; i < N; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    double totalCost = 0.0;
    for (int i = 0; i < N; ++i) {
        long long x = points[i].first, y = points[i].second;
        totalCost += sqrt(pow(startX - x, 2) + pow(startY - y, 2));
        startX = x;
        startY = y;
    }
    // Calculate the distance back to the origin
    totalCost += sqrt(pow(startX, 2) + pow(startY, 2));

    // Set precision for output
    cout << fixed << setprecision(15);
    cout << totalCost << endl;

    return 0;
}