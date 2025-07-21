#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    double x = 0, y = 0, total_distance = 0;
    for (int i = 0; i < n; i++) {
        int x2, y2;
        cin >> x2 >> y2;
        total_distance += sqrt((x - x2) * (x - x2) + (y - y2) * (y - y2));
        x = x2;
        y = y2;
    }
    total_distance += sqrt(x * x + y * y); // Return to the origin

    cout << fixed << setprecision(10) << total_distance << endl;
    return 0;
}