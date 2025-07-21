#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <queue>
#include <map>
#include <set>

using namespace std;

int main() {
    int n;
    long long x = 0, y = 0;
    long double c = 0.0L;
    
    cin >> n;
    vector<pair<long long, long long>> points(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }
    
    for (const auto& p : points) {
        c += sqrtl(powl(p.first - x, 2) + powl(p.second - y, 2));
        x = p.first;
        y = p.second;
    }
    
    c += sqrtl(x * x + y * y);
    
    cout << fixed << setprecision(10) << c << endl;
    
    return 0;
}