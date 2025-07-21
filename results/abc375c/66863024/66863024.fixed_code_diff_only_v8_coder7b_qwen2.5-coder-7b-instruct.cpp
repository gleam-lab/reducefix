#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long double cost = 0;
    long double ans = 0;
    int n;
    long double nowX = 0 , nowY = 0;
    long double nextX, nextY;

    cin >> n;

    for(int i = 0;  i < n; i++) {
        cin >> nextX >> nextY;

        // Calculate distance from current position to the next point
        long double dx = nextX - nowX;
        long double dy = nextY - nowY;

        // Add the distance to the total cost
        ans += sqrtl(dx * dx + dy * dy);

        // Update the current position to the next point
        nowX = nextX;
        nowY = nextY;
    }

    // Return to the origin
    ans += sqrtl(nowX * nowX + nowY * nowY);

    cout << fixed << setprecision(10) << ans << endl;

    return 0;
}