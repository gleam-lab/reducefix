#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long x = 0, y = 0;
    double total_cost = 0.0;
    
    for (int i = 0; i < n; ++i) {
        long long xi, yi;
        cin >> xi >> yi;
        double dx = x - xi;
        double dy = y - yi;
        total_cost += sqrt(dx * dx + dy * dy);
        x = xi;
        y = yi;
    }
    
    double dx = x;
    double dy = y;
    total_cost += sqrt(dx * dx + dy * dy);
    
    cout << fixed << setprecision(15) << total_cost << endl;
    return 0;
}