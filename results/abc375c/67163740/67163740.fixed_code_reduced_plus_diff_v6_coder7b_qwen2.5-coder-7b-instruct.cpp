#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const double EPS = 1e-9;

double dist(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

void solve() {
    int n;
    double x = 0, y = 0, t = 0;
    cin >> n;
    vector<pair<double, double>> points(n);
    for (auto &p : points) {
        cin >> p.first >> p.second;
    }
    for (int i = 0; i < n; ++i) {
        t += dist(x, y, points[i].first, points[i].second);
        x = points[i].first;
        y = points[i].second;
    }
    t += dist(x, y, 0, 0);
    cout << fixed << setprecision(10) << t << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout << endl;
    return 0;
}