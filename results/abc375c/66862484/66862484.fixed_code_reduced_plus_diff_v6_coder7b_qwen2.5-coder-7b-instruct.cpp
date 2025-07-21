#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<pair<long long, long long>> points(N);
    for (int i = 0; i < N; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    double totalCost = 0.0;
    for (int i = 0; i < N; ++i) {
        int x1 = points[i].first, y1 = points[i].second;
        int x2 = points[(i + 1) % N].first, y2 = points[(i + 1) % N].second;
        
        double dx = x2 - x1;
        double dy = y2 - y1;
        totalCost += sqrt(dx * dx + dy * dy);
    }

    printf("%.10f\n", totalCost);
    return 0;
}