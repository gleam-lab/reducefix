#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    vector<pair<long long, long long>> points(N);
    
    for(int i = 0; i < N; ++i) {
        cin >> points[i].first >> points[i].second;
    }
    
    double total_cost = 0.0;
    pair<long long, long long> current_point(0, 0);
    
    for(const auto& point : points) {
        long long dx = point.first - current_point.first;
        long long dy = point.second - current_point.second;
        total_cost += sqrt(dx * dx + dy * dy);
        current_point = point;
    }
    
    // Return to the origin
    long long dx = current_point.first;
    long long dy = current_point.second;
    total_cost += sqrt(dx * dx + dy * dy);
    
    cout << fixed << setprecision(10) << total_cost << endl;
    
    return 0;
}