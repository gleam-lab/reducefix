#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<pair<long long, long long>> points(N + 1);
    
    for (int i = 0; i < N; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    double total_cost = 0.0;
    long long origin_x = 0, origin_y = 0;

    for (int i = 0; i <= N; ++i) {
        long long x = points[i].first;
        long long y = points[i].second;
        total_cost += sqrt(pow(origin_x - x, 2) + pow(origin_y - y, 2));
        origin_x = x;
        origin_y = y;
    }

    cout.precision(10);
    cout << fixed << total_cost << endl;

    return 0;
}