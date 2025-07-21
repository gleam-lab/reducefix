#include <iostream>
#include <cmath>
using namespace std;

main() {
    int n;
    cin >> n;
    double x = 0, y = 0, total_cost = 0.0;

    while (n--) {
        int a, b;
        cin >> a >> b;
        total_cost += sqrt((x - a) * (x - a) + (y - b) * (y - b));
        x = a;
        y = b;
    }

    // Add the distance from the last point back to the origin
    total_cost += sqrt(x * x + y * y);

    cout << fixed << setprecision(20) << total_cost << endl;

    return 0;
}