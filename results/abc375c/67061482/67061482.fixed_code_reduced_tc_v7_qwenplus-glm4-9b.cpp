#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N;
    double x = 0, y = 0, total_cost = 0;

    for (int i = 0; i < N; ++i) {
        int X, Y;
        cin >> X >> Y;
        total_cost += sqrt((double)(X - x) * (X - x) + (Y - y) * (Y - y));
        x = X;
        y = Y;
    }

    total_cost += sqrt(x * x + y * y);
    cout.precision(12);
    cout << total_cost << endl;

    return 0;
}