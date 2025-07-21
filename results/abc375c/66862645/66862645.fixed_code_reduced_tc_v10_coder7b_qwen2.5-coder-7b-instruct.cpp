#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long double cost = 0;
    long double ans = 0;
    int n;
    int x, y;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x >> y;

        if (i == 0) {
            ans += sqrt(x * x + y * y); // Distance from origin
        } else {
            ans += sqrt(pow(x, 2) + pow(y, 2)); // Distance from previous point
        }

        cost = sqrt(pow(x, 2) + pow(y, 2));
    }

    ans += cost; // Return to origin

    cout << fixed << setprecision(10) << ans << endl;

    return 0;
}