#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N;

    long double ans = 0.0;
    long double currentX = 0, currentY = 0;

    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        long double distance = sqrt(pow(x - currentX, 2) + pow(y - currentY, 2));
        ans += distance;
        currentX = x;
        currentY = y;
    }

    // Calculate the distance back to the origin
    long double finalDistance = sqrt(pow(currentX, 2) + pow(currentY, 2));
    ans += finalDistance;

    cout.precision(10); // Set precision for output
    cout << fixed << ans << endl;

    return 0;
}