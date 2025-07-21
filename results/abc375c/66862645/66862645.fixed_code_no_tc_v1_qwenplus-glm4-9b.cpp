#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N;

    long double ans = 0.0;
    long double x = 0.0, y = 0.0;

    for (int i = 0; i < N; ++i) {
        int X, Y;
        cin >> X >> Y;

        ans += sqrt((x - X) * (x - X) + (y - Y) * (y - Y));
        x = X;
        y = Y;
    }

    // Calculate the cost of the last leg back to the origin
    ans += sqrt((x - 0.0) * (x - 0.0) + (y - 0.0) * (y - 0.0));

    cout << fixed << setprecision(12) << ans << endl;

    return 0;
}