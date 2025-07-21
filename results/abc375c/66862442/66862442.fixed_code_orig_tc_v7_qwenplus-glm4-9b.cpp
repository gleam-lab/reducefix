#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<pair<int, int>> points(N);
    long long originX = 0, originY = 0;
    double totalDistance = 0;

    for (int i = 0; i < N; ++i) {
        cin >> points[i].first >> points[i].second;
        long long dx = originX - points[i].first;
        long long dy = originY - points[i].second;
        totalDistance += dx * dx + dy * dy;

        originX = points[i].first;
        originY = points[i].second;
    }
    totalDistance += sqrt((double)(originX * originX + originY * originY));

    cout << fixed << setprecision(6) << sqrt(totalDistance) << '\n';

    return 0;
}