#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    double x = 0, y = 0, cost = 0.0;

    for (int i = 0; i < n; ++i) {
        int xi, yi;
        cin >> xi >> yi;
        cost += sqrt((xi - x) * (xi - x) + (yi - y) * (yi - y));
        x = xi;
        y = yi;
    }

    cost += sqrt(x * x + y * y); // Return to the origin
    cout << fixed << setprecision(10) << cost << endl;
    return 0;
}