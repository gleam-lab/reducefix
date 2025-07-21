#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    double x, y;
    double total_cost = 0.0;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        total_cost += hypot(x, y);
    }

    total_cost += hypot(0.0, 0.0); // Return to origin
    printf("%.10f\n", total_cost);
    return 0;
}