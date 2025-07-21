#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<long long, long long>> points;
    long long x, y;
    for (int i = 0; i < N; ++i) {
        cin >> x >> y;
        points.push_back({x, y});
    }

    long long cost = 0;
    long long nowX = 0, nowY = 0;
    
    // Calculate the cost of traveling to each point
    for (auto& point : points) {
        long long dx = point.first - nowX;
        long long dy = point.second - nowY;
        cost += sqrt(dx * dx + dy * dy);
        nowX = point.first;
        nowY = point.second;
    }
    
    // Calculate the cost of returning to the origin
    long long dx = nowX - 0;
    long long dy = nowY - 0;
    cost += sqrt(dx * dx + dy * dy);
    
    // Set precision for output
    cout << fixed << setprecision(12);
    cout << cost << endl;

    return 0;
}