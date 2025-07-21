#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    int n;
    double c = 0;
    cin >> n;
    pair<int, int> prev = {0, 0}; // Starting at the origin
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        c += sqrt(pow(prev.first - x, 2) + pow(prev.second - y, 2)); // Calculate distance to next point
        prev = {x, y}; // Update current position
    }
    c += sqrt(pow(prev.first, 2) + pow(prev.second, 2)); // Return to origin
    cout << setprecision(10) << c << endl;
    return 0;
}