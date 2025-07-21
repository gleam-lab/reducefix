#include <bits/stdc++.h>
using namespace std;

int main() {

    long double cost = 0;
    long double ans = 0;
    int operation;
    int nowX = 0, nowY = 0;
    int nextX, nextY;

    cin >> operation;

    // Loop through each point
    for(int i = 0; i < operation; i++) {
        cin >> nextX >> nextY;

        // Calculate the Euclidean distance from current position to the next point
        cost = sqrt(pow(nextX - nowX, 2.0) + pow(nextY - nowY, 2.0));

        // Update current position
        nowX = nextX;
        nowY = nextY;

        // Add the cost to the total answer
        ans += cost;
    }

    // Calculate the distance back to the origin from the last point
    cost = sqrt(pow(nowX - 0, 2.0) + pow(nowY - 0, 2.0));
    ans += cost;

    // Print the final total cost
    cout << ans << endl;

    return 0;
}