#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N;
    double x = 0.0, y = 0.0;
    double total_cost = 0.0;

    for (int i = 0; i < N; ++i) {
        double nx, ny;
        cin >> nx >> ny;
        total_cost += sqrt((x - nx) * (x - nx) + (y - ny) * (y - ny));
        x = nx;
        y = ny;
    }

    // Calculate the cost to return to the origin
    total_cost += sqrt(x * x + y * y);

    cout << fixed << setprecision(10) << total_cost << endl;

    return 0;
}