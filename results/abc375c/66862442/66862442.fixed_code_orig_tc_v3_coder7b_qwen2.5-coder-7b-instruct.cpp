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
    for(int i = 0; i < N; ++i){
        cin >> points[i].first >> points[i].second;
    }

    double total_cost = 0.0;

    for(int i = 1; i < N; ++i){
        long long dx = points[i].first - points[i - 1].first;
        long long dy = points[i].second - points[i - 1].second;
        total_cost += sqrt(dx * dx + dy * dy);
    }

    // Add distance back to origin
    long long dx = points[0].first - points[N - 1].first;
    long long dy = points[0].second - points[N - 1].second;
    total_cost += sqrt(dx * dx + dy * dy);

    cout << fixed << setprecision(15) << total_cost << '\n';

    return 0;
}