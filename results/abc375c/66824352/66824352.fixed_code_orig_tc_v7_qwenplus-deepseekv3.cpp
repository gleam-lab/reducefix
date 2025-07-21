#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    double total_cost = 0.0;
    long long prev_x = 0, prev_y = 0;
    
    for (int i = 0; i < n; ++i) {
        long long x, y;
        cin >> x >> y;
        double dx = x - prev_x;
        double dy = y - prev_y;
        total_cost += sqrt(dx * dx + dy * dy);
        prev_x = x;
        prev_y = y;
    }
    
    double dx = prev_x;
    double dy = prev_y;
    total_cost += sqrt(dx * dx + dy * dy);
    
    cout << fixed << setprecision(10) << total_cost << endl;
    
    return 0;
}