#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<pair<double, double>> points(N);
    for (int i = 0; i < N; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    double total = 0.0;
    for (int i = 0; i < N - 1; ++i) {
        double dx = points[i + 1].first - points[i].first;
        double dy = points[i + 1].second - points[i].second;
        total += sqrt(dx * dx + dy * dy);
    }

    // Return to origin
    double dx = points[0].first;
    double dy = points[0].second;
    total += sqrt(dx * dx + dy * dy);

    printf("%.10f\n", total);

    return 0;
}