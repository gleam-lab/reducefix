#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    long long x = 0, y = 0;
    double c = 0.0;
    
    for (int i = 0; i < n; ++i) {
        long long xi, yi;
        cin >> xi >> yi;
        long long dx = x - xi;
        long long dy = y - yi;
        c += sqrt(dx * dx + dy * dy);
        x = xi;
        y = yi;
    }
    
    c += sqrt(x * x + y * y);
    cout << fixed << setprecision(15) << c << endl;
    
    return 0;
}