#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<double, double>> points;
    double x, y;
    for (int i = 0; i < N; ++i) {
        cin >> x >> y;
        points.push_back({x, y});
    }

    double ans = 0.0;
    double nowX = 0.0, nowY = 0.0;

    for (const auto& point : points) {
        double nextX = point.first;
        double nextY = point.second;
        ans += sqrt((nextX - nowX) * (nextX - nowX) + (nextY - nowY) * (nextY - nowY));
        nowX = nextX;
        nowY = nextY;
    }

    // Return to the origin
    ans += sqrt(nowX * nowX + nowY * nowY);

    cout << fixed << setprecision(12) << ans << endl;

    return 0;
}