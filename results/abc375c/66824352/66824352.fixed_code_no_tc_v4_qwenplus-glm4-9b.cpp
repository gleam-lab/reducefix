#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n, x = 0, y = 0;
    double total_cost = 0.0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int xi, yi;
        cin >> xi >> yi;
        total_cost += sqrt(pow(xi - x, 2) + pow(yi - y, 2));
        x = xi;
        y = yi;
    }

    // Add the return to the origin
    total_cost += sqrt(pow(x, 2) + pow(y, 2));

    cout << fixed << setprecision(10) << total_cost << endl;

    return 0;
}