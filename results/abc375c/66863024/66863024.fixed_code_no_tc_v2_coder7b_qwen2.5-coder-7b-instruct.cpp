#include <bits/stdc++.h>
using namespace std;

int main(){
    long double cost = 0;
    long double ans = 0;
    int N;
    long double nowX = 0 , nowY = 0;
    long double nextX, nextY;

    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> nextX >> nextY;

        // Calculate the distance from current position to the next point
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

    cout << ans << endl;

    return 0;
}