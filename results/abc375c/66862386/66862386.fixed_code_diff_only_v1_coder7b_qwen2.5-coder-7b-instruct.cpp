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

        // Calculate the Euclidean distance squared to avoid computing square roots multiple times
        cost = powl(x - prev_x, 2.0) + powl(y - prev_y, 2.0);

        // Accumulate the distance traveled
        ans += sqrtl(cost);

        // Update previous position
        prev_x = x;
        prev_y = y;
    }

    // Return to origin
    cost = powl(prev_x, 2.0) + powl(prev_y, 2.0);
    ans += sqrtl(cost);

    cout << ans << endl;

    return 0;
}