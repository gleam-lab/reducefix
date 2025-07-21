#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    int n;
    double c = 0;
    cin >> n;
    pair<int, int> a[n];

    // Read all points
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    // Calculate the total cost
    for (int i = 0; i < n - 1; i++) {
        c += sqrt(pow(a[i].first - a[i + 1].first, 2) + pow(a[i].second - a[i + 1].second, 2));
    }

    // Add the cost of returning to the origin
    c += sqrt(pow(a[n - 1].first, 2) + pow(a[n - 1].second, 2));

    // Output the result with high precision
    cout << setprecision(10) << c << endl;

    return 0;
}