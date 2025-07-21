#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int N; cin >> N;
    vector<pair<int, int>> points(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> points[i].first >> points[i].second;
    }
    
    double total_cost = 0.0;
    for (int i = 0; i < N; ++i) {
        if (i > 0) {
            total_cost += sqrt(pow(points[i].first - points[i-1].first, 2) +
                                pow(points[i].second - points[i-1].second, 2));
        }
        // Add the distance from the last point to the origin
        if (i == N - 1) {
            total_cost += sqrt(pow(points[i].first, 2) + pow(points[i].second, 2));
        }
    }
    
    cout << fixed << setprecision(12) << total_cost << endl;
    
    return 0;
}