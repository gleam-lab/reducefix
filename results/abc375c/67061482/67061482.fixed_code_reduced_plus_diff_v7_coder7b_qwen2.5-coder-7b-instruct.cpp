#include <bits/stdc++.h>

using namespace std;

double distance(double x1, double y1, double x2, double y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    
    vector<pair<double, double>> points(N);
    for(int i = 0; i < N; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    double total_cost = 0;
    // Starting from origin
    total_cost += distance(0, 0, points[0].first, points[0].second);
    for(int i = 0; i < N - 1; ++i) {
        total_cost += distance(points[i].first, points[i].second, points[i + 1].first, points[i + 1].second);
    }
    // Returning to origin
    total_cost += distance(points[N - 1].first, points[N - 1].second, 0, 0);

    cout.precision(15);
    cout << total_cost << endl;

    return 0;
}