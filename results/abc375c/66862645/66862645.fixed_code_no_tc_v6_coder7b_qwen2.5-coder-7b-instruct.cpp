#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long double cost = 0;
    long double ans = 0;
    int n;
    int x, y;
    int prev_x = 0, prev_y = 0;

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> x >> y;
        cost = sqrt(pow(prev_x - x, 2) + pow(prev_y - y, 2));
        ans += cost;
        prev_x = x;
        prev_y = y;
    }

    cost = sqrt(pow(prev_x, 2) + pow(prev_y, 2));
    ans += cost;

    cout << fixed << setprecision(10) << ans << endl;

    return 0;
}