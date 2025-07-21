#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N;
    double x = 0, y = 0;
    double total_distance = 0;

    for (int i = 0; i < N; i++) {
        double c, d;
        cin >> c >> d;
        total_distance += sqrt((c - x) * (c - x) + (d - y) * (d - y));
        x = c;
        y = d;
    }

    total_distance += sqrt(x * x + y * y);  // Add the distance back to the origin
    cout.precision(10);
    cout << fixed << total_distance << endl;
    return 0;
}