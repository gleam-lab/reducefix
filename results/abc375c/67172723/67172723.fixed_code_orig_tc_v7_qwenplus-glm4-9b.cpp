#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;

    double x = 0, y = 0, total_cost = 0.0;
    double x1, y1;
    
    // Calculate the distance from the origin to the first point
    cin >> x1 >> y1;
    total_cost = hypot(x1 - x, y1 - y);
    x = x1;
    y = y1;

    // Calculate the distance between each consecutive point
    for (int i = 1; i < n; ++i) {
        cin >> x1 >> y1;
        total_cost += hypot(x1 - x, y1 - y);
        x = x1;
        y = y1;
    }

    // Calculate the distance from the last point to the origin
    cin >> x1 >> y1;
    total_cost += hypot(x1 - x, y1 - y);

    // Output the total cost
    printf("%.10f\n", total_cost);
    return 0;
}