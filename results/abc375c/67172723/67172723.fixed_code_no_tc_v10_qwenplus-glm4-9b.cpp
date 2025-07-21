#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    double x = 0.0, y = 0.0;
    double total_cost = 0.0;
    
    for (int i = 0; i < n; ++i) {
        int X, Y;
        cin >> X >> Y;
        total_cost += hypot(x - X, y - Y);
        x = X;
        y = Y;
    }
    
    total_cost += hypot(x, y);
    printf("%.10f\n", total_cost);
    return 0;
}