#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N;
    double x = 0, y = 0;
    double total_distance = 0.0;

    for (int i = 0; i < N; ++i) {
        int x2, y2;
        cin >> x2 >> y2;
        total_distance += sqrt((x - x2) * (x - x2) + (y - y2) * (y - y2));
        x = x2;
        y = y2;
    }

    // Add the distance from the last point to the origin
    total_distance += sqrt((x - 0) * (x - 0) + (y - 0) * (y - 0));

    cout << fixed << setprecision(10) << total_distance << endl;
    return 0;
}