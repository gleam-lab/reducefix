#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    double x = 0, y = 0;
    double total_distance = 0.0;

    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        double distance = sqrt((x - a) * (x - a) + (y - b) * (y - b));
        total_distance += distance;
        x = a;
        y = b;
    }

    // Subtract the distance from the last point back to the origin
    total_distance -= sqrt((x - 0) * (x - 0) + (y - 0) * (y - 0));

    cout << fixed << setprecision(20) << total_distance << endl;
    return 0;
}