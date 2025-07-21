#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N;
    double a = 0, b = 0; // Starting point (0,0)
    double total_cost = 0; // Total cost variable
    double x, y;

    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        total_cost += sqrt((a - x) * (a - x) + (b - y) * (b - y));
        a = x;
        b = y;
    }

    // Calculate final distance back to the origin
    total_cost += sqrt((a - 0) * (a - 0) + (b - 0) * (b - 0));

    // Print the total cost
    cout.precision(6);
    cout << total_cost << endl;

    return 0;
}