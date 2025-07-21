#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    
    long double total_cost = 0.0;
    long double x = 0, y = 0;
    
    for (int i = 0; i < n; ++i) {
        int x1, y1;
        cin >> x1 >> y1;
        total_cost += sqrt((x - x1) * (x - x1) + (y - y1) * (y - y1));
        x = x1;
        y = y1;
    }
    
    total_cost += sqrt(x * x + y * y);  // Return to origin
    
    cout.precision(20);
    cout << fixed << total_cost << endl;
    
    return 0;
}