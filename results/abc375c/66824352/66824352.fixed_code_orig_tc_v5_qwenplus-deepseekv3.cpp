#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    double total_cost = 0.0;
    double prev_x = 0.0, prev_y = 0.0;
    
    for (int i = 0; i < n; i++) {
        double x, y;
        cin >> x >> y;
        double dx = x - prev_x;
        double dy = y - prev_y;
        total_cost += sqrt(dx*dx + dy*dy);
        prev_x = x;
        prev_y = y;
    }
    
    // Add distance back to origin
    total_cost += sqrt(prev_x*prev_x + prev_y*prev_y);
    
    cout << fixed << setprecision(10) << total_cost << endl;
    return 0;
}