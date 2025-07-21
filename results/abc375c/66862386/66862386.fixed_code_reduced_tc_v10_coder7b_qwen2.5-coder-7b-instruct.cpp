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

    for(int i = 0; i < operation; i++){
        cin >> nextX >> nextY;

        // Calculate Euclidean distance squared to avoid precision issues with square root
        cost = (powl((long double)(nowX - nextX), 2.0) + powl((long double)(nowY - nextY), 2.0));

        nowX = nextX;
        nowY = nextY;

        // Add the Euclidean distance to the total cost
        ans += sqrtl(cost);
    }

    // Return to the origin
    cost = (powl((long double)(nowX - 0), 2.0) + powl((long double)(nowY - 0), 2.0));
    ans += sqrtl(cost);

    cout << setprecision(15) << ans << endl;

    return 0;
}