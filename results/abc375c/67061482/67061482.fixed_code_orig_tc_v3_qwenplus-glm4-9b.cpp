#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N;
    double x = 0, y = 0, totalDistance = 0;

    for (int i = 0; i < N; ++i) {
        int cx, cy;
        cin >> cx >> cy;
        totalDistance += sqrt((x - cx) * (x - cx) + (y - cy) * (y - cy));
        x = cx;
        y = cy;
    }

    totalDistance += sqrt(x * x + y * y); // Add the distance from the last point to origin

    cout << fixed << setprecision(10) << totalDistance << endl;

    return 0;
}