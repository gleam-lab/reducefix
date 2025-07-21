#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    double x = 0, y = 0, total_cost = 0;

    for (int i = 0; i < n; ++i) {
        int dx, dy;
        cin >> dx >> dy;
        total_cost += sqrt(pow(dx - x, 2) + pow(dy - y, 2));
        x = dx;
        y = dy;
    }

    total_cost += sqrt(x * x + y * y); // Return to origin
    cout << total_cost << endl;

    return 0;
}