#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N;
    long double cost = 0.0;
    long double ans = 0.0;
    int nowX = 0, nowY = 0;

    for(int i = 0; i < N; i++) {
        int nextX, nextY;
        cin >> nextX >> nextY;
        cost = sqrt((long double)(nextX - nowX) * (nextX - nowX) + (long double)(nextY - nowY) * (nextY - nowY));
        ans += cost;
        nowX = nextX;
        nowY = nextY;
    }
    cout << ans << endl;
    return 0;
}