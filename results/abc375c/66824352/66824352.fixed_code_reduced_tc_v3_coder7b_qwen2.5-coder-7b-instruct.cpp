#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    int n;
    double x = 0, y = 0, total_cost = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int xi, yi;
        cin >> xi >> yi;
        total_cost += sqrt(x * x + y * y);
        total_cost += sqrt(xi * xi + yi * yi);
        total_cost += sqrt((xi - x) * (xi - x) + (yi - y) * (yi - y));
        x = xi;
        y = yi;
    }
    total_cost += sqrt(x * x + y * y); // Return to origin
    cout << setprecision(10) << total_cost << endl;
    return 0;
}