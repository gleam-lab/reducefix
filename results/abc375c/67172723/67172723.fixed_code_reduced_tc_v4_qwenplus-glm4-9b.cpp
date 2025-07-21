#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<pair<long long, long long>> points(N + 1);
    long long px = 0, py = 0;
    for (int i = 0; i <= N; ++i) {
        cin >> points[i].first >> points[i].second;
    }
    
    double ans = 0.0;
    for (int i = 0; i <= N; ++i) {
        long long x = points[i].first, y = points[i].second;
        ans += sqrt((x - px) * (x - px) + (y - py) * (y - py));
        px = x;
        py = y;
    }
    
    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}