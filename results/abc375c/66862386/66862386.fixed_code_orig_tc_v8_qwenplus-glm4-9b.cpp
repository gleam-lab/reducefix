#include <bits/stdc++.h>
using namespace std;

int main() {
    long long cost = 0;
    long long ans = 0;
    int nowX = 0, nowY = 0;
    int nextX, nextY;

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> nextX >> nextY;

        cost = (long long)(nextX - nowX) * (nextX - nowX) + (long long)(nextY - nowY) * (nextY - nowY);

        nowX = nextX;
        nowY = nextY;

        ans += sqrt(cost);
    }

    // Return to origin and calculate the distance
    ans += sqrt((long long)nowX * (long long)nowX + (long long)nowY * (long long)nowY);

    cout << ans << endl;

    return 0;
}