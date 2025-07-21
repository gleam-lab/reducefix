#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N;
    long double x = 0, y = 0, total_cost = 0;

    for (int i = 0; i < N; i++) {
        long double X, Y;
        cin >> X >> Y;
        total_cost += sqrt((X - x) * (X - x) + (Y - y) * (Y - y));
        total_cost += sqrt((X - x) * (X - x) + (Y - y) * (Y - y));
        x = X;
        y = Y;
    }

    total_cost += sqrt(x * x + y * y); // Return to the origin
    cout.precision(10);
    cout << fixed << total_cost << endl; // Use fixed precision for output

    return 0;
}