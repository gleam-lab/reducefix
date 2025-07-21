#include <iostream>
#include <cmath> // Include cmath for sqrt

using namespace std;

int main() {
    int N;
    cin >> N;

    int nowX = 0, nowY = 0;
    long double ans = 0;

    for (int i = 0; i < N; ++i) {
        int nextX, nextY;
        cin >> nextX >> nextY;

        // Use sqrt directly and calculate the cost
        ans += sqrt(pow(nextX - nowX, 2) + pow(nextY - nowY, 2));
        nowX = nextX;
        nowY = nextY;
    }

    // Add the cost of returning to the origin
    ans += sqrt(pow(nowX, 2) + pow(nowY, 2));

    cout << ans << endl;

    return 0;
}