#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N;

    long double cost = 0;
    long double ans = 0;
    int nowX = 0, nowY = 0;

    for (int i = 0; i < N; i++) {
        int nextX, nextY;
        cin >> nextX >> nextY;

        cost = sqrt(pow(nextX - nowX, 2) + pow(nextY - nowY, 2));

        nowX = nextX;
        nowY = nextY;

        ans += cost;
    }

    // Compute the cost from the last point to the origin
    cost = sqrt(pow(nowX, 2) + pow(nowY, 2));

    ans += cost;

    cout << fixed << setprecision(10) << ans << endl;

    return 0;
}