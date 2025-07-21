#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    double x = 0, y = 0;
    double total_cost = 0;

    for (int i = 0; i < N; ++i) {
        int X, Y;
        cin >> X >> Y;
        total_cost += sqrt((X - x) * (X - x) + (Y - y) * (Y - y));
        x = X;
        y = Y;
    }

    total_cost += sqrt(x * x + y * y); // Adding the cost to return to the origin
    cout << fixed << setprecision(10) << total_cost << endl; // Set precision to 10 decimal places

    return 0;
}