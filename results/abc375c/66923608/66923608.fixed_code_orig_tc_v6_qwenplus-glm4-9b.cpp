#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    int n; cin >> n;
    double ans = 0.0;

    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    // Calculate distances between consecutive points and add to total
    for (int i = 0; i < n; i++) {
        ans += sqrt((x[i] - x[(i + 1) % n]) * (x[i] - x[(i + 1) % n]) +
                    (y[i] - y[(i + 1) % n]) * (y[i] - y[(i + 1) % n]));
    }

    // Calculate the distance from the last point to the origin
    ans += sqrt((x[n - 1] - 0) * (x[n - 1] - 0) + (y[n - 1] - 0) * (y[n - 1] - 0));

    // Print the total distance with precision set to 12 decimal places
    cout << fixed << setprecision(12) << ans << endl;

    return 0;
}