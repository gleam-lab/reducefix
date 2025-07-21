#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    double total_cost = 0.0;
    double x = 0.0, y = 0.0;

    for (int i = 0; i < N; ++i) {
        int X, Y;
        cin >> X >> Y;

        double cost = sqrt(pow(x - X, 2) + pow(y - Y, 2));
        total_cost += cost;

        x = X;
        y = Y;
    }

    double final_cost = sqrt(pow(x, 2) + pow(y, 2));
    total_cost += final_cost;

    cout.precision(15);
    cout << fixed << total_cost << '\n';

    return 0;
}