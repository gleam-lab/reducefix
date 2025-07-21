#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int N;
    cin >> N;

    double x = 0, y = 0;
    double total_cost = 0.0;

    for (int i = 0; i < N; i++) {
        int x2, y2;
        cin >> x2 >> y2;
        total_cost += sqrt(pow(x2 - x, 2) + pow(y2 - y, 2));
        x = x2;
        y = y2;
    }

    // Return to the origin
    total_cost += sqrt(pow(x, 2) + pow(y, 2));

    cout.precision(10);
    cout << fixed << total_cost << endl;

    return 0;
}