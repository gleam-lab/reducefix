#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<pair<int, int>> points(N + 1); // +1 for the return to the origin

    for (int i = 0; i < N; i++) {
        cin >> points[i].first >> points[i].second;
    }
    
    long double total_cost = 0.0;
    
    // Calculate the cost from the origin to the first point and from the last point to the origin
    total_cost += sqrt(pow(points[0].first, 2) + pow(points[0].second, 2));
    total_cost += sqrt(pow(points[N-1].first, 2) + pow(points[N-1].second, 2));

    // Calculate the cost between consecutive points
    for (int i = 0; i < N - 1; i++) {
        total_cost += sqrt(pow(points[i].first - points[i + 1].first, 2) + pow(points[i].second - points[i + 1].second, 2));
    }

    cout.precision(10);
    cout << fixed << total_cost << endl;

    return 0;
}