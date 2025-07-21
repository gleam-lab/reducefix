#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long double cost = 0.0;
    long double ans = 0.0;
    int X, Y;

    cin >> X;  // Read the number of points
    for(int i = 0; i < X; i++) {
        cin >> Y;  // Read the coordinates
        cost = sqrt(powl((i == 0 ? 0 : i - 1), 2) + Square(Y));
        ans += cost;
    }

    cout << fixed << setprecision(20) << ans << endl;  // Print the total cost

    return 0;
}

double Square(int x) {
    return x * x;
}