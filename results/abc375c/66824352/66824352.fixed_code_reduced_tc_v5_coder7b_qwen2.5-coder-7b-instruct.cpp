#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long x = 0, y = 0;
    double totalCost = 0;

    // Calculate the total distance to visit all points and return to origin
    for(int i = 0; i < n; ++i) {
        long long newX, newY;
        cin >> newX >> newY;
        totalCost += sqrt((newX - x) * (newX - x) + (newY - y) * (newY - y));
        x = newX;
        y = newY;
    }

    // Add the distance back to the origin
    totalCost += sqrt(x * x + y * y);

    // Output with high precision
    cout << setprecision(10) << fixed << totalCost << endl;

    return 0;
}