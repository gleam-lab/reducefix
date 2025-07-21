#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cin >> n;

    long x = 0, y = 0; // Starting point is the origin, so x and y are initially 0
    double total_distance = 0;

    for (int i = 0; i < n; ++i) {
        long x1, y1;
        cin >> x1 >> y1;
        total_distance += sqrt((x - x1) * (x - x1) + (y - y1) * (y - y1));
        x = x1;
        y = y1;
    }

    // Calculate the distance from the last point back to the origin
    total_distance += sqrt((x - 0) * (x - 0) + (y - 0) * (y - 0));

    cout << fixed << setprecision(10) << total_distance << endl;

    return 0;
}