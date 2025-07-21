#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<pair<long long, long long>> points(N + 1);
    points[0] = {0, 0}; // Starting at the origin
    
    for (int i = 1; i <= N; ++i) {
        cin >> points[i].first >> points[i].second;
    }
    
    double totalCost = 0;
    for (int i = 1; i <= N; ++i) {
        long long dx = points[i].first - points[i - 1].first;
        long long dy = points[i].second - points[i - 1].second;
        totalCost += sqrt(dx * dx + dy * dy);
    }
    
    cout << fixed << setprecision(9) << totalCost << endl;
    
    return 0;
}