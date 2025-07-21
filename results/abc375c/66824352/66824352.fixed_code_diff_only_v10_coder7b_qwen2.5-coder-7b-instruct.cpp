#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long x = 0, y = 0; // Use long long to avoid overflow
    double c = 0;
    pair<long long, long long> a[n]; // Store coordinates as long long
    
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    for (int i = 0; i < n; i++) {
        c += sqrt(((x - a[i].first) * (x - a[i].first)) + ((y - a[i].second) * (y - a[i].second)));
        x = a[i].first;
        y = a[i].second;
    }

    c += sqrt((x * x) + (y * y)); // Return trip to origin

    cout << fixed << setprecision(10) << c << endl; // Print result with high precision

    return 0;
}