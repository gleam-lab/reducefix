#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;

    if (n == 0) {
        cout << "0" << endl;
        return 0;
    }

    vector<pair<long long, long long>> points(n);
    for (long long i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    double cost = 0;
    for (size_t i = 0; i < n - 1; ++i) {
        long long dx = points[i + 1].first - points[i].first;
        long long dy = points[i + 1].second - points[i].second;
        cost += hypot(dx, dy);
    }

    // Return to the origin
    long long lastX = points[n - 1].first;
    long long lastY = points[n - 1].second;
    cost += hypot(lastX, lastY);

    cout << fixed << setprecision(10) << cost << endl;
    return 0;
}