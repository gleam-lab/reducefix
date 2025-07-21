#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const double EPS = 1e-9;

double dist(double x1, double y1, double x2, double y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

void solve() {
    int n;
    double x = 0, y = 0, t = 0;
    cin >> n;
    vector<pair<double, double>> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }
    for (int i = 0; i < n; ++i) {
        t += dist(points[i].first, points[i].second, x, y);
        x = points[i].first;
        y = points[i].second;
    }
    t += dist(x, y, 0, 0);
    cout << setprecision(20) << t << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout << endl;
    return 0;
}