#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int N;
    cin >> N;

    long double cost = 0.0, ans = 0.0;
    int nowX = 0, nowY = 0;

    for (int i = 0; i < N; ++i) {
        int x, y;
        cin >> x >> y;
        cost = sqrt(powl((long double)(x - nowX), 2) + powl((long double)(y - nowY), 2));
        nowX = x;
        nowY = y;
        ans += cost;
    }

    // Add the cost of returning to the origin
    cost = sqrt(powl((long double)(nowX - 0), 2) + powl((long double)(nowY - 0), 2));
    ans += cost;

    cout.precision(10);
    cout.setf(ios::fixed, ios::floatfield);
    cout << ans << endl;

    return 0;
}