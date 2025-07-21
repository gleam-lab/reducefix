#include <bits/stdc++.h>
using namespace std;

int main(){
    long double cost = 0;
    long double ans = 0;
    int N;
    int nowX = 0, nowY = 0;
    int nextX, nextY;

    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> nextX >> nextY;

        cost = sqrt(pow(nextX - nowX, 2.0) + pow(nextY - nowY, 2.0));

        ans += cost;

        nowX = nextX;
        nowY = nextY;
    }

    cost = sqrt(pow(nowX, 2.0) + pow(nowY, 2.0));
    ans += cost;

    cout << fixed << setprecision(10) << ans << endl;

    return 0;
}