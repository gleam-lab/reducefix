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

        // Calculate the distance from the current position to the next point
        cost = sqrtl((nowX - nextX) * (nowX - nextX) + (nowY - nextY) * (nowY - nextY));

        // Add the cost of moving to the next point to the total cost
        ans += cost;

        // Update the current position to the next point
        nowX = nextX;
        nowY = nextY;
    }

    // Return to the origin from the last visited point
    ans += sqrtl(nowX * nowX + nowY * nowY);

    cout << ans << endl;

    return 0;
}