#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    int x = 0, y = 0;
    double c = 0.0;
    
    for (int i = 0; i < n; ++i) {
        int xi, yi;
        cin >> xi >> yi;
        double dx = x - xi;
        double dy = y - yi;
        c += sqrt(dx * dx + dy * dy);
        x = xi;
        y = yi;
    }
    
    // Return to origin
    c += sqrt((double)x * x + (double)y * y);
    
    cout << fixed << setprecision(10) << c << endl;
    return 0;
}