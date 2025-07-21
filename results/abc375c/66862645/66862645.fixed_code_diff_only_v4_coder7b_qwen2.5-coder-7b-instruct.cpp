#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    long double ans = 0;
    int prevX = 0, prevY = 0;
    int currX, currY;

    for (int i = 0; i < N; ++i) {
        cin >> currX >> currY;
        ans += sqrtl(powl(prevX - currX, 2.0) + powl(prevY - currY, 2.0));
        prevX = currX;
        prevY = currY;
    }

    ans += sqrtl(powl(prevX - 0, 2.0) + powl(prevY - 0, 2.0));

    cout << fixed << setprecision(10) << ans << endl;

    return 0;
}