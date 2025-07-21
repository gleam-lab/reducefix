#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    double x = 0, y = 0, total_cost = 0.0;

    for (int i = 0; i < n; i++) {
        int X, Y;
        cin >> X >> Y;
        total_cost += sqrt((x - X) * (x - X) + (y - Y) * (y - Y));
        x = X;
        y = Y;
    }
    total_cost += sqrt(x * x + y * y);

    cout.precision(10);
    cout << fixed << total_cost << endl;

    return 0;
}