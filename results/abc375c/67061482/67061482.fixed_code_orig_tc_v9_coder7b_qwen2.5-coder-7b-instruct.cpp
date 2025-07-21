#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-9;

double distance(double x1, double y1, double x2, double y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<double> x(N + 1), y(N + 1);
    x[0] = y[0] = 0;

    for (int i = 1; i <= N; ++i) {
        cin >> x[i] >> y[i];
    }

    double ans = 0;
    for (int i = 1; i <= N; ++i) {
        ans += distance(x[i - 1], y[i - 1], x[i], y[i]);
    }
    ans += distance(x[N], y[N], x[0], y[0]);

    printf("%.15f\n", ans);

    return 0;
}