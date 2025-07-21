#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n, x = 0, y = 0;
    double total_cost = 0.0;
    cin >> n;
    
    for (int i = 0; i < n; ++i) {
        int fx, fy;
        cin >> fx >> fy;
        total_cost += sqrt((fx - x) * (fx - x) + (fy - y) * (fy - y));
        x = fx;
        y = fy;
    }
    
    total_cost += sqrt(x * x + y * y);
    
    cout << fixed << setprecision(10) << total_cost << endl;
    
    return 0;
}