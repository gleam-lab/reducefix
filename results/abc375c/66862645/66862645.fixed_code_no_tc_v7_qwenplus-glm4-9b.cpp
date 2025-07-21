#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long cost = 0; // Use long long to prevent overflow
    long long ans = 0;
    long long nowX = 0, nowY = 0;
    int N;

    cin >> N;

    for (int i = 0; i < N; i++) {
        long long nextX, nextY;
        cin >> nextX >> nextY;

        // Calculate cost using the Euclidean distance formula
        cost = (nextX - nowX) * (nextX - nowX) + (nextY - nowY) * (nextY - nowY);
        ans += sqrt(cost); // Add the square root of cost to the total cost

        // Update current position
        nowX = nextX;
        nowY = nextY;
    }

    // Add the cost of returning to the origin
    cost = (nowX - 0) * (nowX - 0) + (nowY - 0) * (nowY - 0);
    ans += sqrt(cost);

    cout.precision(10);
    cout << fixed << ans << endl;

    return 0;
}