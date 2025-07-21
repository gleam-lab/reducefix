#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long double cost = 0;
    long double ans = 0;
    int operation;
    int nowX = 0 , nowY = 0;
    int nextX, nextY;

    cin >> operation;

    for(int i = 0; i < operation; i++) {
        cin >> nextX >> nextY;

        // Calculate Euclidean distance between current and next point
        cost = sqrt(pow(nextX - nowX, 2.0) + pow(nextY - nowY, 2.0));

        nowX = nextX;
        nowY = nextY;

        ans += cost;
    }

    // Return trip from last point to origin
    cost = sqrt(pow(nowX, 2.0) + pow(nowY, 2.0));
    ans += cost;

    cout << fixed << setprecision(15) << ans << endl;

    return 0;
}