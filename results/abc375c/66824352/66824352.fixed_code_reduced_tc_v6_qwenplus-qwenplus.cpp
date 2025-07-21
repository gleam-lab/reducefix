#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    long long x = 0, y = 0;
    double cost = 0.0;
    
    for (int i = 0; i < n; ++i) {
        long long xi, yi;
        cin >> xi >> yi;
        cost += sqrt((x - xi) * (x - xi) + (y - yi) * (y - yi));
        x = xi;
        y = yi;
    }
    
    // Return to origin
    cost += sqrt((double)x * x + (double)y * y);
    
    cout << fixed << setprecision(15) << cost << endl;
    return 0;
}