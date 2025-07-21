#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

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

    double total = 0.0;
    for (size_t i = 0; i < N - 1; ++i) {
        long long dx = points[i].first - points[i + 1].first;
        long long dy = points[i].second - points[i + 1].second;
        total += sqrt(dx * dx + dy * dy);
    }

    // Return to the origin
    long long dx = points[N - 1].first;
    long long dy = points[N - 1].second;
    total += sqrt(dx * dx + dy * dy);

    cout << fixed << setprecision(15) << total << endl;

    return 0;
}